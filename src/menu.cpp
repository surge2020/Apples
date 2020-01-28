#include "menu.h"

Menu::Menu(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    display = true;
    itemSelect = 'n';
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

void Menu::setItem(int x, int y)
{
    cursorRect = {x, y, 20, 20};
    if (SDL_HasIntersection(&cursorRect, &playRect)) {
        itemSelect = 'p';
    }
    else if (SDL_HasIntersection(&cursorRect, &exitRect)) {
        itemSelect = 'e';
    }
    else {
        itemSelect = 'n';
    }
}
char Menu::getItem()
{
    return itemSelect;
}

void Menu::render()
{
    if (itemSelect == 'n') {
        surface = IMG_Load("res/menu.png");  
    }
    else if (itemSelect == 'p') {
        surface = IMG_Load("res/menuPlay.png");
    }
    else if (itemSelect == 'e') {
        surface = IMG_Load("res/menuExit.png");
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}