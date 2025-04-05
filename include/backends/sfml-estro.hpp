#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../estrotypes.hpp"
#include <map>
#include "../estroinput.hpp"
#include "iostream"

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

class rCPUTexture : public rAsset {
public:
	sf::Image texture;

	rColor getPixel(rVector2<unsigned int> position) {
		return sfColorTorColor(texture.getPixel(sf::Vector2u{ position.x, position.y }));
	}

	int getWidth() {
		rVector2<unsigned int> size = getSize();

		return size.x;
	}

	int getHeight() {
		rVector2<unsigned int> size = getSize();

		return size.y;
	}

	rVector2<unsigned int> getSize() {
		sf::Vector2u _size = texture.getSize();
		return rVector2<unsigned int>{ _size.x, _size.y };
	}

	bool load(std::string filename) {
		valid = texture.loadFromFile(filename);

		return valid;
	}

	~rCPUTexture() {

	}
};

class rTexture : public rAsset {
public:
	sf::Texture texture;

	int getWidth() {
		rVector2 size = getSize();

		return size.x;
	}

	int getHeight() {
		rVector2<unsigned int> size = getSize();

		return size.y;
	}

	rVector2<unsigned int> getSize() {
		sf::Vector2u size = texture.getSize();
		return rVector2<unsigned int>{ size.x, size.y };
	}

	bool load(std::string filename) {
		valid = texture.loadFromFile(filename);

		return valid;
	}

	~rTexture() {

	}
};

class rFont : public rAsset {
public:
	sf::Font font;

	bool load(std::string filename) {
		valid = font.openFromFile(filename);

		return valid;
	}
};

void rDrawText(rFont* font, rVector2<float> position, unsigned int size, std::string text, rColor color) {
	sf::Text _text(font->font);
	_text.setString(text);
	_text.setCharacterSize(size);
	_text.setPosition({ position.x, position.y });
	_text.setFillColor(rColorTosfColor(color));

	window.draw(_text);
}

std::string rGetClipboard() {
	return sf::Clipboard::getString().toAnsiString();
}

void rSetClipboard(std::string _string) {
	sf::Clipboard::setString(sf::String(_string));
}

void rInit(rVector2<unsigned int> windowSize, std::string windowTitle, bool resizable = false) {
	int style = 0;
	if (resizable) {
		style = sf::Style::Default;
	}
	else {
		style = sf::Style::Close;
	}

	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;

	window.create(sf::VideoMode({ windowSize.x, windowSize.y }), windowTitle, style, sf::State::Windowed, settings);
	window.setKeyRepeatEnabled(false);
}

void rDeinit() {
	window.close();
}

void rDrawTexture(rTexture* texture, rVector2<float> position, rColor tint) {
	if (!texture->isValid()) return;

	sf::Sprite sprite(texture->texture);

	sprite.setPosition(sf::Vector2f{position.x, position.y});
	sprite.setColor(rColorTosfColor(tint));

	window.draw(sprite);
}

void rDrawTextureSection(rTexture* texture, rVector2<float> position, rRectangle<int> rectangle, rColor tint) {
	if (!texture->isValid()) return;

	sf::Sprite sprite(texture->texture);

	sprite.setTextureRect(sf::IntRect({ rectangle.x, rectangle.y }, { rectangle.w, rectangle.h }));
	sprite.setPosition(sf::Vector2f{ position.x, position.y });
	sprite.setColor(rColorTosfColor(tint));

	window.draw(sprite);
}

void rDrawTextureReproject(rTexture* texture, rRectangle<int> source, rRectangle<float> target, rColor tint) {
	if (!texture->isValid()) return;

	sf::Sprite sprite(texture->texture);

	sprite.setTextureRect(sf::IntRect({ source.x, source.y }, { source.w, source.h }));

	sf::Vector2f scale = sf::Vector2f{ target.x / source.x, target.y / source.y };
	sprite.setScale(scale);

	window.draw(sprite);
}

