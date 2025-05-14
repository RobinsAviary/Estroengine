#pragma once
#include <string>

namespace Estro {
	void beginStep();
	void endStep();
	void beginDraw();
	void endDraw();
	void init(unsigned int width, unsigned int height, std::string title);

	bool isLooping();
	void drawRectangle(int x, int y, int w, int h);
}