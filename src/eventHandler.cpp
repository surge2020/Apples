#include "eventHandler.h"

EventHandler::EventHandler(Menu* menu, bool* running)
{
    this->menu = menu;
    this->running = running;
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
        menu->setStatus(event->motion.x, event->motion.y);
    } 
}

void EventHandler::buttonDown(SDL_Event* event)
{
    if (menu->getDisplay()) {
        if (menu->status == Menu::exit) {
            *running = false;
        }
        else if (menu->status == Menu::play) {
            menu->setDisplay(false);
        }
    } 
}