#ifndef MENU
#define MENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    enum menuSelection {none, play, exit} selection;
    void setDisplay(bool b);
    bool getDisplay();
    void select(int x, int y); 
    void render();
private:
    SDL_Renderer* renderer;
    bool display;
    SDL_Rect playRect;
    SDL_Rect exitRect;
    SDL_Rect cursorRect;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

#endif