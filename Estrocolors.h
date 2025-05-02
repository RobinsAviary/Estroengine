#pragma once

// Estrocolors, created for estroengine by Robin <3

namespace Estro {
	struct Color {
		Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255) : r(r), g(g), b(b), a(a) {}

		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
		unsigned char a = 255;

		Color(unsigned char grayscale = 0, unsigned char alpha = 255) {
			r = grayscale;
			g = grayscale;
			b = grayscale;
			a = alpha;
		}

		inline Color operator+ (const Color& rhs) {
			Color{ static_cast<unsigned char>(r + rhs.r), static_cast<unsigned char>(g + rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
		}

		inline Color operator- (const Color& rhs) {
			Color{ static_cast<unsigned char>(r - rhs.r), static_cast<unsigned char>(g - rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
		}

		inline Color operator* (const Color& rhs) {
			Color{ static_cast<unsigned char>(r * rhs.r), static_cast<unsigned char>(g * rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
		}

		inline Color operator/ (const Color& rhs) {
			Color{ static_cast<unsigned char>(r / rhs.r), static_cast<unsigned char>(g / rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
		}

		inline void operator+=(Color& rhs) {
			r += rhs.r;
			g += rhs.g;
			b += rhs.b;
			a += rhs.a;
		}

		inline void operator-=(Color& rhs) {
			r -= rhs.r;
			g -= rhs.g;
			b -= rhs.b;
			a -= rhs.a;
		}

		inline void operator*=(Color& rhs) {
			r *= rhs.r;
			g *= rhs.g;
			b *= rhs.b;
			a *= rhs.a;
		}

		inline void operator/=(Color& rhs) {
			r /= rhs.r;
			g /= rhs.g;
			b /= rhs.b;
			a /= rhs.a;
		}

		inline bool operator==(const Color& rhs) {
			return (r == rhs.r && b == rhs.b && g == rhs.g && a == rhs.a);
		}

		inline bool operator!=(const Color& rhs) {
			return (r != rhs.r || b != rhs.b || g != rhs.g || a != rhs.a);
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

		void mix(Color color) {
			r = (r + color.r) / 2;
			g = (g + color.g) / 2;
			b = (b + color.b) / 2;
			a = (a + color.a) / 2;
		}

		void hsva(unsigned int hue = 0, unsigned int value = 0, unsigned int saturation = 0, unsigned int alpha = 0) {
			hsv(hue, value, saturation);
			a = alpha;
		}
	};

	/*Color cWhite = {255, 255, 255, 255};
	Color cBlack = { 0, 0, 0, 255 };
	Color cRed = { 255, 0, 0, 255 };
	Color cGreen = { 0, 255, 0, 255 };
	Color cBlue = { 0, 0, 255, 255 };
	Color cGray = { 128, 128, 128, 255 };
	Color cDarkGray = { 48, 48, 48, 255 };
	Color cLightGray = { 192, 192, 192, 255 };
	Color cPink = { 255, 0, 220, 255 };
	Color cYellow = { 255, 216, 0, 255 };
	Color cBrown = { 84, 45, 19, 255 };
	Color cPurple = { 140, 0, 255, 255 };
	Color cHotPink = { 255, 0, 110, 255 };
	Color cEstrogen = { 142, 236, 255, 255 };*/
}