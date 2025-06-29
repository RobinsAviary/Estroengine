#include "../../../include/Estroimpl.h"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../../../include/Estrotypes.h"
#include "../../../include/Estrocolors.h"
#include "../../../include/Estroinput.h"
#include "../../../include/Estrolist.h"
#include <map>

sf::RenderWindow window;
sf::RenderTarget* target = &window;

Estro::List<sf::Keyboard::Key> pressedKeys;
Estro::List<sf::Keyboard::Key> releasedKeys;

sf::Keyboard::Key KeyToSFKey(const Estro::Keys::Key key) {
    std::map<Estro::Keys::Key, sf::Keyboard::Key> map {
        {Estro::Keys::A, sf::Keyboard::Key::A},
        {Estro::Keys::Apostrophe, sf::Keyboard::Key::Apostrophe},
        {Estro::Keys::B, sf::Keyboard::Key::B},
        {Estro::Keys::Backslash, sf::Keyboard::Key::Backslash},
        {Estro::Keys::C, sf::Keyboard::Key::C},
        {Estro::Keys::D, sf::Keyboard::Key::D},
        {Estro::Keys::Delete, sf::Keyboard::Key::Delete},
        {Estro::Keys::Down, sf::Keyboard::Key::Down},
        {Estro::Keys::E, sf::Keyboard::Key::E},
        {Estro::Keys::Eight, sf::Keyboard::Key::Num8},
        {Estro::Keys::End, sf::Keyboard::Key::End},
        {Estro::Keys::Enter, sf::Keyboard::Key::Enter},
        {Estro::Keys::Escape, sf::Keyboard::Key::Escape},
        {Estro::Keys::F, sf::Keyboard::Key::F},
        {Estro::Keys::F1, sf::Keyboard::Key::F1},
        {Estro::Keys::F2, sf::Keyboard::Key::F2},
        {Estro::Keys::F3, sf::Keyboard::Key::F3},
        {Estro::Keys::F4, sf::Keyboard::Key::F4},
        {Estro::Keys::F5, sf::Keyboard::Key::F5},
        {Estro::Keys::F6, sf::Keyboard::Key::F6},
        {Estro::Keys::F7, sf::Keyboard::Key::F7},
        {Estro::Keys::F8, sf::Keyboard::Key::F8},
        {Estro::Keys::F9, sf::Keyboard::Key::F9},
        {Estro::Keys::F10, sf::Keyboard::Key::F10},
        {Estro::Keys::F11, sf::Keyboard::Key::F11},
        {Estro::Keys::F12, sf::Keyboard::Key::F12},
        {Estro::Keys::Five, sf::Keyboard::Key::Num5},
        {Estro::Keys::Four, sf::Keyboard::Key::Num4},
        {Estro::Keys::G, sf::Keyboard::Key::G},
        {Estro::Keys::Grave, sf::Keyboard::Key::Grave},
        {Estro::Keys::H, sf::Keyboard::Key::H},
        {Estro::Keys::Home, sf::Keyboard::Key::Home},
        {Estro::Keys::I, sf::Keyboard::Key::I},
        {Estro::Keys::Insert, sf::Keyboard::Key::Insert},
        {Estro::Keys::J, sf::Keyboard::Key::J},
        {Estro::Keys::K, sf::Keyboard::Key::K},
        {Estro::Keys::L, sf::Keyboard::Key::L},
        {Estro::Keys::Left, sf::Keyboard::Key::Left},
        {Estro::Keys::LeftAlt, sf::Keyboard::Key::LAlt},
        {Estro::Keys::LeftCtrl, sf::Keyboard::Key::LControl},
        {Estro::Keys::LeftShift, sf::Keyboard::Key::LShift},
        {Estro::Keys::M, sf::Keyboard::Key::M},
        {Estro::Keys::N, sf::Keyboard::Key::N},
        {Estro::Keys::Nine, sf::Keyboard::Key::Num9},
        {Estro::Keys::NumAdd, sf::Keyboard::Key::Add},
        {Estro::Keys::NumDivide, sf::Keyboard::Key::Divide},
        {Estro::Keys::NumEight, sf::Keyboard::Key::Numpad8},
        {Estro::Keys::NumFive, sf::Keyboard::Key::Numpad5},
        {Estro::Keys::NumFour, sf::Keyboard::Key::Numpad4},
        {Estro::Keys::NumMultiply, sf::Keyboard::Key::Multiply},
        {Estro::Keys::NumNine, sf::Keyboard::Key::Numpad9},
        {Estro::Keys::NumOne, sf::Keyboard::Key::Numpad1},
        {Estro::Keys::NumSeven, sf::Keyboard::Key::Numpad7},
        {Estro::Keys::NumSix, sf::Keyboard::Key::Numpad6},
        {Estro::Keys::NumSubtract, sf::Keyboard::Key::Subtract},
        {Estro::Keys::NumThree, sf::Keyboard::Key::Numpad3},
        {Estro::Keys::NumTwo, sf::Keyboard::Key::Numpad2},
        {Estro::Keys::NumZero, sf::Keyboard::Key::Numpad0},
        {Estro::Keys::O, sf::Keyboard::Key::O},
        {Estro::Keys::One, sf::Keyboard::Key::Num1},
        {Estro::Keys::OpenBracket, sf::Keyboard::Key::LBracket},
        {Estro::Keys::P, sf::Keyboard::Key::P},
        {Estro::Keys::PageDown, sf::Keyboard::Key::PageDown},
        {Estro::Keys::PageUp, sf::Keyboard::Key::PageUp},
        {Estro::Keys::Q, sf::Keyboard::Key::Q},
        {Estro::Keys::R, sf::Keyboard::Key::R},
        {Estro::Keys::Right, sf::Keyboard::Key::Right},
        {Estro::Keys::RightAlt, sf::Keyboard::Key::RAlt},
        {Estro::Keys::RightCtrl, sf::Keyboard::Key::RControl},
        {Estro::Keys::RightShift, sf::Keyboard::Key::RShift},
        {Estro::Keys::S, sf::Keyboard::Key::S},
        {Estro::Keys::Seven, sf::Keyboard::Key::Num7},
        {Estro::Keys::Six, sf::Keyboard::Key::Num6},
        {Estro::Keys::Slash, sf::Keyboard::Key::Slash},
        {Estro::Keys::Space, sf::Keyboard::Key::Space},
        {Estro::Keys::T, sf::Keyboard::Key::T},
        {Estro::Keys::Tab, sf::Keyboard::Key::Tab},
        {Estro::Keys::Three, sf::Keyboard::Key::Num3},
        {Estro::Keys::Two, sf::Keyboard::Key::Num2},
        {Estro::Keys::U, sf::Keyboard::Key::U},
        {Estro::Keys::Up, sf::Keyboard::Key::Up},
        {Estro::Keys::V, sf::Keyboard::Key::V},
        {Estro::Keys::W, sf::Keyboard::Key::W},
        {Estro::Keys::X, sf::Keyboard::Key::X},
        {Estro::Keys::Y, sf::Keyboard::Key::Y},
        {Estro::Keys::Z, sf::Keyboard::Key::Z},
        {Estro::Keys::Zero, sf::Keyboard::Key::Num0},
    };

    if (map.contains(key)) {
        return map[key];
    }

    return sf::Keyboard::Key::Unknown; // Failsafe
}

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

	window.setKeyRepeatEnabled(false);
}

