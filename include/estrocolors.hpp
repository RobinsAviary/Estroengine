#pragma once

struct rColor {
	rColor(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255) : r(r), g(g), b(b), a(a) {}

	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	unsigned char a = 255;

	rColor(unsigned char grayscale = 0, unsigned char alpha = 255) {
		r = grayscale;
		g = grayscale;
		b = grayscale;
		a = alpha;
	}

	void rgb(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0) {
		r = red;
		g = green;
		b = blue;
	}

	void rgba(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 0) {
		rgb(red, green, blue);
		a = alpha;
	}

	void hsv(unsigned int hue = 0, unsigned char saturation = 0, unsigned char value = 0) {
		// derived from https://cs.stackexchange.com/questions/64549/convert-hsv-to-rgb-colors

		unsigned char max = value;
		unsigned int chroma = saturation * value;
		unsigned char min = max - chroma;

		if (hue >= 300) {
			hue -= 360;
			hue /= 60;
		}
		else {
			hue = hue / 60;
		}

		if (hue < 0) {
			r = max;
			g = min;
			b = min - hue * chroma;
		}
		else if (hue >= 0) {
			r = max;
			g = min + hue * chroma;
			b = min;
		}

		if (hue - 2 < 0) {
			r = min - (hue - 2) * chroma;
			g = max;
			b = min;
		}
		else if (hue - 2 >= 0) {
			r = min;
			g = max;
			b = r + (hue - 2) * chroma;
		}

		if (hue - 4 < 0) {
			r = min;
			g = min - (hue - 4) * chroma;
			b = max;
		}
		else if (hue - 4 >= 0) {
			r = min + (hue - 4) * chroma;
			g = min;
			b = max;
		}
	}

	void hsva(unsigned int hue = 0, unsigned int value = 0, unsigned int saturation = 0, unsigned int alpha = 0) {
		hsv(hue, value, saturation);
		a = alpha;
	}
};

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