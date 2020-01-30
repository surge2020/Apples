#include "panel.h"

Panel::Panel(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    panelRect = {0, 500, 800, 100};
    exitRect = {650, 525, 125, 50};
    selection = none;
}

void Panel::select(int x, int y)
{
    SDL_Rect cursorRect = {x, y, 20, 20};
    if (SDL_HasIntersection(&cursorRect, &exitRect)) {
        selection = exit;
    }
    else {
        selection = none;
    }
}

void Panel::render()
{
    if (selection == none) {
        surface = IMG_Load("res/panel.png");
    }
    else if (selection == exit) {
        surface = IMG_Load("res/panelExit.png");
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &panelRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}