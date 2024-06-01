#ifndef GLOBALS_H
#define GLOBALS_H

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int START_X;
extern const int START_Y;

extern int CURRENT_KEY;
extern int CURRENT_WINDOW;

enum WINDOWS {
    Menu,
    Setting,
    Game
};

void PrintWindow();
void ChangeWindow(WINDOWS window_type);

#endif