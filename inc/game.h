#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include "menu.h"
#include "eventHandler.h"

class Game {
public:
    Game();
    bool getRunning();
    void events();
    void logic();
    void update();
    void render();
    void clean();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;  
    Menu* menu;
    EventHandler* eventHandler;
};

#endif