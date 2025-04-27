#include <iostream>
#include <unistd.h> // For sleep() (on Linux/macOS)
#include <termios.h> // For _kbhit() simulation on Linux/macOS
#include <fcntl.h>  // For non-blocking input (Linux/macOS)

// For Windows-specific, include Windows.h and use _kbhit() with Windows console.
#ifdef _WIN32
#include <conio.h>
#endif

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
public:
    int x, y;
    Direction dir;

    Snake(int startX, int startY) : x(startX), y(startY), dir(RIGHT) {}

    void move() {
        switch (dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        }
    }

    void setDirection(Direction newDir) {
        if (newDir == UP && dir != DOWN) dir = UP;
        if (newDir == DOWN && dir != UP) dir = DOWN;
        if (newDir == LEFT && dir != RIGHT) dir = LEFT;
        if (newDir == RIGHT && dir != LEFT) dir = RIGHT;
    }

    void draw() {
        system("clear"); // Use "cls" for Windows instead of "clear" for clearing the console
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (i == y && j == x) {
                    cout << "O"; // Snake head
                } else {
                    cout << "."; // Empty space
                }
            }
            cout << endl;
        }
    }

    bool checkCollision(int width, int height) {
        return (x < 0 || x >= width || y < 0 || y >= height);
    }
};

// Non-blocking key press for cross-platform
bool kbhit() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable buffered input
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // Make input non-blocking
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, 0);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }
    return false;
}

// For Windows, simulate the behavior of _kbhit()
#ifdef _WIN32
bool kbhit() {
    return _kbhit();
}
#endif

int main() {
    Snake snake(10, 10);
    int width = 20, height = 20;

    while (true) {
        snake.draw();

        if (kbhit()) {
            char ch = getchar();
            if (ch == 'w') snake.setDirection(UP);
            if (ch == 's') snake.setDirection(DOWN);
            if (ch == 'a') snake.setDirection(LEFT);
            if (ch == 'd') snake.setDirection(RIGHT);
        }

        snake.move();

        if (snake.checkCollision(width, height)) {
            cout << "Game Over!" << endl;
            break;
        }

        usleep(100000); // Sleep for 100 milliseconds (use Sleep() in Windows)
    }

    return 0;
}
