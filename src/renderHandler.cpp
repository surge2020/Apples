#include "renderHandler.h"

RenderHandler::RenderHandler(SDL_Renderer* renderer, Menu* menu, gameState* state)
{
    this->renderer = renderer;
    this->menu = menu;
    this->state = state;
}

void RenderHandler::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (*state == mainMenu) {
        menu->render();
    }
    SDL_RenderPresent(renderer);
}