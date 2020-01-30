#include "player.h"

Player::Player(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    surface = IMG_Load("res/heart.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    heartRect = {110, 525, 50, 50};
    health = 3;
}

void Player::render()
{
    for (int i = 0; i < health; ++i) {
        SDL_RenderCopy(renderer, texture, NULL, &heartRect);
        heartRect.x += 60;
    }
    heartRect.x = 110;
}