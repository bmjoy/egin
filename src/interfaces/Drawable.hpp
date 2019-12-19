#include <bgfx/bgfx.h>

class Drawable {
private:
  bgfx::VertexBufferHandle vertexBufferHandle;
  bgfx::IndexBufferHandle indexBufferHandle;
public:
  Drawable();
  void draw();
};