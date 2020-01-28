#include "renderHandler.h"

RenderHandler::RenderHandler(SDL_Renderer* renderer, Menu* menu)
{
    this->renderer = renderer;
    this->menu = menu;
}

void RenderHandler::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (menu->getDisplay()) {
        menu->render();
    }
    SDL_RenderPresent(renderer);
}