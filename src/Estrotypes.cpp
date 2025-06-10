#include "../include/Estrotypes.h"

#include "../include/Estrodefs.h"

using namespace Estro;

/*template <typename T> template <typename newType>
Vector2<typename newType> Vector2<T>::cast() {
	return Vector2<newType>{static_cast<newType>(x), static_cast<newType>(y)};
}*/

TemplateType
Vector2<T> Vector2<T>::operator+ (const Vector2<T>& rhs) {
	return Vector2<T> {x + rhs.x, y + rhs.y};
}

TemplateType
Vector2<T> Vector2<T>::operator- (const Vector2<T>& rhs) {
	return Vector2<T> {x - rhs.x, y - rhs.y};
}

TemplateType
Vector2<T> Vector2<T>::operator* (const Vector2<T>& rhs) {
	return Vector2<T> {x * rhs.x, y * rhs.y};
}

TemplateType
Vector2<T> Vector2<T>::operator/ (const Vector2<T>& rhs) {
	return Vector2<T> {x / rhs.x, y / rhs.y};
}

TemplateType
void Vector2<T>::operator+=(Vector2<T>& rhs) {
	x += rhs.x;
	y += rhs.y;
}

TemplateType
void Vector2<T>::operator-=(Vector2<T> &rhs) {
	x -= rhs.x;
	y -= rhs.y;
}

TemplateType
void Vector2<T>::operator*=(Vector2<T>& rhs) {
	x *= rhs.x;
	y *= rhs.y;
}

TemplateType
void Vector2<T>::operator/=(Vector2<T>& rhs) {
	x /= rhs.x;
	y /= rhs.y;
}

TemplateType
bool Vector2<T>::operator==(const Vector2<T>& rhs) {
	return (x == rhs.x && y == rhs.y);
}

TemplateType
bool Vector2<T>::operator!=(const Vector2<T>& rhs) {
	return (x != rhs.x || y != rhs.y);
}

//!Returns a swizzled vector of y and x.
TemplateType
Vector2<T> Vector2<T>::yx() {
	return Vector2<T>{y, x};
}

//!Returns a swizzled vector of y, x, and z.
TemplateType
Vector3<T> Vector3<T>::yxz() {
	return Vector3<T>{y, x, z};
}

//!Returns a swizzled vector of z, x, and y.
TemplateType
Vector3<T> Vector3<T>::zxy() {
	return Vector3<T>{z, x, y};
}

//!Returns a swizzled vector of x, z, and y.
TemplateType
Vector3<T> Vector3<T>::xzy() {
	return Vector3<T>{x, z, y};
}

//!Returns a swizzled vector of y, z, and x.
TemplateType
Vector3<T> Vector3<T>::yzx() {
	return Vector3<T>{y, z, x};
}

//!Returns a swizzled vector of z, y, and x.
TemplateType
Vector3<T> Vector3<T>::zyx() {
	return Vector3<T>{z, y, x};
}

//!Returns a Vector2 of the x and y values.
TemplateType
Vector2<T> Vector3<T>::xy() {
	return Vector2<T>{x, y};
}

//!Returns a Vector2 of the y and x values.
TemplateType
Vector2<T> Vector3<T>::yx() {
	return Vector2<T>{y, x};
}

TemplateType
Vector3<T>::Vector3(T xPosition, T yPosition, T zPosition) {
	x = xPosition;
	y = yPosition;
	z = zPosition;
}

TemplateType
Vector3<T>::Vector3(Vector2<T> vector) {
	x = vector.x;
	y = vector.y;
}

template <typename T> template <typename newType>
Vector3<newType> Vector3<T>::cast() {
	return Vector3<newType> {static_cast<newType>(x), static_cast<newType>(y), static_cast<newType>(z)};
}

TemplateType
Vector3<T> Vector3<T>::operator+ (const Vector3<T>& rhs) {
	return Vector3<T> {x + rhs.x, y + rhs.y, z + rhs.z};
}

TemplateType
Vector3<T> Vector3<T>::operator- (const Vector3<T>& rhs) {
	return Vector3<T> {x - rhs.x, y - rhs.y, z - rhs.z};
}

TemplateType
Vector3<T> Vector3<T>::operator* (const Vector3<T>& rhs) {
	return Vector3<T> {x * rhs.x, y * rhs.y, z * rhs.z};
}

TemplateType
Vector3<T> Vector3<T>::operator/ (const Vector3<T>& rhs) {
	return Vector3<T> {x / rhs.x, y / rhs.y, z / rhs.z};
}

TemplateType
void Vector3<T>::operator+=(Vector3<T>& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

TemplateType
void Vector3<T>::operator-=(Vector3<T>& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

TemplateType
void Vector3<T>::operator*=(Vector3<T>& rhs) {
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
}

TemplateType
void Vector3<T>::operator/=(Vector3<T>& rhs) {
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
}

TemplateType
bool Vector3<T>::operator==(const Vector3<T>& rhs) {
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

TemplateType
bool Vector3<T>::operator!=(const Vector3<T>& rhs) {
	return (x != rhs.x || y != rhs.y || z != rhs.z);
}

TemplateType
bool isPointInsideRectangle(Vector2<T> point, Rectangle<T> rectangle) {
	bool horizontal = point.x >= rectangle.position.x && point.x < rectangle.position.x + rectangle.size.x;
	bool vertical = point.y >= rectangle.position.y && point.y < rectangle.position.y + rectangle.size.y;

	return (horizontal && vertical);
}