#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include <SDL2/SDL.h>
#include "menu.h"
#include "gameState.h"
#include "panel.h"

class EventHandler {
public:
    EventHandler(Menu* menu, bool* running, gameState* state, Panel* panel);
    void input();
    void mouseMotion(SDL_Event* event);
    void buttonDown(SDL_Event* event);
private:
    Menu* menu;
    bool* running;
    SDL_Event event;
    gameState* state;
    Panel* panel;
};

#endif