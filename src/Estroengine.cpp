#include "../include/Estroengine.h"
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

	while (unexploredNodes.getSize() > 0) {
		Node* node = unexploredNodes.front();
		unexploredNodes.popFront(); // Remove the first item
		result.add(node); // Add to our resulting output
		unexploredNodes.append(node->getChildren()); // Add the node's children to our list to explore. This is the point of recursion.
	}
	
	return result;
}

// GARBAGE DAY. /ref
void Estro::Engine::garbageCollect() {
	for (const Node* piece : garbage) {
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

List<Node*> Node::getChildrenTagged(const std::string &tag) {
	List<Node*> result;

	List<Node*> children = getChildren();

	for (Node* child : children) {
		if (child->hasTag(tag)) {
			result.add(child);
		}
	}

	return result;
}

List<Node*> Node::getAncestorsTagged(const std::string &tag) {
	List<Node*> result;
	List<Node*> ancestors = getAncestors();

	for (Node* ancestor : ancestors) {
		if (ancestor->hasTag(tag)) {
			result.add(ancestor);
		}
	}

	return result;
}

List<Node*> Node::getSiblingsTagged(const std::string &tag) {
	List<Node*> siblings = getSiblings();
	List<Node*> result;

	for (Node* sibling : siblings) {
		if (sibling->hasTag(tag)) result.add(sibling);
	}

	return result;
}

List<Node*> Node::getDescendantsTagged(const std::string &tag) {
	List<Node*> descendants = getDescendants();
	List<Node*> result;

	for (Node* descendant : descendants) {
		if (descendant->hasTag(tag)) {
			result.add(descendant);
		}
	}

	return result;
}

Node* Node::getChildTagged(const std::string &tag) {
	List<Node*> children = getChildren();
	
	for (Node* child : children) {
		if (child->hasTag(tag)) return child;
	}

	return nullptr;
}

Node* Node::getAncestorTagged(const std::string &tag) {
	Node* node = this;
	while (true) {
		if (node->parent) {
			if (node != this && node->hasTag(tag)) { // Check if it's not ourselves.
				return node; 
			}

			node = node->parent;
		}
		else {
			return nullptr;
		}
	}
}

Node* Node::getSiblingTagged(const std::string &tag) {
	List<Node*> siblings = getSiblings();

	for (Node* sibling : siblings) {
		if (sibling->hasTag(tag)) return sibling;
	}

	return nullptr;
}

Node* Node::getDescendantTagged(const std::string &tag) {
	List<Node*> unexploredNodes = getChildren();

	while (unexploredNodes.getSize() > 0) {
		Node* node = unexploredNodes.front();
		unexploredNodes.popFront();

		if (node->hasTag(tag)) return node;

		unexploredNodes.append(node->getChildren());
	}

	return nullptr;
}

void Node::addTag(const std::string &tag) {
	if (!_tags.has(tag)) {
		_tags.add(tag);
	}
}

void Node::removeTag(const std::string &tag) {
	_tags.remove(tag);
}

bool Node::hasTag(const std::string &tag) {
	return _tags.has(tag);
}

List<std::string> Node::getTags() {
	return _tags;
}

void Node::destroy() {
	auto list = getDescendants();
	list.add(this);
	garbage.append(list);
	if (parent) {
		parent->_children.remove(this);
	}
	onDestroy();
}

void Node::destroyChildTagged(const std::string &tag) {
	if (Node* node = getChildTagged(tag)) {
		node->destroy();
	}
}

void Node::destroyAncestorTagged(const std::string &tag) {
	if (Node* node = getAncestorTagged(tag)) {
		node->destroy();
	}
}

void Node::destroySiblingTagged(const std::string &tag) {
	if (Node* node = getSiblingTagged(tag)) {
		node->destroy();
	}
}

void Node::destroyDescendantTagged(const std::string &tag) {
	if (Node* node = getDescendantTagged(tag)) {
		node->destroy();
	}
}


void Node::destroyChildrenTagged(const std::string &tag) {
	for (auto child : getChildrenTagged(tag)) {
		child->destroy();
	}
}

void Node::destroyAncestorsTagged(const std::string &tag) {
	for (auto ancestor : getAncestorsTagged(tag)) {
		ancestor->destroy();
	}
}

void Node::destroySiblingsTagged(const std::string &tag) {
	for (auto sibling : getSiblingsTagged(tag)) {
		sibling->destroy();
	}
}

void Node::destroyDescendantsTagged(const std::string &tag) {
	for (auto descendant : getDescendantsTagged(tag)) {
		descendant->destroy();
	}
}