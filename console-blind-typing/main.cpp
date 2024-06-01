#include <curses.h>
#include <windows.h>
#include "globals.cpp"
#include "menu.cpp"

void ResizeConsoleWindow() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsole, {WINDOW_WIDTH, WINDOW_HEIGHT});
    SMALL_RECT sr;
    sr.Left = 0;
    sr.Top = 0;
    sr.Right = WINDOW_WIDTH - 1;
    sr.Bottom = WINDOW_HEIGHT - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &sr);
}

int main() {
    ResizeConsoleWindow();
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW *window = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, START_Y, START_X); 
    keypad(window, TRUE);
    refresh();

    do {
        PrintWindow(window);
    } while ((CURRENT_KEY = getch()) != 27);

    getch();
    endwin();
    return 0;
}