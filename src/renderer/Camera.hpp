#pragma once
#include <glm/mat4x4.hpp>

class Transform;

class Camera {
private:
  Transform *target;
  float fov;
  float ratio;
  float nearPlane;
  float farPlane;

  glm::mat4 projection;
public:
  Camera(float ratio, float fov = 60, float nearPlane = 0.1, float farPlane = 100);
  void setTarget(Transform *target);
  void generateProjection();
  void setup();
};