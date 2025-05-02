#pragma once

// Estrovector, created for estroengine by Robin <3

namespace Estro {
	template <typename T>
	struct Rectangle {
		Rectangle(T x = 0, T y = 0, T w = 0, T h = 0) : x(x), y(y), w(w), h(h) {}
		T x = 0;
		T y = 0;
		T w = 0;
		T h = 0;
	};

	template <typename T>
	struct Vector2 {
		Vector2(T x = 0, T y = 0) : x(x), y(y) {}
		T x = 0;
		T y = 0;

		Vector2<T> yx() {
			return Vector2<T>{y, x};
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator+ (const Vector2<rhs_type>& rhs) {
			return Vector2<rhs_type>{ x + rhs.x, y + rhs.y };
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator- (const Vector2<rhs_type>& rhs) {
			return Vector2<rhs_type>{ x - rhs.x, y - rhs.y };
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator/ (const Vector2<rhs_type>& rhs) {
			return Vector2<rhs_type>{ x / rhs.x, y / rhs.y };
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator* (const Vector2<rhs_type>& rhs) {
			return Vector2<rhs_type>{ x* rhs.x, y* rhs.y };
		}

		template <typename rhs_type>
		inline void operator+=(Vector2<rhs_type>& rhs) {
			x += rhs.x;
			y += rhs.y;
		}

		template <typename rhs_type>
		inline void operator-=(Vector2<rhs_type>& rhs) {
			x -= rhs.x;
			y -= rhs.y;
		}

		template <typename rhs_type>
		inline void operator*=(Vector2<rhs_type>& rhs) {
			x *= rhs.x;
			y *= rhs.y;
		}

		template <typename rhs_type>
		inline void operator/=(Vector2<rhs_type>& rhs) {
			x /= rhs.x;
			y /= rhs.y;
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator+ (const rhs_type& rhs) {
			return Vector2<rhs_type>{ x + rhs, y + rhs };
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator- (const rhs_type& rhs) {
			return Vector2<rhs_type>{ x - rhs, y - rhs };
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator* (const rhs_type& rhs) {
			return Vector2<rhs_type>{ x* rhs, y* rhs };
		}

		template <typename rhs_type>
		inline Vector2<rhs_type> operator/ (const rhs_type& rhs) {
			return Vector2<rhs_type>{ x / rhs, y / rhs };
		}

		template <typename rhs_type>
		inline bool operator==(const Vector2<rhs_type>& rhs) {
			return (x == rhs.x && y == rhs.y);
		}

		template <typename rhs_type>
		inline bool operator!=(const Vector2<rhs_type>& rhs) {
			return (x != rhs.x || y != rhs.y);
		}

		template <typename _T>
		Vector2<_T> cast() {
			return Vector2<_T>{static_cast<_T>(x), static_cast<_T>(y)};
		}

		bool isInside(Rectangle<T> rectangle) {
			if (x >= rectangle.x && x < rectangle.x + rectangle.w) {
				if (y >= rectangle.y && y < rectangle.y + rectangle.h) {
					return true;
				}
			}

			return false;
		}
	};

	Vector2<int> Vector2Zero = { 0, 0 };

	Vector2<int> Vector2Left = { -1, 0 };
	Vector2<int> Vector2Right = { 1, 0 };
	Vector2<int> Vector2Up = { 0, -1 };
	Vector2<int> Vector2Down = { 0, 1 };

	Vector2<int> Vector2NE = { 1, -1 };
	Vector2<int> Vector2SE = { 1, 1 };
	Vector2<int> Vector2NW = { -1, -1 };
	Vector2<int> Vector2SW = { -1, 1 };

	template <typename T>
	struct Vector3 {
		Vector3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
		T x = 0;
		T y = 0;
		T z = 0;

		Vector3(Vector2<T> vector = { 0, 0 }) {
			x = vector.x;
			y = vector.y;
		}

		// Basic swizzling
		Vector3<T> yxz() {
			return { y, x, z };
		}

		Vector3<T> zxy() {
			return { z, x, y };
		}

		Vector3<T> xzy() {
			return { x, z, y };
		}

		Vector3<T> yzx() {
			return { y, z, x };
		}

		Vector3<T> zyx() {
			return { z, y, x };
		}

		Vector2<T> xy() {
			return { x, y };
		}

		Vector2<T> yx() {
			return { y, x };
		}

		template <typename rhs_type>
		inline Vector3<rhs_type> operator+ (const Vector3<rhs_type>& rhs) {
			return Vector3<rhs_type>{ x + rhs.x, y + rhs.y, z + rhs.z };
		}

		template <typename rhs_type>
		inline Vector3<rhs_type> operator- (const Vector3<rhs_type>& rhs) {
			return Vector3<rhs_type>{ x - rhs.x, y - rhs.y, z - rhs.z };
		}

		template <typename rhs_type>
		inline Vector3<rhs_type> operator/ (const Vector3<rhs_type>& rhs) {
			return Vector3<rhs_type>{ x / rhs.x, y / rhs.y, z / rhs.z };
		}

		template <typename rhs_type>
		inline Vector3<rhs_type> operator* (const Vector3<rhs_type>& rhs) {
			return Vector3<rhs_type>{ x* rhs.x, y* rhs.y, z* rhs.z };
		}

		template <typename rhs_type>
		inline void operator+=(Vector3<rhs_type>& rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
		}

		template <typename rhs_type>
		inline void operator-=(Vector3<rhs_type>& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
		}

		template <typename rhs_type>
		inline void operator*=(Vector3<rhs_type>& rhs) {
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
		}

		template <typename rhs_type>
		inline void operator/=(Vector3<rhs_type>& rhs) {
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
		}

		template <typename rhs_type>
		inline bool operator==(const Vector3<rhs_type>& rhs) {
			return (x == rhs.x && y == rhs.y && z == rhs.z);
		}

		template <typename rhs_type>
		inline bool operator!=(const Vector3<rhs_type>& rhs) {
			return (x != rhs.x || y != rhs.y || z != rhs.z);
		}

		template <typename T>
		Vector2<T> cast() {
			return Vector3<T>{static_cast<T>(x), static_cast<T>(y), static_cast<T>(z)};
		}
	};
}