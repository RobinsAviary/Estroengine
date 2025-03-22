#pragma once
#include "../estrotypes.hpp"

std::string rGetBackendName()

class rCPUTexture {
public:
	//CustomType texture;

	rColor getPixel(rVector2 position)

	int getWidth()

	int getHeight()

	rVector2 getSize()

	void load(std::string filename)

	~rCPUTexture()
};

class rTexture {
public:
	//CustomType texture;

	int getWidth()

	int getHeight()

	rVector2 getSize()

	void load(std::string filename)

	~rTexture()
};

std::string rGetClipboard()

void rSetClipboard(std::string _string)

void rInit(int windowWidth, int windowHeight, std::string windowTitle, bool resizable = false)

void rDeinit()

void rDrawTexture(const rTexture& texture, rVector2 position, rColor tint)

void rDrawTextureSection(const rTexture& texture, rVector2 position, rRectangle rectangle, rColor tint)

void rDrawTextureReproject(const rTexture& texture, rRectangle source, rRectangle target, rColor tint)

void rDrawLine(rVector2 pos1, rVector2 pos2, rColor color)

void rDrawRectangle(rRectangle rectangle, rColor color, bool filled)

void rDrawCircle(rVector2 position, float radius, rColor color, bool filled)

// NOTE: DO NOT use in large amounts, this is generally not an efficient way to do whatever you're doing. Look into editing the textures directly or simplifying shapes.
void rDrawPixel(rVector2 position, rColor color)

void rBeginStep()

void rEndStep()

void rBeginDraw()

void rEndDraw()

rVector2 rGetMousePosition()

void rSetMousePosition(rVector2 position)

void rSetWindowTitle(std::string title)

int rGetWindowWidth()

int rGetWindowHeight()

rVector2 rGetWindowSize()

void rSetWindowSize(rVector2 size)

void rSetWindowOpacity(float opacity)

void rSetWindowPosition(rVector2 position)

rVector2 rGetWindowPosition()

void rShowCursor()

void rHideCursor()

bool rIsCursorHidden()

bool rIsCursorOnScreen()

rVector2 rGetCursorPosition()

void rSetCursorPosition(rVector2 position)

void rDrawClear(rColor color)

void rSetMaxFPS(int fps)

float rGetDelta()

bool rIsGameLooping()

void rSetRandomSeed(unsigned int seed)

void rSleep(double seconds)

int rGetRandomValue(int min, int max)