#pragma once
#include "include/estrotypes.hpp"
#include "include/backends/raylib-estro.hpp"
#include <string>
#include <vector>
#include <memory>
#include <ostream>

// Estroengine 0.4, created by Robin

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
		virtual void onDestroy() {}

		rNode* parent = nullptr;

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

		template <typename T>
		T* addNode() {
			rNode* pointer = new T;
			if (pointer) {
				children.push_back(pointer);
			}

			pointer->parent = this;
			
			return static_cast<T*>(pointer);
		}

		void removeNode(int index) {
			children.erase(children.begin() + index);
		}

		void destroy() {
			onDestroy();

 			auto children = getAllChildren();

			for (auto child : children) {
				delete child;
				child = nullptr;

				int i = 0;
			}

			if (parent != nullptr) {
				int parentChildrenSize = parent->children.size();
				for (int i = 0; i < parentChildrenSize; i++) {
					if (parent->children[i] == this) {
						parent->children[i] = nullptr;
						parent->children.erase(parent->children.begin() + i);
						break;
					}
				}
			}

			delete this;
		}

		template <typename T>
		T* insertNode(int index) {
			rNode* pointer = new T;

			if (pointer) {
				children.insert(children.begin() + index, pointer);
			}

			pointer->parent = this;

			return static_cast<T*>(children[index]);
		}

		std::vector<rNode*> getChildren() {
			return children;
		}

		std::vector<rNode*> getAllChildren() {
			std::vector<rNode*> result;

			// Recursively iterate through hierarchy.
			std::vector<rNode*> unexploredNodes;

			unexploredNodes = children;
			result = children;

			while (unexploredNodes.size() > 0) {
				rNode* node = unexploredNodes.back(); // Get last node
				unexploredNodes.pop_back(); // Remove last node
				
				if (node->children.size() != 0) { // If current node has children
					for (auto child : node->children) {
						unexploredNodes.push_back(child); // Push back all children to the unexplored nodes and result.
						result.push_back(child);
					}
				}
			}

			return result;
		}

		bool hasTag(std::string tag) {
			return (std::find(tags.begin(), tags.end(), tag) != tags.end());
		}

		std::vector<rNode*> getChildrenTagged(std::string tag) {
			std::vector<rNode*> result;
			
			for (auto child : children) {
				if (child->hasTag(tag)) {
					result.push_back(child);
				}
			}

			return result;
		}

		// TODO: std::vector<rNode*> getAllChildrenTagged(std::string tag)

		void destroyChildrenTagged(std::string tag) {
			auto childrenCopy = children;

			for (auto child : childrenCopy) {
				if (child->hasTag(tag)) {
					child->destroy();
				}
			}
		}

		void addTag(std::string tag) {
			if (!hasTag(tag)) {
				tags.push_back(tag);
			}
		}

		void removeTag(std::string tag) {
			tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
		}

	private:
		std::vector<std::string> tags;
		std::vector<rNode*> children;
};

class rNode2D : public rNode {
public:
	rVector2 position;
	float rotation;
};

class rNode3D : public rNode {
public:
	rVector3 position;
	rVector3 rotation;
};

class rEngine {
public:
	void update() {
		step();
		draw();
	}

	rNode* root;

	rEngine() {
		root = new rNode();
	}

	~rEngine() {
		delete root;
		root = nullptr;
	}

private:
	void step() {
		root->step();
		root->childrenStep();
	}

	void draw() {
		rBeginDraw();
		
		root->draw();
		root->childrenDraw();

		rEndDraw();
	}
};