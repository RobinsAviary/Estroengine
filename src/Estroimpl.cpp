#include "../include/Estroimpl.h"
#include "SFML/Graphics.hpp"
#include "../include/Estrovector.h"
#include "../include/Estrocolors.h"

sf::RenderWindow window;

template <typename T>
sf::Vector2<T> Vector2ToSFVector2(Estro::Vector2<T> vector) {
	return {vector.x, vector.y};
}

template <typename T>
sf::Vector3<T> Vector3ToSFVector3(Estro::Vector3<T> vector) {
	return {vector.x, vector.y, vector.z};
}

sf::Color ColorToSFColor(Estro::Color color) {
	return {color.r, color.g, color.b, color.a};
}

bool Estro::isLooping() {
	return window.isOpen();
}

void Estro::init(unsigned int width, unsigned int height, std::string title) {
	window.create(sf::VideoMode({width, height}), title, sf::Style::Close);
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

void Estro::drawLine(Vector2<float> startPosition, Vector2<float> endPosition, Color color) {
	std::array line =
	{
		sf::Vertex{Vector2ToSFVector2(startPosition)},
		sf::Vertex{Vector2ToSFVector2(endPosition)}
	};

	window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

void Estro::drawClear(Color color) {
	window.clear(ColorToSFColor(color));
}

void Estro::drawTexture(Vector2<float> position, const Texture &texture, Color color) {
	if (texture.isValid()) {
		sf::Sprite sprite(texture.data);

		sprite.setPosition(Vector2ToSFVector2(position));
		sprite.setColor(ColorToSFColor(color));

		window.draw(sprite);
	}
}