void rDrawLine(rVector2<float> pos1, rVector2<float> pos2, rColor color) {
	sf::Color _color = rColorTosfColor(color);

	std::array line =
	{
		sf::Vertex{sf::Vector2f(pos1.x, pos1.y), _color},
		sf::Vertex{sf::Vector2f(pos2.x, pos2.y), _color}
	};

	window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

void rDrawRectangle(rRectangle<float> rectangle, rColor color, bool filled) {
	sf::Color _color = rColorTosfColor(color);

	sf::RectangleShape shape({ rectangle.w, rectangle.h });
	shape.setPosition(sf::Vector2f{ rectangle.x, rectangle.y });
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

void rDrawCircle(rVector2<float> position, float radius, rColor color, bool filled) {
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
void rDrawPixel(rVector2<unsigned int> position, rColor color) {
	rDrawRectangle(rRectangle<float>{ static_cast<float>(position.x), static_cast<float>(position.y), 1, 1 }, color, true);
}

std::vector<sf::Keyboard::Key> _pressedKeys;
std::vector<sf::Keyboard::Key> _releasedKeys;

void rBeginStep() {
	while (const std::optional event = window.pollEvent())
	{
		_pressedKeys.clear();
		_releasedKeys.clear();

		// Poll close button
		if (event->is<sf::Event::Closed>()) window.close();

		// Poll keyboard
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			_pressedKeys.push_back(keyPressed->code);
		}

		else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
			_releasedKeys.push_back(keyReleased->code);
		}
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

rVector2<int> rGetMousePosition() {
	sf::Vector2i pos = sf::Mouse::getPosition(window);

	return rVector2<int>{ pos.x, pos.y };
}

void rSetMousePosition(rVector2<int> position) {
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

rVector2<unsigned int> rGetWindowSize() {
	sf::Vector2u size = window.getSize();
	return rVector2<unsigned int>{ static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y) };
}

void rSetWindowSize(rVector2<unsigned int> size) {
	window.setSize({ static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y) });
}

void rSetWindowOpacity(float opacity) {
	//rPrint("rSetWindowOpacity is not supported on this backend!");
}

void rSetWindowPosition(rVector2<int> position) {
	window.setPosition({ 10, 50 });
}

rVector2<int> rGetWindowPosition() {
	sf::Vector2i pos = window.getPosition();

	return rVector2<int>{ pos.x, pos.y };
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

rVector2<int> rGetCursorPosition() {
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	return rVector2<int>{pos.x, pos.y};
}

bool rIsCursorOnScreen() {
	// Get cursor position relative to window
	rVector2<int> position = rGetCursorPosition();

	if (position.x >= 0 && position.y >= 0) {
		if (position.x < static_cast<int>(rGetWindowWidth()) && position.y < static_cast<int>(rGetWindowHeight())) {
			return true;
		}
	}

	return false;
}

void rSetCursorPosition(rVector2<int> position) {
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

void rSleep(float seconds) {
	sf::sleep(sf::seconds(seconds));
}

// TODO: Upgrade this to use std members
int rGetRandomValue(int min, int max) {
	return min + (rand() % (max + 1));
}

std::map<rKeys::Key, sf::Keyboard::Key> _keyMap{ {rKeys::Q, sf::Keyboard::Key::Q}, {rKeys::W, sf::Keyboard::Key::W}, {rKeys::E, sf::Keyboard::Key::E}, {rKeys::R, sf::Keyboard::Key::R}, {rKeys::T, sf::Keyboard::Key::T}, {rKeys::Y, sf::Keyboard::Key::Y}, {rKeys::U, sf::Keyboard::Key::U}, {rKeys::I, sf::Keyboard::Key::I}, {rKeys::O, sf::Keyboard::Key::O}, {rKeys::P, sf::Keyboard::Key::P}, {rKeys::A, sf::Keyboard::Key::A}, {rKeys::S, sf::Keyboard::Key::S}, {rKeys::D, sf::Keyboard::Key::D}, {rKeys::F, sf::Keyboard::Key::F}, {rKeys::G, sf::Keyboard::Key::G}, {rKeys::H, sf::Keyboard::Key::H}, {rKeys::J, sf::Keyboard::Key::J}, {rKeys::K, sf::Keyboard::Key::K}, {rKeys::L, sf::Keyboard::Key::L}, {rKeys::Z, sf::Keyboard::Key::Z}, {rKeys::X, sf::Keyboard::Key::X}, {rKeys::C, sf::Keyboard::Key::C}, {rKeys::V, sf::Keyboard::Key::V}, {rKeys::B, sf::Keyboard::Key::B}, {rKeys::N, sf::Keyboard::Key::N}, {rKeys::M, sf::Keyboard::Key::M},
	{rKeys::Space, sf::Keyboard::Key::Space}, {rKeys::LeftAlt, sf::Keyboard::Key::LAlt}, {rKeys::RightAlt, sf::Keyboard::Key::RAlt}, {rKeys::LeftCtrl, sf::Keyboard::Key::LControl}, {rKeys::RightCtrl, sf::Keyboard::Key::RControl}, {rKeys::LeftShift, sf::Keyboard::Key::LShift}, {rKeys::RightShift, sf::Keyboard::Key::RShift}, {rKeys::Enter, sf::Keyboard::Key::Enter}, {rKeys::Left, sf::Keyboard::Key::Left}, {rKeys::Right, sf::Keyboard::Key::Right}, {rKeys::Up, sf::Keyboard::Key::Up}, {rKeys::Down, sf::Keyboard::Key::Down} };

sf::Keyboard::Key rKeyTosfKey(rKeys::Key key) {
	return _keyMap[key];
}

bool rIsKeyPressed(rKeys::Key key) {
	sf::Keyboard::Key _key = rKeyTosfKey(key);

	for (auto key : _pressedKeys) {
		for (auto& iter : _keyMap) {
			if (iter.second == _key) return true;
		}
	}

	return false;
}

bool rIsKeyHeld(rKeys::Key key) {
	return sf::Keyboard::isKeyPressed(rKeyTosfKey(key));
}

bool rIsKeyReleased(rKeys::Key key) {
	sf::Keyboard::Key _key = rKeyTosfKey(key);

	for (auto key : _releasedKeys) {
		for (auto& iter : _keyMap) {
			if (iter.second == _key) return true;
		}
	}

	return false;
}

std::string rGetWorkingDirectory() {
	// TODO: Impl.
	return "";
}

bool rIsControllerConnected(unsigned int index) {
	return sf::Joystick::isConnected(index);
}

float _deadzone = 0.125;

void rSetControllerDeadzone(float deadzone) {
	_deadzone = deadzone;
}

float rGetControllerDeadzone() {
	return _deadzone;
}

float _rGetAxisDeadzone(unsigned int index, sf::Joystick::Axis axis) {
	float pos = sf::Joystick::getAxisPosition(index, axis) / 100;
	if (abs(pos) > _deadzone) {
		return pos;
	}
	else return 0.0f;
}

// Basically a custom implementation in sfml lol
rVector2<float> rGetJoystickPosition(unsigned int index, rJoysticks::Joystick stick) {
	switch (stick) {
		case rJoysticks::Left:
			return rVector2<float>{_rGetAxisDeadzone(index, sf::Joystick::Axis::X), _rGetAxisDeadzone(index, sf::Joystick::Axis::Y)};
		break;
		case rJoysticks::Right:
			return rVector2<float>{_rGetAxisDeadzone(index, sf::Joystick::Axis::U), _rGetAxisDeadzone(index, sf::Joystick::Axis::R)};
		break;
	}
}

bool rGetButtonPressed(unsigned int index, rButtons::Button button) {
	return false;
}

bool rGetButtonHeld(unsigned int index, rButtons::Button button) {
	switch (button) {
	case rButtons::A:
		return sf::Joystick::isButtonPressed(index, 0);
		break;
	case rButtons::B:
		return sf::Joystick::isButtonPressed(index, 1);
		break;
	case rButtons::X:
		return sf::Joystick::isButtonPressed(index, 2);
		break;
	case rButtons::Y:
		return sf::Joystick::isButtonPressed(index, 3);
		break;
	case rButtons::LeftShoulder:
		return sf::Joystick::isButtonPressed(index, 4);
		break;
	case rButtons::RightShoulder:
		return sf::Joystick::isButtonPressed(index, 5);
		break;
	case rButtons::Select:
		return sf::Joystick::isButtonPressed(index, 6);
		break;
	case rButtons::Start:
		return sf::Joystick::isButtonPressed(index, 7);
		break;
	case rButtons::LeftStick:
		return sf::Joystick::isButtonPressed(index, 8);
		break;
	case rButtons::RightStick:
		return sf::Joystick::isButtonPressed(index, 9);
		break;

		// Not a perfect implementation, xInput would be better but that's platform-specific.
	case rButtons::Left:
		return (sf::Joystick::getAxisPosition(index, sf::Joystick::Axis::PovX) < 0);
		break;
	case rButtons::Right:
		return (sf::Joystick::getAxisPosition(index, sf::Joystick::Axis::PovX) > 0);
		break;
	case rButtons::Up:
		return (sf::Joystick::getAxisPosition(index, sf::Joystick::Axis::PovY) < 0);
		break;
	case rButtons::Down:
		return (sf::Joystick::getAxisPosition(index, sf::Joystick::Axis::PovY) > 0);
		break;

	default:
		return false;
		break;
	}
}

bool rGetButtonReleased(rButtons::Button button) {
	return false;
}