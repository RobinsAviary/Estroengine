#pragma once
#include "Estrodefs.h"

namespace Estro {
	template <typename T>
	struct Vector2 {
		T x = 0;
		T y = 0;

		Vector2(T xPosition = 0 , T yPosition = 0) {
			x = xPosition;
			y = yPosition;
		}

		Vector2<T> yx();

		Vector2<T> operator+ (const Vector2<T>& rhs);
		Vector2<T> operator- (const Vector2<T>& rhs);
		Vector2<T> operator* (const Vector2<T>& rhs);
		Vector2<T> operator/ (const Vector2<T>& rhs);

		void operator+=(Vector2<T>& rhs);
		void operator-=(Vector2<T>& rhs);
		void operator*=(Vector2<T>& rhs);
		void operator/=(Vector2<T>& rhs);
		bool operator==(const Vector2<T>& rhs);
		bool operator!=(const Vector2<T>& rhs);

		template <typename newType>
		Vector2<newType> cast();
	};

	template <typename T>
	struct Vector3 {
		public:
			T x = 0;
			T y = 0;
			T z = 0;
			
			Vector3(T xPosition = 0, T yPosition = 0, T zPosition = 0);
			Vector3(Vector2<T> vector = { 0, 0 });

			Vector3<T> yxz();
			Vector3<T> zxy();
			Vector3<T> xzy();
			Vector3<T> yzx();
			Vector3<T> zyx();
			Vector2<T> xy();
			Vector2<T> yx();

			Vector3<T> operator+ (const Vector3<T>& rhs);
			Vector3<T> operator- (const Vector3<T>& rhs);
			Vector3<T> operator* (const Vector3<T>& rhs);
			Vector3<T> operator/ (const Vector3<T>& rhs);

			void operator+=(Vector3<T>& rhs);
			void operator-=(Vector3<T>& rhs);
			void operator*=(Vector3<T>& rhs);
			void operator/=(Vector3<T>& rhs);
			bool operator==(const Vector3<T>& rhs);
			bool operator!=(const Vector3<T>& rhs);

			template <typename newType>
			Vector3<newType> cast();
	};

	template <typename T>
	struct Rectangle {
		Vector2<T> position;
		Vector2<T> size;
	};

	template <typename T>
	struct Circle {
		Vector2<T> position;
		T radius;
	};

	template <typename T>
	/*!@brief Checks if a given point is inside a rectangle.*/
	bool isPointInsideRectangle(Vector2<T> point, Rectangle<T> rectangle) {
		const bool horizontal = point.x >= rectangle.position.x && point.x < rectangle.position.x + rectangle.size.x;
		const bool vertical = point.y >= rectangle.position.y && point.y < rectangle.position.y + rectangle.size.y;

		return (horizontal && vertical);
	}

	class Transform {
		Vector3<float> position;
		Vector3<float> rotation;
		Vector3<float> scale;
	};

	class Transformable {
		Transform transform;
	};
}

template <typename T> template <typename newType>
Estro::Vector2<newType> Estro::Vector2<T>::cast() {
	return {static_cast<newType>(x), static_cast<newType>(y)};
}

TemplateType
Estro::Vector2<T> Estro::Vector2<T>::operator+ (const Vector2<T>& rhs) {
	return Vector2<T> {x + rhs.x, y + rhs.y};
}

TemplateType
Estro::Vector2<T> Estro::Vector2<T>::operator- (const Vector2<T>& rhs) {
	return Vector2<T> {x - rhs.x, y - rhs.y};
}

TemplateType
Estro::Vector2<T> Estro::Vector2<T>::operator* (const Vector2<T>& rhs) {
	return Vector2<T> {x * rhs.x, y * rhs.y};
}

TemplateType
Estro::Vector2<T> Estro::Vector2<T>::operator/ (const Vector2<T>& rhs) {
	return Vector2<T> {x / rhs.x, y / rhs.y};
}

TemplateType
void Estro::Vector2<T>::operator+=(Vector2<T>& rhs) {
	x += rhs.x;
	y += rhs.y;
}

