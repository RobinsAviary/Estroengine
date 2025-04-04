#pragma once

template <typename T>
struct rVector2 {
	rVector2(T x = 0, T y = 0) : x(x), y(y) {}
	T x = 0;
	T y = 0;

	rVector2<T> yx() {
		return rVector2<T>{y, x};
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator+ (const rVector2<rhs_type>& rhs) {
		return rVector2<rhs_type>{ x + rhs.x, y + rhs.y };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator- (const rVector2<rhs_type>& rhs) {
		return rVector2<rhs_type>{ x - rhs.x, y - rhs.y };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator/ (const rVector2<rhs_type>& rhs) {
		return rVector2<rhs_type>{ x / rhs.x, y / rhs.y };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator* (const rVector2<rhs_type>& rhs) {
		return rVector2<rhs_type>{ x * rhs.x, y * rhs.y };
	}

	template <typename rhs_type>
	inline void operator+=(rVector2<rhs_type>& rhs) {
		x += rhs.x;
		y += rhs.y;
	}

	template <typename rhs_type>
	inline void operator-=(rVector2<rhs_type>& rhs) {
		x -= rhs.x;
		y -= rhs.y;
	}

	template <typename rhs_type>
	inline void operator*=(rVector2<rhs_type>& rhs) {
		x *= rhs.x;
		y *= rhs.y;
	}

	template <typename rhs_type>
	inline void operator/=(rVector2<rhs_type>& rhs) {
		x /= rhs.x;
		y /= rhs.y;
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator+ (const rhs_type& rhs) {
		return rVector2<rhs_type>{ x + rhs, y + rhs };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator- (const rhs_type& rhs) {
		return rVector2<rhs_type>{ x - rhs, y - rhs };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator* (const rhs_type& rhs) {
		return rVector2<rhs_type>{ x * rhs, y * rhs };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator/ (const rhs_type& rhs) {
		return rVector2<rhs_type>{ x / rhs, y / rhs };
	}

	template <typename rhs_type>
	inline bool operator==(const rVector2<rhs_type>& rhs) {
		return (x == rhs.x && y == rhs.y);
	}

	template <typename rhs_type>
	inline bool operator!=(const rVector2<rhs_type>& rhs) {
		return (x != rhs.x || y != rhs.y);
	}

	template <typename _T>
	rVector2<_T> cast() {
		return rVector2<_T>{static_cast<_T>(x), static_cast<_T>(y)};
	}
};

rVector2<int> rVector2Zero = { 0, 0 };

rVector2<int> rVector2Left = { -1, 0 };
rVector2<int> rVector2Right = { 1, 0 };
rVector2<int> rVector2Up = { 0, -1 };
rVector2<int> rVector2Down = { 0, 1 };

rVector2<int> rVector2NE = { 1, -1 };
rVector2<int> rVector2SE = { 1, 1 };
rVector2<int> rVector2NW = { -1, -1 };
rVector2<int> rVector2SW = { -1, 1 };

template <typename T>
struct rVector3 {
	rVector3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
	T x = 0;
	T y = 0;
	T z = 0;

	// Basic swizzling
	rVector3<T> yxz() {
		return { y, x, z };
	}

	rVector3<T> zxy() {
		return { z, x, y };
	}

	rVector3<T> xzy() {
		return { x, z, y };
	}

	rVector3<T> yzx() {
		return { y, z, x };
	}

	rVector3<T> zyx() {
		return { z, y, x };
	}

	rVector2<T> xy() {
		return { x, y };
	}

	rVector2<T> yx() {
		return { y, x };
	}

	template <typename rhs_type>
	inline rVector3<rhs_type> operator+ (const rVector3<rhs_type>& rhs) {
		return rVector3<rhs_type>{ x + rhs.x, y + rhs.y, z + rhs.z };
	}

	template <typename rhs_type>
	inline rVector3<rhs_type> operator- (const rVector3<rhs_type>& rhs) {
		return rVector3<rhs_type>{ x - rhs.x, y - rhs.y, z - rhs.z };
	}

	template <typename rhs_type>
	inline rVector3<rhs_type> operator/ (const rVector3<rhs_type>& rhs) {
		return rVector3<rhs_type>{ x / rhs.x, y / rhs.y, z / rhs.z };
	}

	template <typename rhs_type>
	inline rVector3<rhs_type> operator* (const rVector3<rhs_type>& rhs) {
		return rVector3<rhs_type>{ x * rhs.x, y * rhs.y, z * rhs.z };
	}

	template <typename rhs_type>
	inline void operator+=(rVector3<rhs_type>& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	template <typename rhs_type>
	inline void operator-=(rVector3<rhs_type>& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	template <typename rhs_type>
	inline void operator*=(rVector3<rhs_type>& rhs) {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
	}

	template <typename rhs_type>
	inline void operator/=(rVector3<rhs_type>& rhs) {
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
	}

	template <typename rhs_type>
	inline bool operator==(const rVector3<rhs_type>& rhs) {
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}

	template <typename rhs_type>
	inline bool operator!=(const rVector3<rhs_type>& rhs) {
		return (x != rhs.x || y != rhs.y || z != rhs.z);
	}

	template <typename T>
	rVector2<T> cast() {
		return rVector3<T>{static_cast<T>(x), static_cast<T>(y), static_cast<T>(z)};
	}
};