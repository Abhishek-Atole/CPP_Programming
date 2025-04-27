#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Enemy {
public:
    Enemy(const string& enemyName, int hp, int atk, int rewardXp)
        : name(enemyName), health(hp), attackPower(atk), experienceReward(rewardXp) {}

    void attack() const {
        cout << name << " attacks!" << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getAttackPower() const {
        return attackPower;
    }

    int getExperienceReward() const {
        return experienceReward;
    }

    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

private:
    string name;
    int health;
    int attackPower;
    int experienceReward;
};

class Player {
public:
    Player(const string& playerName)
        : name(playerName), health(100), attackPower(20), level(1), experience(0), experienceToNextLevel(100), specialCooldown(0) {}

    void basicAttack(Enemy& enemy) {
        bool isCritical = (rand() % 100) < 20;
        int damage = isCritical ? attackPower * 2 : attackPower;
        cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!";
        if (isCritical) cout << " (Critical Hit!)";
        cout << endl;
        enemy.takeDamage(damage);
    }

    void specialAttack(Enemy& enemy) {
        if (specialCooldown == 0) {
            int damage = attackPower * 3;
            cout << name << " uses Special Attack on " << enemy.getName() << " for " << damage << " damage!" << endl;
            enemy.takeDamage(damage);
            specialCooldown = 3;
        } else {
            cout << "Special Attack is on cooldown (" << specialCooldown << " turns remaining)." << endl;
        }
    }

    void takeDamage(int damage) {
        bool dodged = (rand() % 100) < 25;
        if (dodged) {
            cout << name << " dodged the attack!" << endl;
        } else {
            health -= damage;
            if (health < 0) health = 0;
            cout << name << " takes " << damage << " damage! [HP: " << health << "]" << endl;
        }
    }

    void endTurn() {
        if (specialCooldown > 0) specialCooldown--;
    }

    bool isAlive() const {
        return health > 0;
    }

    void gainExperience(int xp) {
        experience += xp;
        cout << name << " gained " << xp << " XP!" << endl;
        checkLevelUp();
    }

    void checkLevelUp() {
        while (experience >= experienceToNextLevel) {
            experience -= experienceToNextLevel;
            level++;
            attackPower += 5;
            health += 20;
            cout << "*** " << name << " leveled up! Now Level " << level 
                 << " [HP: " << health << ", ATK: " << attackPower << "] ***" << endl;
            experienceToNextLevel += 50;
        }
    }

    void showStatus() const {
        cout << name << " [Level " << level 
             << ", HP: " << health 
             << ", ATK: " << attackPower 
             << ", XP: " << experience << "/" << experienceToNextLevel << "]" << endl;
    }

    string getName() const {
        return name;
    }

private:
    string name;
    int health;
    int attackPower;
    int level;
    int experience;
    int experienceToNextLevel;
    int specialCooldown;
};

void displayMenu() {
    cout << "\n========== Battle Arena Multiplayer ==========" << endl;
    cout << "1. Spawn a Dragon (HP 60, ATK 15, XP 50)" << endl;
    cout << "2. Spawn a Goblin (HP 40, ATK 10, XP 30)" << endl;
    cout << "3. Spawn a Troll (HP 80, ATK 20, XP 70)" << endl;
    cout << "4. Attack an Enemy (Basic Attack)" << endl;
    cout << "5. Special Attack an Enemy" << endl;
    cout << "6. Show Status" << endl;
    cout << "7. Exit Game" << endl;
    cout << "Enter your choice: ";
}

void showEnemies(const vector<unique_ptr<Enemy>>& enemies) {
    if (enemies.empty()) {
        cout << "No enemies on the battlefield." << endl;
        return;
    }
    for (size_t i = 0; i < enemies.size(); ++i) {
        cout << i+1 << ". " << enemies[i]->getName() << " [HP: " << enemies[i]->getHealth() << "]" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numPlayers;
    cout << "Enter number of players: ";
    cin >> numPlayers;
    cin.ignore();

    vector<unique_ptr<Player>> players;

    for (int i = 0; i < numPlayers; ++i) {
        string name;
        cout << "Enter Player " << i+1 << " Name: ";
        getline(cin, name);
        players.push_back(make_unique<Player>(name));
    }

    vector<unique_ptr<Enemy>> enemies;
    int choice;

    do {
        for (auto& player : players) {
            if (!player->isAlive()) continue;

            displayMenu();
            cout << "\n" << player->getName() << "'s Turn:\n";
            cin >> choice;

            switch (choice) {
            case 1:
                enemies.push_back(make_unique<Enemy>("Dragon", 60, 15, 50));
                break;
            case 2:
                enemies.push_back(make_unique<Enemy>("Goblin", 40, 10, 30));
                break;
            case 3:
                enemies.push_back(make_unique<Enemy>("Troll", 80, 20, 70));
                break;
            case 4:
            case 5:
                if (enemies.empty()) {
                    cout << "No enemies to attack!" << endl;
                    break;
                }
                showEnemies(enemies);
                cout << "Choose an enemy to attack: ";
                int targetIndex;
                cin >> targetIndex;
                if (targetIndex >= 1 && targetIndex <= enemies.size()) {
                    Enemy& target = *enemies[targetIndex - 1];

                    if (choice == 4)
                        player->basicAttack(target);
                    else
                        player->specialAttack(target);

                    if (!target.isAlive()) {
                        cout << target.getName() << " has been defeated!" << endl;
                        player->gainExperience(target.getExperienceReward());
                        enemies.erase(enemies.begin() + (targetIndex - 1));
                    }

                    for (auto& enemy : enemies) {
                        if (rand() % 2 == 0) {
                            enemy->attack();
                            player->takeDamage(enemy->getAttackPower());
                        }
                    }

                    player->endTurn();

                    if (!player->isAlive()) {
                        cout << player->getName() << " has fallen!" << endl;
                    }
                } else {
                    cout << "Invalid target selection." << endl;
                }
                break;
            case 6:
                player->showStatus();
                showEnemies(enemies);
                break;
            case 7:
                cout << "\nExiting game...\n";
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
            }
        }
    } while (true);

    return 0;
}
