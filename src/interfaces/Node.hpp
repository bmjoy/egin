#include "math/Transform.hpp"
#include <set>

class Drawable;
namespace renderer { class Renderer; }

class Node : public Transform {
private:
  Node *root; // If root == NULL then this == root.
  Node *parent;
  std::set<Node*> children;
  Drawable *drawable;

  friend renderer::Renderer;
public:  
  virtual void update() {};
  void setParent(Node *parent);
  void setDrawable(Drawable *drawable);
  Node *getRoot() const;
  void setRoot(Node *root);
};