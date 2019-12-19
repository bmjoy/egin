#include "Input.hpp"
#include "SDL.h"
#include <cstring>
#include "core/Window.hpp"

using namespace core;

Input core::input;

Input::Input() :
  mouseSpeed({ 0, 0 }),
  lockMouse(false)
{
  this->keyState = SDL_GetKeyboardState(&this->numKeys);  
  SDL_GetMouseState(&this->mousePos.x, &this->mousePos.y);
}

void Input::update() {
  int posX, posY;
  SDL_GetMouseState(&posX, &posY);
  
  this->mouseSpeed.x = posX - this->mousePos.x;
  this->mouseSpeed.y = posY - this->mousePos.y;

  if (this->lockMouse) {
		SDL_WarpMouseInWindow(
      core::window.getWindow(),
      core::window.getWidth() / 2,
      core::window.getHeight() / 2
    );

    this->mousePos.x = core::window.getWidth() / 2;
    this->mousePos.y = core::window.getHeight() / 2;
  } else {
    this->mousePos.x = posX;
    this->mousePos.y = posY;
  }
}

bool Input::isKeyPressed(int keyCode) {
  return this->keyState[keyCode];
}

bool Input::isKeyDown(int keyCode) {
  if (Input::isKeyPressed(keyCode)) {
    return !this->keyOldState[keyCode];
  }

  return false;
}

bool Input::isKeyUp(int keyCode) {
  if (!Input::isKeyPressed(keyCode)) {
    return this->keyOldState[keyCode];
  }

  return false;
}

mouse_point Input::getMousePos() {
  return this->mousePos;
}

mouse_point Input::getMouseSpeed() {
  return this->mouseSpeed;
}

void Input::setMouseLock(bool lock) {
  this->lockMouse = lock;
}

bool Input::getMouseLock() {
  return this->lockMouse;
}