#pragma once
#include <string>

#include "Estroassets.h"
#include "Estrocolors.h"
#include "Estroinput.h"
#include "Estrotypes.h"
#include "Estronodes.h"

namespace Estro {
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
	void drawTexture(const Texture &texture, Vector2<float> position, Color tint);

	void drawTextureSection(const Texture &texture, Vector2<float> position, Rectangle<int> section, Color tint);

	void drawTextureReproject(const Texture &texture, Vector2<float>position, Rectangle<int> source, Rectangle<float> target, Color tint);

	/*!@brief Check if a key is pressed down.
	@ingroup Input
	@sa Keys::Key
	*/
	bool isKeyDown(Keys::Key key);
	/*!@brief Check if a key was just pressed this frame.
	@ingroup Input
	@sa Keys::Key
	*/
	bool isKeyPressed(Keys::Key key);
	/*!@brief Check if a key was just released this frame.
	@ingroup Input
	@sa Keys::Key
	*/
	bool isKeyReleased(Keys::Key key);

	/*!@brief Get the position of the cursor on-screen.
	 *@ingroup Input
	 */
	Vector2<int> getCursorPosition();
	/*!@brief Set the position of the cursor on-screen.
	 *@ingroup Input
	 */
	void setCursorPosition(Vector2<int> position);

	void playSound(Sound sound);

	void beginStep();
	void endStep();
	void beginDraw();
	void endDraw();

	/*!@brief A basic 2D node that contains and constantly renders a sprite.
	 *@ingroup Graphics
	 */
	class Sprite2D : public Node2D {
		public:
			void step() override;
			void draw() override;

			/*!@brief Set the tint color of the sprite.
			 */
			void setTint(Color color);
			/*!@brief Get the tint color of the sprite.
			 */
			Color getTint();


			/*!@brief The texture used for this sprite.
			 */
			Texture texture;
		private:
			sf::Sprite sprite;
	};
}
