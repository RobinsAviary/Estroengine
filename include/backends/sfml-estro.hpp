#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../estrotypes.hpp"
#include <map>
#include "../estroinput.hpp"

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
	window.setKeyRepeatEnabled(false);
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

std::vector<sf::Keyboard::Key> _pressedKeys;
std::vector<sf::Keyboard::Key> _releasedKeys;

void rBeginStep() {
	while (const std::optional event = window.pollEvent())
	{
		_pressedKeys.clear();
		_releasedKeys.clear();

		// TODO: Upgrade to switch
		if (event->is<sf::Event::Closed>()) window.close();
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

std::map<rKey, sf::Keyboard::Key> _keyMap{ {Q, sf::Keyboard::Key::Q}, {W, sf::Keyboard::Key::W}, {E, sf::Keyboard::Key::E}, {R, sf::Keyboard::Key::R}, {T, sf::Keyboard::Key::T}, {Y, sf::Keyboard::Key::Y}, {U, sf::Keyboard::Key::U}, {I, sf::Keyboard::Key::I}, {O, sf::Keyboard::Key::O}, {P, sf::Keyboard::Key::P}, {A, sf::Keyboard::Key::A}, {S, sf::Keyboard::Key::S}, {D, sf::Keyboard::Key::D}, {F, sf::Keyboard::Key::F}, {G, sf::Keyboard::Key::G}, {H, sf::Keyboard::Key::H}, {J, sf::Keyboard::Key::J}, {K, sf::Keyboard::Key::K}, {L, sf::Keyboard::Key::L}, {Z, sf::Keyboard::Key::Z}, {X, sf::Keyboard::Key::X}, {C, sf::Keyboard::Key::C}, {V, sf::Keyboard::Key::V}, {B, sf::Keyboard::Key::B}, {N, sf::Keyboard::Key::N}, {M, sf::Keyboard::Key::M},
	{Space, sf::Keyboard::Key::Space}, {LeftAlt, sf::Keyboard::Key::LAlt}, {RightAlt, sf::Keyboard::Key::RAlt}, {LeftCtrl, sf::Keyboard::Key::LControl}, {RightCtrl, sf::Keyboard::Key::RControl}, {LeftShift, sf::Keyboard::Key::LShift}, {RightShift, sf::Keyboard::Key::RShift}, {Enter, sf::Keyboard::Key::Enter}, {Left, sf::Keyboard::Key::Left}, {Right, sf::Keyboard::Key::Right}, {Up, sf::Keyboard::Key::Up}, {Down, sf::Keyboard::Key::Down} };

sf::Keyboard::Key rKeyTosfKey(rKey key) {
	return _keyMap[key];
}

bool rIsKeyPressed(rKey key) {
	sf::Keyboard::Key _key = rKeyTosfKey(key);

	for (auto key : _pressedKeys) {
		for (auto& iter : _keyMap) {
			if (iter.second == _key) return true;
		}
	}

	return false;
}

bool rIsKeyHeld(rKey key) {
	return sf::Keyboard::isKeyPressed(rKeyTosfKey(key));
}

bool rIsKeyReleased(rKey key) {
	sf::Keyboard::Key _key = rKeyTosfKey(key);

	for (auto key : _releasedKeys) {
		for (auto& iter : _keyMap) {
			if (iter.second == _key) return true;
		}
	}

	return false;
}