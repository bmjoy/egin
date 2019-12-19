#include "SDL_Keyboard.h"

namespace core {
  struct mouse_point {
    int x;
    int y;
  };
  

  class Input {
    private:
      int numKeys;
      const uint8_t *keyState;
      const uint8_t *keyOldState;

      mouse_point mousePos;
      mouse_point mouseSpeed;

      bool lockMouse;
    public:
      Input();
      void update();
      bool isKeyPressed(int keyCode);
      bool isKeyDown(int keyCode);
      bool isKeyUp(int keyCode);
      mouse_point getMousePos();
      mouse_point getMouseSpeed();
      void setMouseLock(bool lock);
      bool getMouseLock();
  };

  extern Input input;
}