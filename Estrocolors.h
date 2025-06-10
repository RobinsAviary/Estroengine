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
		inline Color White = { 255, 255, 255, 255 };
		inline Color Black = { 0, 0, 0, 255 };
		inline Color Red = { 255, 0, 0, 255 };
		inline Color Green = { 0, 255, 0, 255 };
		inline Color Blue = { 0, 0, 255, 255 };
		inline Color Gray = { 128, 128, 128, 255 };
		inline Color DarkGray = { 48, 48, 48, 255 };
		inline Color LightGray = { 192, 192, 192, 255 };
		inline Color Pink = { 255, 0, 220, 255 };
		inline Color Yellow = { 255, 216, 0, 255 };
		inline Color Brown = { 84, 45, 19, 255 };
		inline Color Purple = { 140, 0, 255, 255 };
		inline Color HotPink = { 255, 0, 110, 255 };
		inline Color Estrogen = { 142, 236, 255, 255 };
	}
}