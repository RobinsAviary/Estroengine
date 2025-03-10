#pragma once
#include "include/estrotypes.hpp"
#include <string>
#include <vector>

// Estroengine 0.4, created by Robin

class rNode {
	public:
		virtual void step() {}
		virtual void draw() {}

	private:
		std::vector<std::string> tags;
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

	}



private:

};