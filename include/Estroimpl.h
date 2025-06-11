#pragma once
#include "Estrotypes.h"
#include "Estrocolors.h"
#include "Estroassets.h"
#include "Estroinput.h"
#include <string>

namespace Estro {
	void beginStep();
	void endStep();
	void beginDraw();
	void endDraw();
	void init(unsigned int width, unsigned int height, std::string title);

	bool isLooping();

	/*!@brief Draws a colored rectangle to the screen.
	@ingroup Graphics
	*/
	void drawRectangle(Vector2<float> position, Vector2<float> size, Color color);
	/*!@brief Draws a colored line to the screen.
	@ingroup Graphics
	*/
	void drawLine(Vector2<float> startPosition, Vector2<float> endPosition, Color color);
	/*!@brief Draws a colored circle to the screen.
	@ingroup Graphics
	*/
	void drawCircle(Vector2<float> position, float size, Color color);
	/*!@brief Draws a single color across the entire screen.
	@ingroup Graphics
	*/
	void drawClear(Color color);
	//!@ingroup Graphics
	void drawTexture(Vector2<float> position, const Texture &texture, Color color = Colors::White);

	/*!@brief Check if a key is pressed down.
	@ingroup Input
	*/
	bool isKeyDown(Keys::Key key);
	/*!@brief Check if a key was just pressed this frame.
	@ingroup Input
	*/
	bool isKeyPressed(Keys::Key key);
	/*!@brief Check if a key was just released this frame.
	@ingroup Input
	*/
	bool isKeyReleased(Keys::Key key);

	/*!@brief Get the position of the cursor on-screen.
	 *@ingroup Input
	 */
	Vector2<int> getCursorPosition();
	/*!@brief Set the position of the cursor on-screen.
	 *@ingorup Input
	 */
	void setCursorPosition(Vector2<int> position);
}