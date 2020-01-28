#include "menu.h"

Menu::Menu(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    display = true;
    status = menu;
    playRect = {250, 250, 300, 100};
    exitRect = {250, 375, 300, 100};
}

void Menu::setDisplay(bool b)
{
    display = b;
}

bool Menu::getDisplay()
{
    return display;
}

void Menu::setStatus(int x, int y)
{
    cursorRect = {x, y, 20, 20};
    if (SDL_HasIntersection(&cursorRect, &playRect)) {
        status = play;
    }
    else if (SDL_HasIntersection(&cursorRect, &exitRect)) {
        status = exit;
    }
    else {
        status = menu;
    }
}

void Menu::render()
{
    if (status == menu) {
        surface = IMG_Load("res/menu.png");  
    }
    else if (status == play) {
        surface = IMG_Load("res/menuPlay.png");
    }
    else if (status == exit) {
        surface = IMG_Load("res/menuExit.png");
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}