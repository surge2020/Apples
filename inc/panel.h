#ifndef PANEL
#define PANEL

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Panel {
public:
    Panel(SDL_Renderer* renderer);
    enum panelSelection {none, exit} selection;
    void select(int x, int y);
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Rect panelRect;
    SDL_Rect exitRect;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

#endif