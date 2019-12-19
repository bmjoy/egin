#include "Transform.hpp"

Transform::Transform()
    : scale(glm::vec3(1))
    , rotation({ 0, 0, 0 })
{
}

glm::mat4 Transform::toMatrix() const
{
  return glm::scale(glm::mat4(1), this->scale)
		* glm::mat4_cast(this->rotation)
		* glm::translate(glm::mat4(1), -this->position);
}

void Transform::translate(const glm::vec3 &position)
{
  this->position += position;
}

void Transform::move(const glm::vec3 &position)
{
  this->position += position * this->rotation;
}

glm::vec3 Transform::getPosition() const
{
  return this->position;
}

void Transform::rotate(const glm::vec3 &angles)
{
  this->rotation = glm::normalize(this->rotation * glm::quat(angles));
}

void Transform::setRotation(const glm::vec3 &angles)
{
  this->rotation = angles;
}

void Transform::setRotation(const glm::quat &rotation)
{
  this->rotation = rotation;
}