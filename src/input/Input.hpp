#include "SDL_Keyboard.h"

namespace engine {
  class Input {
    private:
      int numKeys;
      const uint8_t *keyState;
      const uint8_t *keyOldState;
    public:
      Input();
      void update();
      bool isKeyPressed(int keyCode);
      bool isKeyDown(int keyCode);
      bool isKeyUp(int keyCode);
  };

  extern Input input;
}