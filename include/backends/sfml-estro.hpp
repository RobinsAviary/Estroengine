#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../estrotypes.hpp"

std::string backendName = "sfml";

sf::Window window;

class rCPUTexture {
public:
	 texture;

	rColor getPixel(rVector2 position) {
		
	}

	int getWidth() {
		
	}

	int getHeight() {
		
	}
};

class rTexture {
public:
	 texture;

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
	sf::Window _window(sf::VideoMode({ 800, 600 }), "My window");
	window = _window;
}

void rDeinit() {
	
}

void rDrawTexture(rTexture* texture, rVector2 position, rColor tint) {
	
}

void rDrawTextureSection(rTexture* texture, rVector2 position, rRectangle rectangle, rColor tint) {
	
}

void rDrawTextureReproject(rTexture* texture, rRectangle source, rRectangle target, rColor tint) {
	
}

void rDrawLine(rVector2 pos1, rVector2 pos2, rColor color) {
	
}

void rDrawRectangle(rRectangle rectangle, rColor color, bool filled) {
	
}

void rDrawCircle(rVector2 position, float radius, rColor color, bool filled) {
	
}

// NOTE: DO NOT use in large amounts, this is generally not an efficient way to do whatever you're doing. Look into editing the textures directly or simplifying shapes.
void rDrawPixel(rVector2 position, rColor color) {
	
}

void rBeginStep() {
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window.close();
	}
}

void rBeginDraw() {
	
}

void rEndDraw() {
	
}

rVector2 rGetMousePosition() {
	
}

void rSetMousePosition(rVector2 position) {
	
}

void rSetWindowTitle(std::string title) {
	window.setTitle(title)
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
	return rVector2{ size.x, size.y };
}

void rSetWindowSize(rVector2 size) {
	window.setSize({ size.x, size.y });
}

void rSetWindowOpacity(float opacity) {
	
}

void rSetWindowPosition(rVector2 position) {
	window.setPosition({ 10, 50 });
}

rVector2 rGetWindowPosition() {
	
}

void rShowCursor() {
	
}

void rHideCursor() {
	
}

bool rIsCursorHidden() {
	
}

bool rIsCursorOnScreen() {
	
}

void rDrawClear(rColor color) {
	
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
	
}

void rSleep(double seconds) {
	
}

int rGetRandomValue(int min, int max) {
	
}

class rInput {
public:

};
