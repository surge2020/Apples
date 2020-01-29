#include "eventHandler.h"

EventHandler::EventHandler(Menu* menu, bool* running, gameState* state)
{
    this->menu = menu;
    this->running = running;
    this->state = state;
}

void EventHandler::input()
{
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            *running = false;
            break;
        case SDL_MOUSEMOTION:
            mouseMotion(&event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            buttonDown(&event);
        default:
            break;
        }
    }
}

void EventHandler::mouseMotion(SDL_Event* event)
{
    if (menu->getDisplay()) {
        menu->select(event->motion.x, event->motion.y);
    } 
}

void EventHandler::buttonDown(SDL_Event* event)
{
    if (*state == mainMenu) {
        if (menu->getDisplay()) {
            if (menu->selection == Menu::exit) {
                *running = false;
            }
            else if (menu->selection == Menu::play) {
                *state = playing;
            }
        }
    }
     
}