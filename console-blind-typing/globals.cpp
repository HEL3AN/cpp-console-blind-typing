#ifndef GLOBALS_H
#include "globals.h"
#include "menu.cpp"

const int WINDOW_WIDTH = 128;
const int WINDOW_HEIGHT = 36;
const int START_X = 0;
const int START_Y = 0;

int CURRENT_KEY = 0;
int CURRENT_WINDOW = WINDOWS::Menu;

void PrintWindow(WINDOW *window) {
    wclear(window);
    box(window, 0, 0);
    switch (CURRENT_WINDOW)
    {
    case WINDOWS::Menu:
        Menu_Window::PrintMenu(window);
        break;
    
    default:
        break;
    }
    wrefresh(window);
}

void ChangeWindow(WINDOWS window_type) {
    CURRENT_WINDOW = window_type;
}

#endif