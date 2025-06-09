#pragma once

namespace Estro {
	struct Color {
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
		unsigned char a = 255;

		Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 255);

		Color operator+ (const Color& rhs);
		Color operator- (const Color& rhs);
		Color operator* (const Color& rhs);
		Color operator/ (const Color& rhs);

		void operator+=(Color& rhs);
		void operator-=(Color& rhs);
		void operator*=(Color& rhs);
		void operator/=(Color& rhs);

		bool operator==(const Color& rhs);
		bool operator!=(const Color& rhs);

		void rgb(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);
		void rgba(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 0);
		void hsv(unsigned int hue = 0, unsigned char saturation = 0, unsigned char value = 0);
		void hsva(unsigned int hue = 0, unsigned char value = 0, unsigned char saturation = 0, unsigned char alpha = 0);
		void mix(Color color);
	};

	namespace Colors {
		inline Color White = {255, 255, 255, 255};
		inline Color Black = {0, 0, 0, 255};
	}
}