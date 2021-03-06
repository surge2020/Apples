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
    state = new gameState(mainMenu);
    menu = new Menu(renderer);
    panel = new Panel(renderer);
    player = new Player(renderer);
    eventHandler = new EventHandler(menu, &running, state, panel);
    renderHandler = new RenderHandler(renderer, menu, state, panel, player);
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
    renderHandler->render();
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}