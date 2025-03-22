#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../estrotypes.hpp"

std::string rGetBackendName() {
	return "sfml";
}

sf::RenderWindow window;

sf::Clock deltaClock;

float _delta = 0.0f;

bool _mouseHidden = false;

rColor sfColorTorColor(sf::Color color) {
	return rColor{ color.r, color.g, color.b, color.a };
}

sf::Color rColorTosfColor(rColor color) {
	return sf::Color{ color.r, color.g, color.b, color.a };
}

class rCPUTexture {
public:
	sf::Image texture;

	rColor getPixel(rVector2 position) {
		return sfColorTorColor(texture.getPixel(sf::Vector2u{ static_cast<unsigned int>(position.x), static_cast<unsigned int>(position.y) }));
	}

	int getWidth() {
		rVector2 size = getSize();

		return size.x;
	}

	int getHeight() {
		rVector2 size = getSize();

		return size.y;
	}

	rVector2 getSize() {
		sf::Vector2u _size = texture.getSize();
		return rVector2{ static_cast<int>(_size.x), static_cast<int>(_size.y) };
	}

	void load(std::string filename) {
		texture.loadFromFile(filename);
	}

	~rCPUTexture() {

	}
};

class rTexture {
public:
	sf::Texture texture;

	int getWidth() {
		rVector2 size = getSize();

		return size.x;
	}

	int getHeight() {
		rVector2 size = getSize();

		return size.y;
	}

	rVector2 getSize() {
		sf::Vector2u size = texture.getSize();
		return rVector2{ static_cast<int>(size.x), static_cast<int>(size.y) };
	}

	void load(std::string filename) {
		texture.loadFromFile(filename);
	}

	~rTexture() {

	}
};

std::string rGetClipboard() {
	return sf::Clipboard::getString().toAnsiString();
}

void rSetClipboard(std::string _string) {
	sf::Clipboard::setString(sf::String(_string));
}

void rInit(int windowWidth, int windowHeight, std::string windowTitle, bool resizable = false) {
	int style = 0;
	if (resizable) {
		style = sf::Style::Default;
	}
	else {
		style = sf::Style::Close;
	}

	window.create(sf::VideoMode({ static_cast<unsigned int>(windowWidth), static_cast<unsigned int>(windowHeight) }), windowTitle, style);
}

void rDeinit() {
	window.close();
}

void rDrawTexture(const rTexture& texture, rVector2 position, rColor tint) {
	sf::Sprite sprite(texture.texture);

	sprite.setPosition(sf::Vector2f{static_cast<float>(position.x), static_cast<float>(position.y)});
	sprite.setColor(rColorTosfColor(tint));

	window.draw(sprite);
}

void rDrawTextureSection(const rTexture& texture, rVector2 position, rRectangle rectangle, rColor tint) {
	sf::Sprite sprite(texture.texture);

	sprite.setTextureRect(sf::IntRect({ rectangle.x, rectangle.y }, { rectangle.w, rectangle.h }));
	sprite.setPosition(sf::Vector2f{ static_cast<float>(position.x), static_cast<float>(position.y) });
	sprite.setColor(rColorTosfColor(tint));

	window.draw(sprite);
}

void rDrawTextureReproject(const rTexture& texture, rRectangle source, rRectangle target, rColor tint) {
	sf::Sprite sprite(texture.texture);

	sprite.setTextureRect(sf::IntRect({ source.x, source.y }, { source.w, source.h }));

	sf::Vector2f scale = sf::Vector2f{ static_cast<float>(target.x) / static_cast<float>(source.x), static_cast<float>(target.y) / static_cast<float>(source.y) };
	sprite.setScale(scale);

	window.draw(sprite);
}

