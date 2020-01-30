#ifndef RENDER_HANDLER
#define RENDER_HANDLER

#include <SDL2/SDL.h>
#include "menu.h"
#include "gameState.h"
#include "background.h"
#include "panel.h"
#include "player.h"

class RenderHandler {
public:
    RenderHandler(
        SDL_Renderer* renderer, Menu* menu, 
        gameState* state, Panel* panel, Player* player);
    void render();
private:
    SDL_Renderer* renderer;
    Menu* menu;
    Panel* panel;
    gameState* state;
    Background* background;
    Player* player;
};

#endif