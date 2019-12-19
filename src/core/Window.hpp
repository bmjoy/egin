#pragma once

struct SDL_Window;

namespace core {
  class Window {
  private:
    SDL_Window *window;
    int width;
    int height;
  public:
    void init();
    void start();
    void frame();
    int getWidth() const;
    int getHeight() const;
    SDL_Window *getWindow() const;
  };

  extern Window window;
}