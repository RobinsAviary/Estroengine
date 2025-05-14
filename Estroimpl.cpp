#include "Estroimpl.h"
#include "SFML/Graphics.hpp"

sf::RenderWindow window;

bool Estro::isLooping() {
	return window.isOpen();
}

void Estro::init(unsigned int width, unsigned int height, std::string title) {
	window.create(sf::VideoMode({width, height}), title);
}

void Estro::beginStep() {

}

void Estro::endStep() {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}
	}
}

void Estro::beginDraw() {

}

void Estro::endDraw() {
	window.display();
}

void Estro::drawRectangle(float x, float y, float w, float h) {
	sf::RectangleShape rectangle;

	rectangle.setPosition({x, y});
	rectangle.setSize({w, h});
	rectangle.setFillColor({255, 255, 255, 255});

	window.draw(rectangle);
}