#include <string>
#include <bgfx/bgfx.h>

class ShaderProgram {
private:
  std::string name;
  bgfx::ProgramHandle programHandle;
  bgfx::ShaderHandle vsh;
  bgfx::ShaderHandle fsh;
public:
  ShaderProgram(std::string name);
  void load();
  const bgfx::ProgramHandle getProgram() const; 
};