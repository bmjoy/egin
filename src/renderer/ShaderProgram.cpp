#include "ShaderProgram.hpp"
#include <brtshaderc/brtshaderc.h>

ShaderProgram::ShaderProgram(std::string name)
: name(name)
{
}

void ShaderProgram::load()
{
    const std::string vshPath = "data/shader/" + this->name + ".vert";
    const std::string fshPath = "data/shader/" + this->name + ".frag";

    const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, vshPath.c_str());
    const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, fshPath.c_str());

    if(!memVsh)
      throw std::exception(("Error while compiling vertex shader " + vshPath).c_str());
    
    if(!memFsh)
      throw std::exception(("Error while compiling fragment shader " + vshPath).c_str());

    // Create shaders.
    this->vsh = bgfx::createShader(memVsh);
    this->fsh = bgfx::createShader(memFsh);

    // Create bgfx program.
    this->programHandle = bgfx::createProgram(this->vsh, this->fsh, true);

    if(!bgfx::isValid(this->programHandle))
      throw std::exception(("Error while creating bgfx program: " + name).c_str());
}

const bgfx::ProgramHandle ShaderProgram::getProgram() const {
  return this->programHandle;
}