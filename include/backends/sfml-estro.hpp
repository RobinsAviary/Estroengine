#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../estrotypes.hpp"

std::string backendName = "sfml";

sf::RenderWindow window;

bool mouseHidden = false;

rColor sfColorTorColor(sf::Color color) {
	return rColor{ color.r, color.g, color.b, color.a };
}

sf::Color rColorTosfColor(rColor color) {
	return sf::Color{ color.r, color.g, color.b, color.a };
}

class rCPUTexture {
public:
	// texture;

	rColor getPixel(rVector2 position) {
		
	}

	int getWidth() {
		
	}

	int getHeight() {
		
	}
};

class rTexture {
public:
	// texture;

	int getWidth() {
		
	}

	int getHeight() {
		
	}
};

rTexture rLoadTexture(std::string filename) {

};

void rUnloadTexture(rTexture texture) {
	
}

rCPUTexture rLoadCPUTexture(std::string filename) {
	
}

void rUnloadCPUTexture(rCPUTexture texture) {
	
}

void rInit(int windowWidth, int windowHeight, std::string windowTitle) {
	window.create(sf::VideoMode({ static_cast<unsigned int>(windowWidth), static_cast<unsigned int>(windowHeight) }), windowTitle);
}

void rDeinit() {
	window.close();
}

void rDrawTexture(rTexture* texture, rVector2 position, rColor tint) {
	
}

void rDrawTextureSection(rTexture* texture, rVector2 position, rRectangle rectangle, rColor tint) {
	
}

void rDrawTextureReproject(rTexture* texture, rRectangle source, rRectangle target, rColor tint) {
	
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
	mouseHidden = false;
}

void rHideCursor() {
	window.setMouseCursorVisible(false);
	mouseHidden = true;
}

bool rIsCursorHidden() {
	return mouseHidden;
}

bool rIsCursorOnScreen() {
	
}

void rDrawClear(rColor color) {
	window.clear(rColorTosfColor(color));
}

void rSetMaxFPS(int fps) {
	window.setFramerateLimit(fps);
}

float rGetDelta() {
	
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
