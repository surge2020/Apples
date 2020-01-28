#ifndef MENU
#define MENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    void setDisplay(bool b);
    bool getDisplay();
    void setItem(int x, int y);
    char getItem();
    void render();
private:
    SDL_Renderer* renderer;
    bool display;
    char itemSelect;
    SDL_Rect playRect;
    SDL_Rect exitRect;
    SDL_Rect cursorRect;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

#endif