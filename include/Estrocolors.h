#pragma once

namespace Estro {
	struct Color {
		//!Red value.
		unsigned char r = 0;
		//!Green value.
		unsigned char g = 0;
		//!Blue value.
		unsigned char b = 0;
		//!Alpha value.
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

		/*!@brief Sets the Color using Red, Green, and Blue. Assumes Alpha to be 255.
		@param red Red.
		@param green Green.
		@param blue Blue.
		@sa rgba(), hsv(), hsva().
		*/
		void rgb(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);

		/*!@brief Sets the Color using Red, Green, Blue, and Alpha.
		@param red Red.
		@param green Green.
		@param blue Blue.
		@param alpha Alpha.
		@sa rgb(), hsv(), hsva().
		*/
		void rgba(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 255);

		/*!@brief Sets the Color using Hue, Saturation, and Value. Assumes alpha to be 255.
		@param hue Hue.
		@param saturation Saturation.
		@param value Value.
		@sa rgb(), rgba(), hsva().
		*/
		void hsv(unsigned int hue = 0, unsigned char saturation = 0, unsigned char value = 0);

		/*!@brief Sets the Color using Hue, Saturation, Value, and Alpha.
		@param hue Hue.
		@param saturation Saturation.
		@param value Value.
		@sa rgb(), rgba(), hsv().
		*/
		void hsva(unsigned int hue = 0, unsigned char value = 0, unsigned char saturation = 0, unsigned char alpha = 255);

		/*!@brief Averages the base color with the supplied color.
		@param color The color to mix in.
		*/
		void mix(Color color);
	};

	//!Default colors.
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
		//!@briefA basic light blue color.
		inline Color Estrogen = { 142, 236, 255, 255 };
	}
}