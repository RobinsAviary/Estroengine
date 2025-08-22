#pragma once
#include "Estrodefs.h"

namespace Estro {
	/*!@brief A simple struct for storing two numbers. Typically used for a 2D position.*/
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

	/*!@brief A simple struct for storing three numbers. Typically used for a 3D position.*/
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

	/*!@brief A simple struct for representing a Rectangle.
	 *
	 * It is polymorphic to support different art/game-styles.
	 * @sa Vector2, Circle
	 */
	template <typename T>
	struct Rectangle {
		Vector2<T> position;
		Vector2<T> size;
	};

	/*!@brief A simple struct for representing a Circle.
	 *
	 * It is polymorphic to support different art/game-styles.
	 * @sa Vector2, Rectangle
	 */
	template <typename T>
	struct Circle {
		Vector2<T> position;
		T radius;
	};

	template <typename T>
	/*!@brief Checks if a given point is inside a rectangle.
	 * @sa Vector2, Rectangle
	 */
	bool isPointInsideRectangle(Vector2<T> point, Rectangle<T> rectangle) {
		const bool horizontal = point.x >= rectangle.position.x && point.x < rectangle.position.x + rectangle.size.x;
		const bool vertical = point.y >= rectangle.position.y && point.y < rectangle.position.y + rectangle.size.y;

		return (horizontal && vertical);
	}

	/*!@brief An abstract class for representing a transform.
	 * @sa Transform2D, Transform3D
	 */
	class Transform {

	};

	/*!@brief A simple class for representing a 2D object's transform.
	 * @sa Transform, Transform3D
	 */
	class Transform2D : public Transform {
		Vector2<float> position;
		Vector2<float> rotation;
		Vector2<float> scale;
	};

	/*!@brief A simple class for representing a 3D object's transform
	 * @sa Transform, Transform2D
	 */
	class Transform3D : public Transform {
		Vector3<float> position;
		Vector3<float> rotation;
		Vector3<float> scale;
	};

	/*!@brief An abstract class to represent an object in an N-Dimensional space*/
	class Transformable {

	};

	/*!@brief A simple class to represent an object in a 2D space.*/
	class Transformable2D : public Transformable {
		Transform2D transform;
	};

	/*!@brief A simple class to represent an object in a 3D space.*/
	class Transformable3D : public Transformable {
		Transform3D transform;
	};
}

/*!@brief Cast the values in a Vector2 to a different type.*/
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

/*!@brief Returns a swizzled vector of y and x.*/
TemplateType
Estro::Vector2<T> Estro::Vector2<T>::yx() {
	return Vector2<T>{y, x};
}

/*!@brief Returns a swizzled vector of y, x, and z.
 * @sa zxy, xzy, yzx, zyx, xy, yx
 */
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::yxz() {
	return Vector3<T>{y, x, z};
}

/*!@brief Returns a swizzled vector of z, x, and y.
 * @sa yxz, xzy, yzx, zyx, xy, yx
 */
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::zxy() {
	return Vector3<T>{z, x, y};
}

/*!@brief Returns a swizzled vector of x, z, and y.
 * @sa yxz, zxy, yzx, zyx, xy, yx
 */
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::xzy() {
	return Vector3<T>{x, z, y};
}

/*!@brief Returns a swizzled vector of y, z, and x.
 * @sa yxz, zxy, xzy, zyx, xy, yx
 */
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::yzx() {
	return Vector3<T>{y, z, x};
}

/*!@brief Returns a swizzled vector of z, y, and x.
 * @sa yxz, zxy, xzy, yzx, xy, yx
 */
TemplateType
Estro::Vector3<T> Estro::Vector3<T>::zyx() {
	return Vector3<T>{z, y, x};
}

/*!@brief Returns a Vector2 of the x and y values.
 * @sa yxz, zxy, xzy, yzx, zyx, yx
 */
TemplateType
Estro::Vector2<T> Estro::Vector3<T>::xy() {
	return Vector2<T>{x, y};
}

/*!@brief Returns a Vector2 of the y and x values.
 * @sa yxz, zxy, xzy, yzx, zyx, xy
 */
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