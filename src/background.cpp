#include "background.h"

Background::Background(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    backgroundRect = {0, 0, 800, 500};
    surface = IMG_Load("res/background.png");
}

void Background::render()
{
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &backgroundRect);
    SDL_DestroyTexture(texture);
}