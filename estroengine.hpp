#pragma once
#include "include/backends/sfml-estro.hpp"
#include "include/estrotypes.hpp"
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <iostream>

// Estroengine 0.4, created by Robin

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

		rNode* parent = nullptr;

		template <typename T>
		T* addNode() {
			rNode* pointer = new T;
			if (pointer) {
				children.pushBack(pointer);
			}

			pointer->parent = this;

			pointer->onCreate();
			
			return static_cast<T*>(pointer);
		}

		rNode* getNode(rNode* pointer) {
			auto _children = getRoot()->getAllChildren();

			for (auto child : children) {
				if (child == pointer) {
					return child;
				}
			}
		}

		rNode* getNode(unsigned int handle) {
			auto _children = getRoot()->getAllChildren();

			for (auto child : children) {
				if (child->getHandle() == handle) {
					return child;
				}
			}
		}

		unsigned int getHandle() {
			return _handle;
		}

		void removeNode(int index) {
			children.erase(index);
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

			return static_cast<T*>(children[index]);
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

		rList<rNode*> getAllChildren() {
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
						unexploredNodes.pushBack(child); // Push back all children to the unexplored nodes and result.
						result.pushBack(child);
					}
				}
			}

			return result;
		}

		rList<rNode*> getAllChildrenTagged(std::string tag) {
			auto _children = getAllChildren();
			rList<rNode*> result;

			for (auto child : _children) {
				if (child->hasTag(tag)) {
					result.add(child);
				}
			}

			return result;
		}

		bool hasTag(std::string tag) {
			return (std::find(tags.begin(), tags.end(), tag) != tags.end());
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

		rList<rNode*> getSiblings() {
			rList<rNode*> result;
			
			if (parent) {
				 parent->getChildren();

				// Remove self from list
				result.erase(this);
			}

			return result;
		}

		// TODO: Fix
		template <typename T = rNode>
		rList<T*> getSiblingsTagged(std::string tag) {
			if (parent!=nullptr) {
				return parent->getChildrenTagged<T>(tag);
			}

			rList<T*> blankList;
			return blankList;
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
				if (child->hasTag(tag)) {
					child->destroy();
				}
			}
		}

		bool isValid() { return _valid; }

		void addTag(std::string tag) {
			if (!hasTag(tag)) {
				tags.push_back(tag);
			}
		}

		void removeTag(std::string tag) {
			tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
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
		std::vector<std::string> tags;
		rList<rNode*> children;

	protected:
		bool _valid = true;
		unsigned int _handle = 0;
		std::string _name;

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
			rNode* currentNode = static_cast<rNode*>(piece);

			auto allChildren = currentNode->getAllChildren();

			for (auto child : allChildren) {
				delete child;
				child = NULL;
			}

			delete piece;
			piece = NULL;
		}

		garbage.clear();
	}
};