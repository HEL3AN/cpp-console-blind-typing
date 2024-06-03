#pragma once
#include <curses.h>
#include <string>
#include "globals.cpp"

namespace Game_Window {
    std::string correct_text = "give me this fancy boolochka";
    std::string user_text;

    void Control() {
        switch (CURRENT_KEY)
        {
            case KEY_EXIT:
                ChangeWindow(WINDOWS::Menu);
                break;     
            case KEY_ENTER:
                break; 
            case KEY_BACKSPACE:
                if (user_text.size()) {
                    user_text.pop_back();         
                }          
                break;
            default:
                user_text += static_cast<char>(CURRENT_KEY);
                break;
        }
    }

    void Print() {
        mvwprintw(MAIN_WINDOW, START_Y + 1, START_X + 1, "%s", correct_text.c_str());
        mvwprintw(MAIN_WINDOW, START_Y + 2, START_X + 1, "%s", user_text.c_str());
        wclrtoeol(MAIN_WINDOW);
    }
}