#include "Input.hpp"
#include "Keyboard.h"
#include "../core/Logger.h"
#include <cstring>

using namespace gplay;
using namespace engine;

Input engine::input;

Input::Input() {
  this->keyState = SDL_GetKeyboardState(&this->numKeys);
}

void Input::update() {
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