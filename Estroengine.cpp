#include "Estroengine.h"
#include <iostream>

void Estro::Node::step() {};
void Estro::Node::draw() {};
void Estro::Node::onCreate() {};
void Estro::Node::onDestroy() {};

void Estro::Engine::step() {
	List<Node*> unexploredNodes = children;

	while (unexploredNodes.size() > 0) {
		Node* node = unexploredNodes.front();
		unexploredNodes.popFront();
		node->step();
		unexploredNodes.append(node->children);
	}
}