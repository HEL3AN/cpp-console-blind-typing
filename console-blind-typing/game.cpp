#pragma once
#include <curses.h>
#include <string>
#include "globals.cpp"

namespace Game_Window {
    std::string correct_text = "give me this fancy boolochka";

    void Control() {
        switch (CURRENT_KEY)
        {
            case KEY_EXIT:
                ChangeWindow(WINDOWS::Menu);
                break;      
            default:
                break;
        }
    }

    void Print() {
        mvwprintw(MAIN_WINDOW, START_Y + 1, START_X + 1, "%s", correct_text.c_str());
    }
}