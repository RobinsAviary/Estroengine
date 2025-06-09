#pragma once
#include "Estrovector.h"
#include "Estrocolors.h"
#include <string>

namespace Estro {
	void beginStep();
	void endStep();
	void beginDraw();
	void endDraw();
	void init(unsigned int width, unsigned int height, std::string title);

	bool isLooping();

	// These should mostly be used for debug.
	void drawRectangle(Vector2<float> position, Vector2<float> size, Color color);
	void drawLine(Vector2<float> startPosition, Vector2<float> endPosition, Color color);
	void drawCircle(Vector2<float> position, float size, Color color);
	void drawClear(Color color);
}