TemplateType
void Estro::Vector2<T>::operator-=(Vector2<T> &rhs) {
	x -= rhs.x;
	y -= rhs.y;
}

TemplateType
void Estro::Vector2<T>::operator*=(Vector2<T>& rhs) {
	x *= rhs.x;
	y *= rhs.y;
}

TemplateType
void Estro::Vector2<T>::operator/=(Vector2<T>& rhs) {
	x /= rhs.x;
	y /= rhs.y;
}

TemplateType
bool Estro::Vector2<T>::operator==(const Vector2<T>& rhs) {
	return (x == rhs.x && y == rhs.y);
}

TemplateType
bool Estro::Vector2<T>::operator!=(const Vector2<T>& rhs) {
	return (x != rhs.x || y != rhs.y);
}

//!Returns a swizzled vector of y and x.
TemplateType
Estro::Vector2<T> Estro::Vector2<T>::yx() {
	return Vector2<T>{y, x};
}

//!Returns a swizzled vector of y, x, and z.
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::yxz() {
	return Vector3<T>{y, x, z};
}

//!Returns a swizzled vector of z, x, and y.
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::zxy() {
	return Vector3<T>{z, x, y};
}

//!Returns a swizzled vector of x, z, and y.
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::xzy() {
	return Vector3<T>{x, z, y};
}

//!Returns a swizzled vector of y, z, and x.
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::yzx() {
	return Vector3<T>{y, z, x};
}

//!Returns a swizzled vector of z, y, and x.
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::zyx() {
	return Vector3<T>{z, y, x};
}

//!Returns a Vector2 of the x and y values.
TemplateType
Estro::Vector2<T> Estro::Vector3<T>::xy() {
	return Vector2<T>{x, y};
}

//!Returns a Vector2 of the y and x values.
TemplateType
Estro::Vector2<T> Estro::Vector3<T>::yx() {
	return Vector2<T>{y, x};
}

TemplateType
Estro::Vector3<T>::Vector3(T xPosition, T yPosition, T zPosition) {
	x = xPosition;
	y = yPosition;
	z = zPosition;
}

TemplateType
Estro::Vector3<T>::Vector3(Vector2<T> vector) {
	x = vector.x;
	y = vector.y;
}

template <typename T> template <typename newType>
Estro::Vector3<newType> Estro::Vector3<T>::cast() {
	return Vector3<newType> {static_cast<newType>(x), static_cast<newType>(y), static_cast<newType>(z)};
}

TemplateType
Estro::Vector3<T> Estro::Vector3<T>::operator+ (const Vector3<T>& rhs) {
	return Vector3<T> {x + rhs.x, y + rhs.y, z + rhs.z};
}

TemplateType
Estro::Vector3<T> Estro::Vector3<T>::operator- (const Vector3<T>& rhs) {
	return Vector3<T> {x - rhs.x, y - rhs.y, z - rhs.z};
}

TemplateType
Estro::Vector3<T> Estro::Vector3<T>::operator* (const Vector3<T>& rhs) {
	return Vector3<T> {x * rhs.x, y * rhs.y, z * rhs.z};
}

TemplateType
Estro::Vector3<T> Estro::Vector3<T>::operator/ (const Vector3<T>& rhs) {
	return Vector3<T> {x / rhs.x, y / rhs.y, z / rhs.z};
}

TemplateType
void Estro::Vector3<T>::operator+=(Vector3<T>& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

TemplateType
void Estro::Vector3<T>::operator-=(Vector3<T>& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

TemplateType
void Estro::Vector3<T>::operator*=(Vector3<T>& rhs) {
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
}

TemplateType
void Estro::Vector3<T>::operator/=(Vector3<T>& rhs) {
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
}

TemplateType
bool Estro::Vector3<T>::operator==(const Vector3<T>& rhs) {
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

TemplateType
bool Estro::Vector3<T>::operator!=(const Vector3<T>& rhs) {
	return (x != rhs.x || y != rhs.y || z != rhs.z);
}