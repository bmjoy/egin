#pragma once
#include <list>

struct SDL_Window;
class Camera;
class Node;

namespace renderer {
  class Renderer {
  private:
    Camera *camera;
    std::list<Node*> drawableNodes;

    bool setPlatformData(SDL_Window* window);
    bool initBgfx();
  public:
    void init();
    void start();
    void frame();
    void setupWindow(SDL_Window *window);
    void setCamera(Camera *camera);
    void addDrawable(Node *node);
    void removeDrawable(Node *node);
  };

  extern Renderer renderer;
}