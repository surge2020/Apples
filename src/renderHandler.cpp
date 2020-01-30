#include "renderHandler.h"

RenderHandler::RenderHandler(
    SDL_Renderer* renderer, Menu* menu,
    gameState* state, Panel* panel, Player* player)
{
    this->renderer = renderer;
    this->menu = menu;
    this->panel = panel;
    this->state = state;
    background = new Background(renderer);
    this->player = player;
}

void RenderHandler::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (*state == mainMenu) {
        menu->render();
    }
    else if(*state == playing) {
        background->render();
        panel->render();
        player->render();
    }
    SDL_RenderPresent(renderer);
}