void Estro::beginStep() {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}

		if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			pressedKeys.add(keyPressed->code);
		}

		if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
			releasedKeys.add(keyReleased->code);
		}
	}
}

void Estro::endStep() {

}

void Estro::beginDraw() {

}

void Estro::endDraw() {
	window.display();
	pressedKeys.clear();
	releasedKeys.clear();
}


void Estro::drawLine(Vector2<float> startPosition, Vector2<float> endPosition, Color color) {
	std::array line =
	{
		sf::Vertex{Vector2ToSFVector2(startPosition)},
		sf::Vertex{Vector2ToSFVector2(endPosition)}
	};

	target->draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

void Estro::drawClear(Color color) {
	window.clear(ColorToSFColor(color));
}

void Estro::drawTexture(const Texture &texture, Vector2<float> position, Color tint) {
	if (!texture.isValid()) return;

	sf::Sprite sprite(texture.data);

	sprite.setPosition(Vector2ToSFVector2(position));
	sprite.setColor(ColorToSFColor(tint));

	target->draw(sprite);
}

void Estro::drawTextureSection(const Texture &texture, Vector2<float> position, Rectangle<int> section, Color tint) {
	if (!texture.isValid()) return;

	sf::Sprite sprite(texture.data);

	sprite.setPosition(Vector2ToSFVector2(position));
	sprite.setColor(ColorToSFColor(tint));
	sprite.setTextureRect({{section.position.x, section.position.y},  {section.size.x, section.size.y}});

	target->draw(sprite);
}

void Estro::drawTextureReproject(const Texture &texture, Vector2<float>position, Rectangle<int> source, Rectangle<float> targetProjection, Color tint) {
	if (!texture.isValid()) return;

	sf::Sprite sprite(texture.data);

	sprite.setTextureRect({{source.position.x, source.position.y}, {source.size.x, source.size.y}});

	sf::Vector2f scale = {targetProjection.position.x / static_cast<float>(source.position.x), targetProjection.position.y / static_cast<float>(source.position.y)};
	sprite.setScale(scale);

	target->draw(sprite);
}

bool Estro::isKeyDown(const Keys::Key key) {
	sf::Keyboard::Key _key = KeyToSFKey(key);

	if (_key != sf::Keyboard::Key::Unknown) {
		return sf::Keyboard::isKeyPressed(_key);
	}

	return false;
}

bool Estro::isKeyPressed(const Keys::Key key) {
	sf::Keyboard::Key _key = KeyToSFKey(key);

	if (_key != sf::Keyboard::Key::Unknown) {
		return pressedKeys.has(_key);
	}

	return false;
}

bool Estro::isKeyReleased(const Keys::Key key) {
	sf::Keyboard::Key _key = KeyToSFKey(key);

	if (_key != sf::Keyboard::Key::Unknown) {
		return releasedKeys.has(_key);
	}

	return false;
}

Vector2<int> getCursorPosition() {
	sf::Vector2i cursorPosition = sf::Mouse::getPosition();
	return {cursorPosition.x, cursorPosition.y};
}

void setCursorPosition(Vector2<int> position) {
	sf::Mouse::setPosition({position.x, position.y});
}

void playSound(const Sound& sound) {
	sf::Sound _sound(sound.data);
	_sound.play();
}

void Sprite2D::step() {

}


void Sprite2D::draw() {
	drawTexture(texture, position, Colors::White);
}

void Sprite2D::setTint(const Color color) {
	sprite.setColor(ColorToSFColor(color));
}

Color Sprite2D::getTint() {
	sf::Color color = sprite.getColor();
	return {color.r, color.g, color.b, color.a};
}