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

		void childrenStep() {
			int childrenSize = children.size();
			for (int i = 0; i < + )
		}

		void childrenDraw() {

		}

		std::unique_ptr<rNode>* addNode(rNode* pointer) {
			if (pointer) {
				children.push_back(std::unique_ptr<rNode>(pointer));
			}
			
			return &children[children.size() - 1];
		}

		void removeNode(int index) {
			children.erase(children.begin() + index);
		}

		std::unique_ptr<rNode>* insertNode(int index, rNode* pointer) {
			if (pointer) {
				children.insert(children.begin() + index, std::unique_ptr<rNode>(pointer));
			}

			return &children[index];
		}

	private:
		std::vector<std::string> tags;
		std::vector<std::unique_ptr<rNode>> children;
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
	}

	void draw() {
		root->draw();
	}
};