#ifndef BACKGROUND
#define BACKGROUND

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Background {
public:
    Background(SDL_Renderer* renderer);
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Rect backgroundRect;
    SDL_Texture* texture;
    SDL_Surface* surface;
};

#endif