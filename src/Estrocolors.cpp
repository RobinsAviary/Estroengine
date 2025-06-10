#include "../include/Estrocolors.h"

using namespace Estro;

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
	r = red;
	g = green;
	b = blue;
	a = alpha;
}

Color Color::operator+ (const Color& rhs) {
	return Color{ static_cast<unsigned char>(r + rhs.r), static_cast<unsigned char>(g + rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
}

Color Color::operator- (const Color& rhs) {
	return Color{ static_cast<unsigned char>(r - rhs.r), static_cast<unsigned char>(g - rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
}

Color Color::operator* (const Color& rhs) {
	return Color{ static_cast<unsigned char>(r * rhs.r), static_cast<unsigned char>(g * rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
}

Color Color::operator/ (const Color& rhs) {
	return Color{ static_cast<unsigned char>(r / rhs.r), static_cast<unsigned char>(g / rhs.g), static_cast<unsigned char>(b + rhs.b), static_cast<unsigned char>(a + rhs.a) };
}

void Color::operator+=(Color& rhs) {
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	a += rhs.a;
}

void Color::operator-=(Color& rhs) {
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	a -= rhs.a;
}

void Color::operator*=(Color& rhs) {
	r *= rhs.r;
	g *= rhs.g;
	b *= rhs.b;
	a *= rhs.a;
}

void Color::operator/=(Color& rhs) {
	r /= rhs.r;
	g /= rhs.g;
	b /= rhs.b;
	a /= rhs.a;
}

bool Color::operator==(const Color& rhs) {
	return (r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a);
}

bool Color::operator!=(const Color& rhs) {
	return (r != rhs.r || g != rhs.g || b != rhs.b || a == rhs.a);
}

void Color::rgb(unsigned char red, unsigned char green, unsigned char blue) {
	r = red;
	g = green;
	b = blue;
}

void Color::rgba(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
	r = red;
	g = green;
	b = blue;
	a = alpha;
}

void Color::hsv(unsigned int hue, unsigned char saturation, unsigned char value) {
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

void Color::hsva(unsigned int hue, unsigned char value, unsigned char saturation, unsigned char alpha) {
	hsv(hue, value, saturation);
	a = alpha;
}

void Color::mix(Color color) {
	r = (r + color.r) / 2;
	g = (g + color.g) / 2;
	b = (b + color.b) / 2;
	a = (a + color.a) / 2;
}