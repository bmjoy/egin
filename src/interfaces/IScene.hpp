#pragma once
#include <list>

class Node;

class IScene {
private:
	Node *root;
	std::list<Node*> updatable;
public:
	IScene();

	virtual void load() = 0;
	virtual void start() = 0;
	virtual void clear() = 0;
	inline Node *getRoot() { return root; }
	void update();
	void addUpdatable(Node *node);
	void removeUpdatable(Node *node);
};