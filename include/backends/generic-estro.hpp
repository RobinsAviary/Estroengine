#pragma once
#include "../estrotypes.hpp"
#include "../estroinput.hpp"

std::string rGetBackendName();

class rCPUTexture : public rAsset {
public:
	rColor getPixel(rVector2<unsigned int> position);

	int getWidth();

	int getHeight();

	rVector2<unsigned int> getSize();

	void load(std::string filename);

	~rCPUTexture();
};

class rTexture : public rAsset {
public:
	int getWidth();

	int getHeight();

	rVector2<unsigned int> getSize();

	void load(std::string filename);

	~rTexture();
};

std::string rGetClipboard();

void rSetClipboard(std::string _string);

void rInit(unsigned int windowWidth, unsigned int windowHeight, std::string windowTitle, bool resizable = false);

void rDeinit();

void rDrawTexture(rTexture* texture, rVector2<float> position, rColor tint);

void rDrawTextureSection(rTexture* texture, rVector2<float> position, rRectangle<int> rectangle, rColor tint);

void rDrawTextureReproject(rTexture* texture, rRectangle<int> source, rRectangle<float> target, rColor tint);

void rDrawLine(rVector2<float> pos1, rVector2<float> pos2, rColor color);

void rDrawRectangle(rRectangle<float> rectangle, rColor color, bool filled);

void rDrawCircle(rVector2<float> position, float radius, rColor color, bool filled);

// NOTE: DO NOT use in large amounts, this is generally not an efficient way to do whatever you're doing. Look into editing the textures directly or simplifying shapes.
void rDrawPixel(rVector2<int> position, rColor color);

void rBeginStep();

void rEndStep();

void rBeginDraw();

void rEndDraw();

rVector2<int> rGetMousePosition();

void rSetMousePosition(rVector2<int> position);

void rSetWindowTitle(std::string title);

int rGetWindowWidth();

int rGetWindowHeight();

rVector2<unsigned int> rGetWindowSize();

void rSetWindowSize(rVector2<unsigned int> size);

void rSetWindowOpacity(float opacity);

void rSetWindowPosition(rVector2<int> position);

rVector2<int> rGetWindowPosition();

void rShowCursor();

void rHideCursor();

bool rIsCursorHidden();

bool rIsCursorOnScreen();

rVector2<int> rGetCursorPosition();

void rSetCursorPosition(rVector2<int> position);

void rDrawClear(rColor color);

void rSetMaxFPS(int fps);

float rGetDelta();

bool rIsGameLooping();

void rSetRandomSeed(unsigned int seed);

void rSleep(double seconds);

int rGetRandomValue(int min, int max);

bool rIsKeyPressed(rKey key);

bool rIsKeyHeld(rKey key);

bool rIsKeyReleased(rKey key);

std::string rGetWorkingDirectory();