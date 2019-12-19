#include "Camera.hpp"
#include <bgfx/bgfx.h>
#include "math/Transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <bx/math.h>
#include "renderer/Renderer.hpp"

Camera::Camera(float ratio, float fov, float nearPlane, float farPlane) :
  ratio(ratio), fov(fov), nearPlane(nearPlane), farPlane(farPlane), target(nullptr)
{
  renderer::renderer.setCamera(this);
  this->generateProjection();
}

void Camera::generateProjection()
{
  // this->projection = glm::perspective(45.0f, float(800)/float(600), 0.1f, 100.0f);
  // WTF IS IT?!?
  float proj[16];
	bx::mtxProj(proj, this->fov, this->ratio, this->nearPlane, this->farPlane, bgfx::getCaps()->homogeneousDepth);
  this->projection = glm::make_mat4(proj);
}

void Camera::setup()
{ 
  //auto matrix = this->target->toMatrix();
  //for (int i = 0; i < 4; i++)
  //  for (int j = 0; j < 4; j++)
  //    bgfx::dbgTextPrintf(j * 5, i, 0x0f, "%i", (int)matrix[i][j]);

  bgfx::setViewTransform(
    NULL,
    glm::value_ptr(this->target ? this->target->toMatrix() : glm::mat4()),
    glm::value_ptr(this->projection)
  );
}

void Camera::setTarget(Transform *target)
{
  this->target = target;
}