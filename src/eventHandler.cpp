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
            keyDown(&event);          
        default:
            break;
        }
    }
}

void EventHandler::mouseMotion(SDL_Event* event)
{
    if (menu->getDisplay()) {
        menu->setItem(event->motion.x, event->motion.y);
    } 
}

void EventHandler::keyDown(SDL_Event* event)
{
    if (menu->getDisplay()) {
        if (menu->getItem() == 'e') {
             *running = false;
        }
    } 
}