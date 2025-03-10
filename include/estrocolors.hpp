#pragma once

typedef struct rColor {
	rColor(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255) : r(r), g(g), b(b), a(a) {}
	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	unsigned char a = 255;
} rColor;

rColor cWhite = { 255, 255, 255, 255 };
rColor cBlack = { 0, 0, 0, 255 };
rColor cRed = { 255, 0, 0, 255 };
rColor cGreen = { 0, 255, 0, 255 };
rColor cBlue = { 0, 0, 255, 255 };
rColor cGray = { 128, 128, 128, 255 };
rColor cDarkGray = { 48, 48, 48, 255 };
rColor cLightGray = { 192, 192, 192, 255 };
rColor cPink = { 255, 0, 220, 255 };
rColor cYellow = { 255, 216, 0, 255 };
rColor cBrown = { 84, 45, 19, 255 };
rColor cPurple = { 140, 0, 255, 255 };
rColor cHotPink = { 255, 0, 110, 255 };
rColor cEstrogen = { 142, 236, 255, 255 };