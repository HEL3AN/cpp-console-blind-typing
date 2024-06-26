#pragma once
#include <curses.h>
#include "globals.h"
#include "menu.cpp"
#include "game.cpp"

const int WINDOW_WIDTH = 128;
const int WINDOW_HEIGHT = 36;
const int START_X = 0;
const int START_Y = 0;

WINDOW *MAIN_WINDOW;
void InitMainWin() {
    MAIN_WINDOW = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, START_Y, START_X);
}

int CURRENT_KEY = 0;
int CURRENT_WINDOW = WINDOWS::Menu;
bool SHOULD_CLOSE = false;

void PrintWindow() {
    wclear(MAIN_WINDOW);
    switch (CURRENT_WINDOW)
    {
        case WINDOWS::Menu:
            Menu_Window::Print();
            break;
        case WINDOWS::Game:
            Game_Window::Print();
            break;
        default:
            break;
    }
    box(MAIN_WINDOW, 0, 0);
    wrefresh(MAIN_WINDOW);
}
void ControlWindow() {
    switch (CURRENT_WINDOW)
    {
        case WINDOWS::Menu:
            Menu_Window::Control();
            break;
        case WINDOWS::Game:
            Game_Window::Control();
            break;
        default:
            break;
    }
}
void ChangeWindow(WINDOWS window_type) {
    CURRENT_WINDOW = window_type;
    if (CURRENT_WINDOW == WINDOWS::Game) {
        Game_Window::Init();
    }
    PrintWindow();
}

void ProcessInput() {
    CURRENT_KEY = getch();
    if (CURRENT_KEY == '\n') { //enter buutom
        CURRENT_KEY = KEY_ENTER;
    }
    if (CURRENT_KEY == 27) { //esc button
        CURRENT_KEY = KEY_EXIT;
    }
    if (CURRENT_KEY == 127 || CURRENT_KEY == '\b') { //backspace button
        CURRENT_KEY = KEY_BACKSPACE;
    }
}

std::vector<std::string> SplitIntoWords(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    for (const char symbol : text) {
        if (symbol == ' ') {
            words.push_back(word);
            word.clear();
        } else {
            word += symbol;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}