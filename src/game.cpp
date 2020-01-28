#include "game.h"

Game::Game()
{
    window = SDL_CreateWindow(
        "Apples",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    running = true;
}

bool Game::getRunning()
{
    return running;
}

void Game::input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
        }
    }
}

void Game::logic()
{

}

void Game::update()
{

}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}