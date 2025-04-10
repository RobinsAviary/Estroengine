#pragma once

#include "raylib.h"
#include "../estrotypes.hpp"
#include "../estroinput.hpp"
#include <string>
#include <map>
#include <iostream>

std::string rGetBackendName() {
	return "raylib";
}

Color rColorToColor(rColor color) {
	return Color{ color.r, color.g, color.b, color.a };
}

rColor ColorTorColor(Color color) {
	return rColor{ color.r, color.g, color.b, color.a };
}

template <typename T>
Vector2 rVector2ToVector2(rVector2<T> vector) {
	return Vector2{ static_cast<float>(vector.x), static_cast<float>(vector.y) };
}

template <typename T>
rVector2<T> Vector2TorVector2(Vector2 vector) {
	return rVector2<T>{ static_cast<T>(vector.x), static_cast<T>(vector.y) };
}

template <typename T>
Rectangle rRectangleToRectangle(rRectangle<T> rectangle) {
	return Rectangle{ static_cast<float>(rectangle.x), static_cast<float>(rectangle.y), static_cast<float>(rectangle.w), static_cast<float>(rectangle.h) };
}

class rCPUTexture : public rAsset {
	public:
		Image texture = { 0 };

		rColor getPixel(rVector2<unsigned int> position) {
			return ColorTorColor(GetImageColor(texture, position.x, position.y));
		}

		int getWidth() {
			return texture.width;
		}

		int getHeight() {
			return texture.height;
		}

		bool load(std::string filename) {
			if (IsImageValid(texture)) {
				UnloadImage(texture);
			}
			
			texture = LoadImage(filename.c_str());
			valid = IsImageValid(texture);

			return valid;
		}

		~rCPUTexture() {
			UnloadImage(texture);
			valid = false;
		}
};

class rTexture : public rAsset {
	public:
		Texture2D texture = { 0 };

		int getWidth() {
			return texture.width;
		}

		int getHeight() {
			return texture.height;
		}

		rVector2<unsigned int> getSize() {
			return rVector2<unsigned int>{ getWidth(), getHeight() };
		}

		bool load(std::string filename) {
			if (IsTextureValid(texture)) {
				UnloadTexture(texture);
			}
			texture = LoadTexture(filename.c_str());

			valid = IsTextureValid(texture);

			return valid;
		}

		~rTexture() {
			UnloadTexture(texture);
		}
};

class rAudio : public rAsset {
	public:
		Sound audio;

		bool load(std::string filename) {
			if (IsSoundValid(audio)) {
				UnloadSound(audio);
			}
			audio = LoadSound(filename.c_str());

			valid = IsSoundValid(audio);

			return valid;
		}

		~rAudio() {
			UnloadSound(audio);
		}

		void play() {
			PlaySound(audio);
		}

		void pause() {
			PauseSound(audio);
		}

		void stop() {
			StopSound(audio);
		}
};

std::string rGetClipboard() {
	return GetClipboardText();
}

void rSetClipboard(std::string _string) {
	SetClipboardText(_string.c_str());
}

void rInit(int windowWidth, int windowHeight, std::string windowTitle) {
	InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

void rDeinit() {
	CloseWindow();
}

void rDrawTexture(rTexture* texture, rVector2<float> position, rColor tint) {
	if (!texture->isValid()) return;
	DrawTexture(texture->texture, position.x, position.y, rColorToColor(tint));
}

void rDrawTextureSection(rTexture* texture, rVector2<float> position, rRectangle<int> rectangle, rColor tint) {
	if (!texture->isValid()) return;
	DrawTextureRec(texture->texture, rRectangleToRectangle(rectangle), rVector2ToVector2(position), rColorToColor(tint));
}

void rDrawTextureReproject(rTexture* texture, rRectangle<unsigned int> source, rRectangle<int> target, rColor tint) {
	if (!texture->isValid()) return;
	DrawTexturePro(texture->texture, rRectangleToRectangle(source), rRectangleToRectangle(target), Vector2{ 0, 0 }, 0, rColorToColor(tint));
}

void rDrawLine(rVector2<float> pos1, rVector2<float> pos2, rColor color) {
	DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, rColorToColor(color));
}

void rDrawRectangle(rRectangle<float> rectangle, rColor color, bool filled) {
	if (filled) {
		DrawRectangle(rectangle.x, rectangle.y, rectangle.w, rectangle.h, rColorToColor(color));
	}
	else {
		DrawRectangleLines(rectangle.x, rectangle.y, rectangle.w, rectangle.h, rColorToColor(color));
	}
}

void rDrawCircle(rVector2<float> position, float radius, rColor color, bool filled) {
	if (filled) {
		DrawCircle(position.x, position.y, radius, rColorToColor(color));
	}
	else {
		DrawCircleLines(position.x, position.y, radius, rColorToColor(color));
	}
}

