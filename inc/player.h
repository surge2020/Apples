#ifndef PLAYER
#define PLAYER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player {
public:
    Player(SDL_Renderer* renderer);
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect heartRect;
    int health;
};

#endif