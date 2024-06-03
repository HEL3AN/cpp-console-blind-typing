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

    InitMainWin();
    keypad(MAIN_WINDOW, TRUE);
    refresh();

    while (!SHOULD_CLOSE) {    
        PrintWindow();
        ProcessInput();
        ControlWindow();
    }

    endwin();
    return 0;
}