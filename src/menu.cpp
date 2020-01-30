#include "menu.h"

Menu::Menu(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    selection = none;
    playRect = {250, 250, 300, 100};
    exitRect = {250, 375, 300, 100};
}

void Menu::select(int x, int y)
{
    cursorRect = {x, y, 20, 20};
    if (SDL_HasIntersection(&cursorRect, &playRect)) {
        selection = play;
    }
    else if (SDL_HasIntersection(&cursorRect, &exitRect)) {
        selection = exit;
    }
    else {
        selection = none;
    }
}

void Menu::render()
{
    if (selection == none) {
        surface = IMG_Load("res/menu.png");  
    }
    else if (selection == play) {
        surface = IMG_Load("res/menuPlay.png");
    }
    else if (selection == exit) {
        surface = IMG_Load("res/menuExit.png");
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}