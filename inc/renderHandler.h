#ifndef RENDER_HANDLER
#define RENDER_HANDLER

#include <SDL2/SDL.h>
#include "menu.h"
#include "gameState.h"

class RenderHandler {
public:
    RenderHandler(SDL_Renderer* renderer, Menu* menu, gameState* state);
    void render();
private:
    SDL_Renderer* renderer;
    Menu* menu;
    gameState* state;
};

#endif