#pragma once
#include <glm/gtc/quaternion.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Transform
{
private:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
public:
    Transform();
    glm::mat4 toMatrix() const;
    void translate(const glm::vec3 &position);
    void move(const glm::vec3 &position);
    glm::vec3 getPosition() const;
    void rotate(const glm::vec3 &angles);
    void setRotation(const glm::vec3 &angles);
    void setRotation(const glm::quat &rotation);
};
