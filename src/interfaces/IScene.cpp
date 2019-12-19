#include "IScene.hpp"
#include "Node.hpp"
#include <algorithm>

IScene::IScene() {
	this->root = new Node();
	this->root->setRoot(this->root);
}

void IScene::update() {
	std::for_each(this->updatable.begin(), this->updatable.end(), [] (Node *node) {
		node->update();
	});
}

void IScene::addUpdatable(Node *node) {
	this->updatable.push_back(node);
}

void IScene::removeUpdatable(Node *node) {
	this->updatable.remove(node);
}