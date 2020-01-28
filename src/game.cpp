#include "game.h"

Game::Game()
{
    window = SDL_CreateWindow(
        "Apples",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    running = true;   
    menu = new Menu(renderer);
    eventHandler = new EventHandler(menu, &running);
}

bool Game::getRunning()
{
    return running;
}

void Game::events()
{
    eventHandler->input();
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
    if (menu->getDisplay()) {
        menu->render();
    }
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}