#pragma once
#include "include/backends/sfml-estro.hpp"
#include "include/estrotypes.hpp"
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <iostream>
#include <typeindex>

// Estroengine v0.1.5, created by Robin <3

rList<void*> garbage;

void rPrint(std::string text) {
	std::cout << text << std::endl;
}

// For printing lots of text to console. Either this or just use a string you build up and then output to console depending on memory limitations.
void rPrintCache(std::string text) {
	std::cout << text << "\n";
}

// Companion to rPrintCache();
void rPrintFlush() {
	std::cout << std::endl;
}

class rNode {
	public:
		virtual void step() {}
		virtual void draw() {}
		virtual void onCreate() {}
		virtual void onDestroy() {}

		template <typename T>
		T* addNode() {
			rNode* pointer = new T;
			if (pointer) {
				children.pushBack(pointer);
			}

			pointer->parent = this;

			pointer->_type = typeid(T);

			pointer->onCreate();
			
			return static_cast<T*>(pointer);
		}

		rNode* getRoot() {
			rNode* currentNode = parent;

			while (currentNode->parent) {
				currentNode = currentNode->parent;
			}

			return currentNode;
		}

		rList<rNode*> getChildren() {
			return children;
		}

		rNode* getParent() {
			return parent;
		}

		rNode* getNode(rNode* pointer) {
			auto _children = getRoot()->getDescendants();

			for (auto child : children) {
				if (child == pointer) {
					return child;
				}
			}
		}

		rNode* getNode(unsigned int handle) {
			auto _children = getRoot()->getDescendants();

			for (auto child : children) {
				if (child->getHandle() == handle) {
					return child;
				}
			}
		}

		unsigned int getHandle() {
			return _handle;
		}

		void destroy() {
			_valid = false;

			if (parent) {
				parent->children.erase(this);
			}
			
			garbage.add(this);

			onDestroy();
		}

		template <typename T>
		T* insertNode(int index) {
			rNode* pointer = new T;

			if (pointer) {
				children.insert(pointer, index);
			}

			pointer->parent = this;
			pointer->_type = typeid(T);

			return static_cast<T*>(children[index]);
		}

		// Old query system
		template <typename T = rNode>
		T* getAncestorTagged(std::string tag) {
			auto ancestors = getAncestors();

			for (auto ancestor : ancestors) {
				if (ancestor->isTagged(tag)) {
					return static_cast<T*>(ancestor);
				}
			}

			return NULL;
		}

		template <typename T = rNode>
		rList<T*> getAncestorsTagged(std::string tag) {
			auto ancestors = getAncestors();

			rList<rNode*> result;

			for (auto ancestor : ancestors) {
				if (ancestor->isTagged(tag)) {
					result.add(static_cast<T>(ancestor));
				}
			}

			return result;
		}

		template <typename T = rNode>
		T* getChildTagged(std::string tag) {
			for (auto child : children) {
				if (child->isTagged(tag)) return static_cast<T>(child);
			}

			return NULL;
		}

		template <typename T = rNode>
		T* getDescendantTagged(std::string tag) {
			auto descendants = getDescendants();

			for (auto descendant : descendants) {
				if (descendant->isTagged(tag)) return static_cast<T>(descendant);
			}

			return NULL;
		}

		template <typename T = rNode>
		rList<T*> getDescendantsTagged(std::string tag) {
			auto _children = getDescendants();
			rList<rNode*> result;

			for (auto child : _children) {
				if (child->isTagged(tag)) {
					result.add(static_cast<T>(child));
				}
			}

			return result;
		}

		template <typename T = rNode>
		rList<T*> getSiblingsTagged(std::string tag) {
			rList<T*> result;

			rList<rNode*> siblings = getSiblings();

			for (auto sibling : siblings) {
				if (sibling->hasTag(tag)) {
					result.add(static_cast<T*>(sibling));
				}
			}

			return result;
		}

		template <typename T = rNode>
		T* getSiblingTagged(std::string tag) {
			rList<rNode*> siblings = getSiblings();

			for (auto sibling : siblings) {
				if (sibling->hasTag(tag)) {
					return static_cast<T*>(sibling);
				}
			}

			return NULL;
		}

		template <typename T = rNode>
		rList<T*> getChildrenTagged(std::string tag) {
			rList<T*> result;

			for (auto child : children) {
				if (child->hasTag(tag)) {
					result.add(static_cast<T*>(child));
				}
			}

			return result;
		}

