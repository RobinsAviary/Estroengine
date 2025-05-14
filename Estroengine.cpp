#include "Estroengine.h"
#include <iostream>

List<Node*> garbage;

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

// Returns a list of descendants that is guaranteed to be ordered with higher (closer to root) nodes first.
List<Node*> Estro::Node::getDescendants() {
	List<Node*> result;

	List<Node*> unexploredNodes = getChildren();

	while (unexploredNodes.size() > 0) {
		Node* node = unexploredNodes.front();
		unexploredNodes.popFront(); // Remove the first item
		result.add(node); // Add to our resulting output
		unexploredNodes.append(node->getChildren()); // Add the node's children to our list to explore. This is the point of recursion.
	}
	
	return result;
}

// GARBAGE DAY. /ref
void Estro::Engine::garbageCollect() {
	for (Node* piece : garbage) {
		delete piece;
	}

	garbage.clear();
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
	beginStep();
	step();
	endStep();
	beginDraw();
	draw();
	endDraw();
	garbageCollect();
}

List<Node*> Node::getChildren() {
	return _children;
}

Node* Node::getRoot() {
	Node* node = this;
	
	while (true) {
		if (node->parent) {
			node = node->parent;
		}
		else {
			return node;
		}
	}
}

List<Node*> Node::getChildrenTagged(std::string tag) {
	List<Node*> result;

	List<Node*> children = getChildren();

	for (Node* child : children) {
		if (child->hasTag(tag)) {
			result.add(child);
		}
	}

	return result;
}

List<Node*> Node::getAncestorsTagged(std::string tag) {
	List<Node*> result;

	while (true) {
		Node* currentNode = this;
		
		if (currentNode->hasTag(tag)) result.add(currentNode);

		if (currentNode->parent) {
			currentNode = currentNode->parent;
		}
		else {
			break;
		}
	}

	return result;
}

List<Node*> Node::getSiblingsTagged(std::string tag) {
	List<Node*> siblings = getSiblings();
	List<Node*> result;

	for (Node* sibling : siblings) {
		if (sibling->hasTag(tag)) result.add(sibling);
	}

	return result;
}

List<Node*> Node::getDescendantsTagged(std::string tag) {
	List<Node*> descendants = getDescendants();
	List<Node*> result;

	for (Node* descendant : descendants) {
		if (descendant->hasTag(tag)) {
			result.add(descendant);
		}
	}

	return result;
}

Node* Node::getChildTagged(std::string tag) {
	List<Node*> children = getChildren();
	
	for (Node* child : children) {
		if (child->hasTag(tag)) return child;
	}

	return NULL;
}

Node* Node::getAncestorTagged(std::string tag) {
	Node* node = this;
	while (true) {
		if (node->parent) {
			if (node != this && node->hasTag(tag)) { // Check if it's not ourselves.
				return node; 
			}

			node = node->parent;
		}
		else {
			return NULL;
		}
	}
}

Node* Node::getSiblingTagged(std::string tag) {
	List<Node*> siblings = getSiblings();

	for (Node* sibling : siblings) {
		if (sibling->hasTag(tag)) return sibling;
	}

	return NULL;
}

Node* Node::getDescendantTagged(std::string tag) {
	List<Node*> unexploredNodes = getChildren();

	while (unexploredNodes.size() > 0) {
		Node* node = unexploredNodes.front();
		unexploredNodes.popFront();

		if (node->hasTag(tag)) return node;

		unexploredNodes.append(node->getChildren());
	}

	return NULL;
}

template <typename nodeType>
nodeType* Node::addNode() {
	Node* node = new nodeType;
	_children.add(node);
	
	return node;
}

void Node::addTag(std::string tag) {
	if (!_tags.has(tag)) {
		_tags.add(tag);
	}
}

void Node::removeTag(std::string tag) {
	_tags.remove(tag);
}

bool Node::hasTag(std::string tag) {
	return _tags.has(tag);
}

List<std::string> Node::getTags() {
	return _tags;
}