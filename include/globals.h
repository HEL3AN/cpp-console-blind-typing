#ifndef GLOBALS_H
#define GLOBALS_H
#include <vector>
#include <string>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int START_X;
extern const int START_Y;

extern WINDOW *MAIN_WINDOW;
void InitMainWin();

extern int CURRENT_KEY;
extern int CURRENT_WINDOW;
extern bool SHOULD_CLOSE;

enum WINDOWS {
    Menu,
    Setting,
    Game
};

void PrintWindow();
void ControlWindow();
void ChangeWindow(WINDOWS window_type);

void ProcessInput();

std::vector<std::string> SplitIntoWords(const std::string& text);

#endif