void rDrawLine(rVector2 pos1, rVector2 pos2, rColor color) {
	sf::Color _color = rColorTosfColor(color);

	std::array line =
	{
		sf::Vertex{sf::Vector2f(pos1.x, pos1.y), _color},
		sf::Vertex{sf::Vector2f(pos2.x, pos2.y), _color}
	};

	window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

void rDrawRectangle(rRectangle rectangle, rColor color, bool filled) {
	sf::Color _color = rColorTosfColor(color);

	sf::RectangleShape shape({ static_cast<float>(rectangle.w), static_cast<float>(rectangle.h) });
	shape.setPosition(sf::Vector2f{ static_cast<float>(rectangle.x), static_cast<float>(rectangle.y) });
	if (filled) {
		shape.setFillColor(_color);
	}
	else {
		shape.setOutlineColor(_color);
		// TODO: Make this able to be changed.
		shape.setOutlineThickness(1);
	}
	window.draw(shape);
}

void rDrawCircle(rVector2 position, float radius, rColor color, bool filled) {
	sf::CircleShape shape(radius);

	shape.setOrigin(sf::Vector2f{ .5, .5 });
	shape.setPosition(sf::Vector2f{ static_cast<float>(position.x), static_cast<float>(position.y) });

	sf::Color _color = rColorTosfColor(color);

	if (filled) {
		shape.setFillColor(_color);
	}
	else {
		shape.setFillColor(_color);
		// TODO: Make this able to be changed.
		shape.setOutlineThickness(1);
	}

	window.draw(shape);
}

// NOTE: DO NOT use in large amounts, this is generally not an efficient way to do whatever you're doing. Look into editing the textures directly or simplifying shapes.
void rDrawPixel(rVector2 position, rColor color) {
	rDrawRectangle(rRectangle{ position.x, position.y, 1, 1 }, color, true);
}

void rBeginStep() {
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window.close();
	}
}

void rEndStep() {

}

void rBeginDraw() {
	
}

void rEndDraw() {
	window.display();
	sf::Time time = deltaClock.restart();
	_delta = time.asSeconds();
}

rVector2 rGetMousePosition() {
	sf::Vector2i pos = sf::Mouse::getPosition();

	return rVector2{ pos.x, pos.y };
}

void rSetMousePosition(rVector2 position) {
	sf::Mouse::setPosition(sf::Vector2i{ position.x, position.y });
}

void rSetWindowTitle(std::string title) {
	window.setTitle(title);
}

int rGetWindowWidth() {
	sf::Vector2u size = window.getSize();
	return size.x;
}

int rGetWindowHeight() {
	sf::Vector2u size = window.getSize();
	return size.y;
}

rVector2 rGetWindowSize() {
	sf::Vector2u size = window.getSize();
	return rVector2{ static_cast<int>(size.x), static_cast<int>(size.y) };
}

void rSetWindowSize(rVector2 size) {
	window.setSize({ static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y) });
}

void rSetWindowOpacity(float opacity) {
	//rPrint("rSetWindowOpacity is not supported on this backend!");
}

void rSetWindowPosition(rVector2 position) {
	window.setPosition({ 10, 50 });
}

rVector2 rGetWindowPosition() {
	sf::Vector2i pos = window.getPosition();

	return rVector2{ pos.x, pos.y };
}

void rShowCursor() {
	window.setMouseCursorVisible(true);
	_mouseHidden = false;
}

void rHideCursor() {
	window.setMouseCursorVisible(false);
	_mouseHidden = true;
}

bool rIsCursorHidden() {
	return _mouseHidden;
}

bool rIsCursorOnScreen() {
	// Get cursor position relative to window
	sf::Vector2i _position = sf::Mouse::getPosition(window);
	rVector2 position = rVector2{ _position.x, _position.y };

	if (position.x >= 0 && position.y >= 0) {
		if (position.x < rGetWindowWidth() && position.y < rGetWindowHeight()) {
			return true;
		}
	}

	return false;
}

rVector2 rGetCursorPosition() {
	sf::Vector2i pos = sf::Mouse::getPosition();
	return rVector2{pos.x, pos.y};
}

void rSetCursorPosition(rVector2 position) {
	sf::Mouse::setPosition(sf::Vector2i{ position.x, position.y });
}

void rDrawClear(rColor color) {
	window.clear(rColorTosfColor(color));
}

void rSetMaxFPS(int fps) {
	window.setFramerateLimit(fps);
}

float rGetDelta() {
	return _delta;
}

bool rIsGameLooping() {
	return window.isOpen();
}

void rSetRandomSeed(unsigned int seed) {
	srand(seed);
}

void rSleep(double seconds) {
	sf::sleep(sf::seconds(seconds));
}

// TODO: Upgrade this to use std members
int rGetRandomValue(int min, int max) {
	return min + (rand() % (max + 1));
}

class rInput {
public:

};
