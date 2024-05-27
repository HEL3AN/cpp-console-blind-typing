#include <curses.h>
#include "menu.cpp"

#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 10
#define START_X 0
#define START_Y 0

int main() {
    initscr();
    clear();
    noecho();
    cbreak();

    WINDOW *window = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, START_X, START_Y);
    keypad(window, TRUE);
    refresh();
    Menu::PrintMenu(window);

    getch();
    endwin();
    return 0;
}