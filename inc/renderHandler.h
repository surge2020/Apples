#ifndef RENDER_HANDLER
#define RENDER_HANDLER

#include <SDL2/SDL.h>
#include "menu.h"

class RenderHandler {
public:
    RenderHandler(SDL_Renderer* renderer, Menu* menu);
    void render();
private:
    SDL_Renderer* renderer;
    Menu* menu;
};

#endif