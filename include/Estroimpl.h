#pragma once
#include "Estrovector.h"
#include "Estrocolors.h"
#include "Estroassets.h"
#include <string>

namespace Estro {
	void beginStep();
	void endStep();
	void beginDraw();
	void endDraw();
	void init(unsigned int width, unsigned int height, std::string title);

	bool isLooping();

	/*! Draws a colored rectangle to the screen.
	@ingroup Graphics
	*/
	void drawRectangle(Vector2<float> position, Vector2<float> size, Color color);
	/*! Draws a colored line to the screen.
	@ingroup Graphics
	*/
	void drawLine(Vector2<float> startPosition, Vector2<float> endPosition, Color color);
	/*! Draws a colored circle to the screen.
	@ingroup Graphics
	*/
	void drawCircle(Vector2<float> position, float size, Color color);
	/*! Resets all
	@ingroup Graphics
	*/
	void drawClear(Color color);
	//!@ingroup Graphics
	void drawTexture(Vector2<float> position, const Texture &texture, Color color = Colors::White);
}