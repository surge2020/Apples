#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include <SDL2/SDL.h>
#include "menu.h"

class EventHandler {
public:
    EventHandler(Menu* menu, bool* running);
    void input();
    void mouseMotion(SDL_Event* event);
    void keyDown(SDL_Event* event);
private:
    Menu* menu;
    bool* running;
    SDL_Event event;
};

#endif