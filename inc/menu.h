#ifndef MENU
#define MENU

#include <SDL2/SDL.h>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
private:
    SDL_Renderer* renderer;
};

#endif