// NOTE: DO NOT use in large amounts, this is generally not an efficient way to do whatever you're doing. Look into editing the textures directly or simplifying shapes.
void rDrawPixel(rVector2<unsigned int> position, rColor color) {
	DrawPixel(position.x, position.y, rColorToColor(color));
}

void rBeginStep() {
	
}

void rEndStep() {

}

void rBeginDraw() {
	BeginDrawing();
}

void rEndDraw() {
	EndDrawing();
}

rVector2<unsigned int> rGetMousePosition() {
	return rVector2<unsigned int>{ GetMouseX(), GetMouseY() };
}

void rSetMousePosition(rVector2<unsigned int> position) {
	SetMousePosition(position.x, position.y);
}

void rSetWindowTitle(std::string title) {
	SetWindowTitle(title.c_str());
}

int rGetWindowWidth() {
	return GetScreenWidth();
}

int rGetWindowHeight() {
	return GetScreenHeight();
}

rVector2<unsigned int> rGetWindowSize() {
	return rVector2<unsigned int>{ rGetWindowWidth(), rGetWindowHeight() };
}

void rSetWindowSize(rVector2<unsigned int> size) {
	SetWindowSize(size.x, size.y);
}

void rSetWindowOpacity(float opacity) {
	SetWindowOpacity(opacity);
}

void rSetWindowPosition(rVector2<int> position) {
	SetWindowPosition(position.x, position.y);
}

rVector2<int> rGetWindowPosition() {
	Vector2 position = GetWindowPosition();

	return rVector2<int>{ static_cast<int>(position.x), static_cast<int>(position.y) };
}

void rShowCursor() {
	ShowCursor();
}

void rHideCursor() {
	HideCursor();
}

bool rIsCursorHidden() {
	return IsCursorHidden();
}

bool rIsCursorOnScreen() {
	return IsCursorOnScreen();
}

rVector2<unsigned int> rGetCursorPosition() {
	return Vector2TorVector2<unsigned int>(GetMousePosition());
}

void rSetCursorPosition(rVector2<unsigned int> position) {
	SetMousePosition(position.x, position.y);
}

void rDrawClear(rColor color) {
	ClearBackground(rColorToColor(color));
}

void rSetMaxFPS(int fps) {
	SetTargetFPS(fps);
}

float rGetDelta() {
	return GetFrameTime();
}

bool rIsGameLooping() {
	return !WindowShouldClose();
}

void rSetRandomSeed(unsigned int seed) {
	SetRandomSeed(seed);
}

void rSleep(double seconds) {
	WaitTime(seconds);
}

int rGetRandomValue(int min, int max) {
	return GetRandomValue(min, max);
}

std::map<rKeys::Key, int> _keyMap{ {rKeys::Q, KEY_Q}, {rKeys::W, KEY_W}, {rKeys::E, KEY_E}, {rKeys::R, KEY_R}, {rKeys::T, KEY_T}, {rKeys::Y, KEY_Y}, {rKeys::U, KEY_U}, {rKeys::I, KEY_I}, {rKeys::O, KEY_O}, {rKeys::P, KEY_P}, {rKeys::A, KEY_A}, {rKeys::S, KEY_S}, {rKeys::D, KEY_D}, {rKeys::F, KEY_F}, {rKeys::G, KEY_G}, {rKeys::H, KEY_H}, {rKeys::J, KEY_J}, {rKeys::K, KEY_K}, {rKeys::L, KEY_L}, {rKeys::Z, KEY_Z}, {rKeys::X, KEY_X}, {rKeys::C, KEY_C}, {rKeys::V, KEY_V}, {rKeys::B, KEY_B}, {rKeys::N, KEY_N}, {rKeys::M, KEY_M},
	{rKeys::Space, KEY_SPACE}, {rKeys::LeftAlt, KEY_LEFT_ALT}, {rKeys::RightAlt, KEY_RIGHT_ALT}, {rKeys::LeftCtrl, KEY_LEFT_CONTROL}, {rKeys::RightCtrl, KEY_RIGHT_CONTROL}, {rKeys::LeftShift, KEY_LEFT_SHIFT}, {rKeys::RightShift, KEY_RIGHT_SHIFT}, {rKeys::Enter, KEY_ENTER}, {rKeys::Left, KEY_LEFT}, {rKeys::Right, KEY_RIGHT}, {rKeys::Up, KEY_UP}, {rKeys::Down, KEY_DOWN} };

int rKeyToInt(rKeys::Key key) {
	return _keyMap[key];
}

bool rIsKeyPressed(rKeys::Key key) {
	return IsKeyPressed(rKeyToInt(key));
}

bool rIsKeyHeld(rKeys::Key key) {
	return IsKeyDown(rKeyToInt(key));
}

bool rIsKeyReleased(rKeys::Key key) {
	return IsKeyReleased(rKeyToInt(key));
}

std::string rGetWorkingDirectory() {
	return GetWorkingDirectory();
}