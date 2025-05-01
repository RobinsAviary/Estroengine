#include "Estroengine.h"
#include <iostream>

void Estro::Node::step() {};
void Estro::Node::draw() {};
void Estro::Node::onCreate() {};
void Estro::Node::onDestroy() {};

List<Node*> Estro::Node::getAncestors() {
	List<Node*> result;

	Node* currentNode = parent;

	while (currentNode) {
		result.add(currentNode);

		currentNode = currentNode->parent; // Move to the next parent up
	}

	return result;
}

List<Node*> Estro::Node::getSiblings() {
	List<Node*> result;

	if (parent) {
		result = parent->getChildren();

		result.remove(this);
	}

	return result;
}

List<Node*> Estro::Node::getDescendants() {
	List<Node*> result;

	List<Node*> unexploredNodes = children;

	while (unexploredNodes.size() > 0) {
		Node* node = unexploredNodes.front();
		unexploredNodes.popFront(); // Remove the first item
		result.add(node); // Add to our resulting output
		unexploredNodes.append(node->children); // Add the node's children to our list to explore. This is the point of recursion.
	}
	
	return result;
}

void Estro::Engine::step() {
	List<Node*> descendants = getDescendants();

	for (Node* descendant : descendants) {
		descendant->step();
	}
}

void Estro::Engine::draw() {
	List<Node*> descendants = getDescendants();

	for (Node* descendant : descendants) {
		descendant->draw();
	}
}

void Estro::Engine::update() {
	step();
	draw();
}