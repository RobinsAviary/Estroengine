#include "raylib.h"
#include "../estrotypes.hpp"
#include <string>
#include <map>
#include <iostream>

std::string backendName = "raylib";

Color rColorToColor(rColor color) {
	return Color{ color.r, color.g, color.b, color.a };
}

rColor ColorTorColor(Color color) {
	return rColor{ color.r, color.g, color.b, color.a };
}

Vector2 rVector2ToVector2(rVector2 vector) {
	return Vector2{ static_cast<float>(vector.x), static_cast<float>(vector.y) };
}

Rectangle rRectangleToRectangle(rRectangle rectangle) {
	return Rectangle{ static_cast<float>(rectangle.x), static_cast<float>(rectangle.y), static_cast<float>(rectangle.w), static_cast<float>(rectangle.h) };
}

class rCPUTexture {
	public:
		Image texture;

		rColor getPixel(rVector2 position) {
			return ColorTorColor(GetImageColor(texture, position.x, position.y));
		}

		int getWidth() {
			return texture.width;
		}

		int getHeight() {
			return texture.height;
		}
};

class rTexture {
	public:
		Texture2D texture;

		int getWidth() {
			return texture.width;
		}

		int getHeight() {
			return texture.height;
		}
};

rTexture rLoadTexture(std::string filename) {
	rTexture result;

	result.texture = LoadTexture(filename.c_str());

	return result;
};

void rUnloadTexture(rTexture texture) {
	UnloadTexture(texture.texture);
}

rCPUTexture rLoadCPUTexture(std::string filename) {
	rCPUTexture result;

	result.texture = LoadImage(filename.c_str());

	return result;
}

void rUnloadCPUTexture(rCPUTexture texture) {
	UnloadImage(texture.texture);
}

void rInit(int windowWidth, int windowHeight, std::string windowTitle) {
	InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

void rDeinit() {
	CloseWindow();
}

void rDrawTexture(rTexture* texture, rVector2 position, rColor tint) {
	DrawTexture(texture->texture, position.x, position.y, rColorToColor(tint));
}

void rDrawTextureSection(rTexture* texture, rVector2 position, rRectangle rectangle, rColor tint) {
	if (texture) {
		DrawTextureRec(texture->texture, rRectangleToRectangle(rectangle), rVector2ToVector2(position), rColorToColor(tint));
	}
}

void rDrawTextureReproject(rTexture* texture, rRectangle source, rRectangle target, rColor tint) {
	DrawTexturePro(texture->texture, rRectangleToRectangle(source), rRectangleToRectangle(target), Vector2{ 0, 0 }, 0, rColorToColor(tint));
}

void rDrawLine(rVector2 pos1, rVector2 pos2, rColor color) {
	DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, rColorToColor(color));
}

void rDrawRectangle(rRectangle rectangle, rColor color, bool filled) {
	if (filled) {
		DrawRectangle(rectangle.x, rectangle.y, rectangle.w, rectangle.h, rColorToColor(color));
	}
	else {
		DrawRectangleLines(rectangle.x, rectangle.y, rectangle.w, rectangle.h, rColorToColor(color));
	}
}

void rDrawCircle(rVector2 position, float radius, rColor color, bool filled) {
	if (filled) {
		DrawCircle(position.x, position.y, radius, rColorToColor(color));
	}
	else {
		DrawCircleLines(position.x, position.y, radius, rColorToColor(color));
	}
}

// NOTE: DO NOT use in large amounts, this is generally not an efficient way to do whatever you're doing. Look into editing the textures directly or simplifying shapes.
void rDrawPixel(rVector2 position, rColor color) {
	DrawPixel(position.x, position.y, rColorToColor(color));
}

void rBeginStep() {
	
}

void rBeginDraw() {
	BeginDrawing();
}

void rEndDraw() {
	EndDrawing();
}

rVector2 rGetMousePosition() {
	return rVector2{ GetMouseX(), GetMouseY() };
}

void rSetMousePosition(rVector2 position) {
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

rVector2 rGetWindowSize() {
	return rVector2{ rGetWindowWidth(), rGetWindowHeight() };
}

void rSetWindowSize(rVector2 size) {
	SetWindowSize(size.x, size.y);
}

void rSetWindowOpacity(float opacity) {
	SetWindowOpacity(opacity);
}

void rSetWindowPosition(rVector2 position) {
	SetWindowPosition(position.x, position.y);
}

rVector2 rGetWindowPosition() {
	Vector2 position = GetWindowPosition();

	return rVector2{ static_cast<int>(position.x), static_cast<int>(position.y) };
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

class rInput {
public:

};
