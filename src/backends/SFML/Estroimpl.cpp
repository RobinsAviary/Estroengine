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

sf::Keyboard::Key KeyToSFKey(const Estro::Input::Keyboard::Keys::Key key) {
    std::map<Estro::Input::Keyboard::Keys::Key, sf::Keyboard::Key> map {
        {Estro::Input::Keyboard::Keys::A, sf::Keyboard::Key::A},
        {Estro::Input::Keyboard::Keys::Apostrophe, sf::Keyboard::Key::Apostrophe},
        {Estro::Input::Keyboard::Keys::B, sf::Keyboard::Key::B},
        {Estro::Input::Keyboard::Keys::Backslash, sf::Keyboard::Key::Backslash},
        {Estro::Input::Keyboard::Keys::C, sf::Keyboard::Key::C},
        {Estro::Input::Keyboard::Keys::D, sf::Keyboard::Key::D},
        {Estro::Input::Keyboard::Keys::Delete, sf::Keyboard::Key::Delete},
        {Estro::Input::Keyboard::Keys::Down, sf::Keyboard::Key::Down},
        {Estro::Input::Keyboard::Keys::E, sf::Keyboard::Key::E},
        {Estro::Input::Keyboard::Keys::Eight, sf::Keyboard::Key::Num8},
        {Estro::Input::Keyboard::Keys::End, sf::Keyboard::Key::End},
        {Estro::Input::Keyboard::Keys::Enter, sf::Keyboard::Key::Enter},
        {Estro::Input::Keyboard::Keys::Escape, sf::Keyboard::Key::Escape},
        {Estro::Input::Keyboard::Keys::F, sf::Keyboard::Key::F},
        {Estro::Input::Keyboard::Keys::F1, sf::Keyboard::Key::F1},
        {Estro::Input::Keyboard::Keys::F2, sf::Keyboard::Key::F2},
        {Estro::Input::Keyboard::Keys::F3, sf::Keyboard::Key::F3},
        {Estro::Input::Keyboard::Keys::F4, sf::Keyboard::Key::F4},
        {Estro::Input::Keyboard::Keys::F5, sf::Keyboard::Key::F5},
        {Estro::Input::Keyboard::Keys::F6, sf::Keyboard::Key::F6},
        {Estro::Input::Keyboard::Keys::F7, sf::Keyboard::Key::F7},
        {Estro::Input::Keyboard::Keys::F8, sf::Keyboard::Key::F8},
        {Estro::Input::Keyboard::Keys::F9, sf::Keyboard::Key::F9},
        {Estro::Input::Keyboard::Keys::F10, sf::Keyboard::Key::F10},
        {Estro::Input::Keyboard::Keys::F11, sf::Keyboard::Key::F11},
        {Estro::Input::Keyboard::Keys::F12, sf::Keyboard::Key::F12},
        {Estro::Input::Keyboard::Keys::Five, sf::Keyboard::Key::Num5},
        {Estro::Input::Keyboard::Keys::Four, sf::Keyboard::Key::Num4},
        {Estro::Input::Keyboard::Keys::G, sf::Keyboard::Key::G},
        {Estro::Input::Keyboard::Keys::Grave, sf::Keyboard::Key::Grave},
        {Estro::Input::Keyboard::Keys::H, sf::Keyboard::Key::H},
        {Estro::Input::Keyboard::Keys::Home, sf::Keyboard::Key::Home},
        {Estro::Input::Keyboard::Keys::I, sf::Keyboard::Key::I},
        {Estro::Input::Keyboard::Keys::Insert, sf::Keyboard::Key::Insert},
        {Estro::Input::Keyboard::Keys::J, sf::Keyboard::Key::J},
        {Estro::Input::Keyboard::Keys::K, sf::Keyboard::Key::K},
        {Estro::Input::Keyboard::Keys::L, sf::Keyboard::Key::L},
        {Estro::Input::Keyboard::Keys::Left, sf::Keyboard::Key::Left},
        {Estro::Input::Keyboard::Keys::LeftAlt, sf::Keyboard::Key::LAlt},
        {Estro::Input::Keyboard::Keys::LeftCtrl, sf::Keyboard::Key::LControl},
        {Estro::Input::Keyboard::Keys::LeftShift, sf::Keyboard::Key::LShift},
        {Estro::Input::Keyboard::Keys::M, sf::Keyboard::Key::M},
        {Estro::Input::Keyboard::Keys::N, sf::Keyboard::Key::N},
        {Estro::Input::Keyboard::Keys::Nine, sf::Keyboard::Key::Num9},
        {Estro::Input::Keyboard::Keys::NumAdd, sf::Keyboard::Key::Add},
        {Estro::Input::Keyboard::Keys::NumDivide, sf::Keyboard::Key::Divide},
        {Estro::Input::Keyboard::Keys::NumEight, sf::Keyboard::Key::Numpad8},
        {Estro::Input::Keyboard::Keys::NumFive, sf::Keyboard::Key::Numpad5},
        {Estro::Input::Keyboard::Keys::NumFour, sf::Keyboard::Key::Numpad4},
        {Estro::Input::Keyboard::Keys::NumMultiply, sf::Keyboard::Key::Multiply},
        {Estro::Input::Keyboard::Keys::NumNine, sf::Keyboard::Key::Numpad9},
        {Estro::Input::Keyboard::Keys::NumOne, sf::Keyboard::Key::Numpad1},
        {Estro::Input::Keyboard::Keys::NumSeven, sf::Keyboard::Key::Numpad7},
        {Estro::Input::Keyboard::Keys::NumSix, sf::Keyboard::Key::Numpad6},
        {Estro::Input::Keyboard::Keys::NumSubtract, sf::Keyboard::Key::Subtract},
        {Estro::Input::Keyboard::Keys::NumThree, sf::Keyboard::Key::Numpad3},
        {Estro::Input::Keyboard::Keys::NumTwo, sf::Keyboard::Key::Numpad2},
        {Estro::Input::Keyboard::Keys::NumZero, sf::Keyboard::Key::Numpad0},
        {Estro::Input::Keyboard::Keys::O, sf::Keyboard::Key::O},
        {Estro::Input::Keyboard::Keys::One, sf::Keyboard::Key::Num1},
        {Estro::Input::Keyboard::Keys::OpenBracket, sf::Keyboard::Key::LBracket},
        {Estro::Input::Keyboard::Keys::P, sf::Keyboard::Key::P},
        {Estro::Input::Keyboard::Keys::PageDown, sf::Keyboard::Key::PageDown},
        {Estro::Input::Keyboard::Keys::PageUp, sf::Keyboard::Key::PageUp},
        {Estro::Input::Keyboard::Keys::Q, sf::Keyboard::Key::Q},
        {Estro::Input::Keyboard::Keys::R, sf::Keyboard::Key::R},
        {Estro::Input::Keyboard::Keys::Right, sf::Keyboard::Key::Right},
        {Estro::Input::Keyboard::Keys::RightAlt, sf::Keyboard::Key::RAlt},
        {Estro::Input::Keyboard::Keys::RightCtrl, sf::Keyboard::Key::RControl},
        {Estro::Input::Keyboard::Keys::RightShift, sf::Keyboard::Key::RShift},
        {Estro::Input::Keyboard::Keys::S, sf::Keyboard::Key::S},
        {Estro::Input::Keyboard::Keys::Seven, sf::Keyboard::Key::Num7},
        {Estro::Input::Keyboard::Keys::Six, sf::Keyboard::Key::Num6},
        {Estro::Input::Keyboard::Keys::Slash, sf::Keyboard::Key::Slash},
        {Estro::Input::Keyboard::Keys::Space, sf::Keyboard::Key::Space},
        {Estro::Input::Keyboard::Keys::T, sf::Keyboard::Key::T},
        {Estro::Input::Keyboard::Keys::Tab, sf::Keyboard::Key::Tab},
        {Estro::Input::Keyboard::Keys::Three, sf::Keyboard::Key::Num3},
        {Estro::Input::Keyboard::Keys::Two, sf::Keyboard::Key::Num2},
        {Estro::Input::Keyboard::Keys::U, sf::Keyboard::Key::U},
        {Estro::Input::Keyboard::Keys::Up, sf::Keyboard::Key::Up},
        {Estro::Input::Keyboard::Keys::V, sf::Keyboard::Key::V},
        {Estro::Input::Keyboard::Keys::W, sf::Keyboard::Key::W},
        {Estro::Input::Keyboard::Keys::X, sf::Keyboard::Key::X},
        {Estro::Input::Keyboard::Keys::Y, sf::Keyboard::Key::Y},
        {Estro::Input::Keyboard::Keys::Z, sf::Keyboard::Key::Z},
        {Estro::Input::Keyboard::Keys::Zero, sf::Keyboard::Key::Num0},
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


void Estro::Graphics::drawLine(Vector2<float> startPosition, Vector2<float> endPosition, Color color) {
	std::array line =
	{
		sf::Vertex{Vector2ToSFVector2(startPosition)},
		sf::Vertex{Vector2ToSFVector2(endPosition)}
	};

	target->draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

void Estro::Graphics::drawClear(Color color) {
	window.clear(ColorToSFColor(color));
}

void Estro::Graphics::drawTexture(const Texture &texture, Vector2<float> position, Color tint) {
	if (!texture.isValid()) return;

	sf::Sprite sprite(texture.data);

	sprite.setPosition(Vector2ToSFVector2(position));
	sprite.setColor(ColorToSFColor(tint));

	target->draw(sprite);
}

void Estro::Graphics::drawTextureSection(const Texture &texture, Vector2<float> position, Rectangle<int> section, Color tint) {
	if (!texture.isValid()) return;

	sf::Sprite sprite(texture.data);

	sprite.setPosition(Vector2ToSFVector2(position));
	sprite.setColor(ColorToSFColor(tint));
	sprite.setTextureRect({{section.position.x, section.position.y},  {section.size.x, section.size.y}});

	target->draw(sprite);
}

void Estro::Graphics::drawTextureReproject(const Texture &texture, Vector2<float>position, Rectangle<int> source, Rectangle<float> targetProjection, Color tint) {
	if (!texture.isValid()) return;

	sf::Sprite sprite(texture.data);

	sprite.setTextureRect({{source.position.x, source.position.y}, {source.size.x, source.size.y}});

	sf::Vector2f scale = {targetProjection.position.x / static_cast<float>(source.position.x), targetProjection.position.y / static_cast<float>(source.position.y)};
	sprite.setScale(scale);

	target->draw(sprite);
}

bool Estro::Input::isKeyDown(const Input::Keyboard::Keys::Key key) {
	sf::Keyboard::Key _key = KeyToSFKey(key);

	if (_key != sf::Keyboard::Key::Unknown) {
		return sf::Keyboard::isKeyPressed(_key);
	}

	return false;
}

bool Estro::Input::isKeyPressed(const Input::Keyboard::Keys::Key key) {
	sf::Keyboard::Key _key = KeyToSFKey(key);

	if (_key != sf::Keyboard::Key::Unknown) {
		return pressedKeys.has(_key);
	}

	return false;
}

bool Estro::Input::isKeyReleased(const Input::Keyboard::Keys::Key key) {
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