		// New Query system
		rList<rNode*> getAncestors() {
			rList<rNode*> result;

			rNode* currentParent = getParent();
			while (currentParent) {
				result.add(currentParent);

				currentParent = currentParent->getParent();
			}

			return result;
		}

		template <typename T>
		rList<T*> getAncestors() {
			auto ancestors = getAncestors();
			rList<T*> result;

			for (auto ancestor : ancestors) {
				if (ancestor->_type == T) {
					result.add(ancestor);
				}
			}

			return result;
		}

		rList<rNode*> getDescendants() {
			rList<rNode*> result;

			// Recursively iterate through hierarchy.
			rList<rNode*> unexploredNodes;

			unexploredNodes = children;
			result = children;

			while (unexploredNodes.size() > 0) {
				rNode* node = unexploredNodes.back(); // Get last node
				unexploredNodes.popBack(); // Remove last node

				if (node->children.size() != 0) { // If current node has children
					for (auto child : node->children) {
						unexploredNodes.add(child); // Push back all children to the unexplored nodes and result.
						result.add(child);
					}
				}
			}

			return result;
		}

		template <typename T>
		rList<T*> getDescendants() {
			auto descendants = getDescendants();
			rList<T*> result;

			for (auto descendant : descendants) {
				if (descendant->_type == T) {
					result.add(descendant);
				}
			}

			return result;
		}

		template <typename T>
		T* getSibling() {
			auto siblings = getSiblings();

			for (auto sibling : siblings) {
				if (sibling->_type == T) {
					return sibling;
				}
			}
		}

		rList<rNode*> getSiblings() {
			rList<rNode*> result;

			if (parent) {
				parent->getChildren();

				// Remove self from list
				result.erase(this);
			}

			return result;
		}

		template <typename T>
		rList<T*> getSiblings() {
			auto siblings = getSiblings();
			rList<T*> result;

			for (auto sibling : siblings) {
				if (sibling->_type == T) {
					result.add(sibling);
				}
			}

			return result;
		}

		template <typename T>
		T* getChild() {
			for (auto child : children) {
				if (child->_type == T) {
					return child;
				}
			}
		}

		template <typename T>
		rList<T*> getChildren() {
			rList<T*> result;

			for (auto child : children) {
				if (child->_type == T) {
					result.add(child);
				}
			}

			return result;
		}

		bool isTagged(std::string tag) {
			return (tags.has(tag));
		}

		void destroyAllChildren() {
			auto childrenCopy = children;

			for (auto child : childrenCopy) {
				child->destroy();
			}
		}

		void destroyChildrenTagged(std::string tag) {
			auto childrenCopy = children;

			for (auto child : childrenCopy) {
				if (child->isTagged(tag)) {
					child->destroy();
				}
			}
		}

		bool isValid() { return _valid; }

		void addTag(std::string tag) {
			if (!isTagged(tag)) {
				tags.add(tag);
			}
		}

		void removeTag(std::string tag) {
			tags.erase(tag);
		}
		
		std::string getName() {
			return _name;
		}

		void setName(std::string name) {
			_name = name;
		}

		bool isNamed(std::string name) {
			return (name == _name);
		}

	private:
		rList<std::string> tags;
		rList<rNode*> children;
		rNode* parent = nullptr;

	protected:
		bool _valid = true;
		unsigned int _handle = 0;
		std::string _name;
		std::type_index _type = typeid(rNode);

		void childrenStep() {
			if (children.size() != 0) {
				for (auto child : children) {
					child->step();
					child->childrenStep();
				}
			}
		}

		void childrenDraw() {
			if (children.size() != 0) {
				for (auto child : children) {
					child->draw();
					child->childrenDraw();
				}
			}
		}
};

class rNode2D : public rNode {
public:
	rVector2<float> position;
	float rotation;
};

class rNode3D : public rNode {
public:
	rVector3<float> position;
	rVector3<float> rotation;
};

class rEngine : public rNode {
public:
	void onCreate() {
		_type = typeid(rEngine);
	}

	void update() {
		step();
		draw();
		garbageCollect();
	}

	void step() {
		rBeginStep();
		childrenStep();
		rEndStep();
	}

	void draw() {
		rBeginDraw();
		childrenDraw();
		rEndDraw();
	}

	// GARBAGE DAY. /ref
	void garbageCollect() {
		for (auto piece : garbage) {
			if (piece) {
				rNode* currentNode = static_cast<rNode*>(piece);

				auto allChildren = currentNode->getDescendants();

				for (auto child : allChildren) {
					delete child;
					child = NULL;
				}

				delete piece;
				piece = NULL;
			}
		}

		garbage.clear();
	}
};