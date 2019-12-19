#include "Node.hpp"
#include "renderer/Renderer.hpp"

void Node::setParent(Node *parent) {
  if (this->parent) {
    this->parent->children.erase(this);
  }
  
  if (parent) {
    this->parent = parent;
    this->parent->children.insert(this);
    if (!this->root)
      this->root = this->parent->getRoot();
  } else {
    this->parent = this->getRoot();
  }
}

void Node::setDrawable(Drawable *drawable)
{
  if (drawable == nullptr) {
    renderer::renderer.removeDrawable(this);
    return;
  }

  this->drawable = drawable;
  renderer::renderer.addDrawable(this);
}

Node *Node::getRoot() const
{
  return this->root;
}

void Node::setRoot(Node *root)
{
  this->root = root;
}