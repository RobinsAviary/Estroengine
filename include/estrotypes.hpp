#pragma once

#include "estrocolors.hpp"
#include <list>
#include <algorithm>
#include <string>

template <typename T>
struct rVector2 {
	rVector2(int x = 0, int y = 0) : x(x), y(y) {}
	int x = 0;
	int y = 0;

	template <typename rhs_type>
	inline rVector2<rhs_type> operator+ (const rVector2<rhs_type>& rhs) {
		return rVector2{ x + rhs.x, y + rhs.y };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator- (const rVector2<rhs_type>& rhs) {
		return rVector2{ x - rhs.x, y - rhs.y };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator/ (const rVector2<rhs_type>& rhs) {
		return rVector2{ x / rhs.x, y / rhs.y };
	}

	template <typename rhs_type>
	inline rVector2<rhs_type> operator* (const rVector2<rhs_type>& rhs) {
		return rVector2{ x * rhs.x, y * rhs.y };
	}

	template <typename rhs_type>
	inline void operator+=(rVector2& rhs) {
		x += rhs.x;
		y += rhs.y;
	}

	template <typename rhs_type>
	inline void operator-=(rVector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;
	}

	template <typename rhs_type>
	inline void operator*=(rVector2& rhs) {
		x *= rhs.x;
		y *= rhs.y;
	}

	template <typename rhs_type>
	inline void operator/=(rVector2& rhs) {
		x /= rhs.x;
		y /= rhs.y;
	}

	template <typename rhs_type>
	inline bool operator==(const rVector2& rhs) {
		return (x == rhs.x && y == rhs.y);
	}

	template <typename rhs_type>
	inline bool operator!=(const rVector2& rhs) {
		return (x != rhs.x || y != rhs.y);
	}

	template <typename T>
	rVector2<T> cast() {
		return rVector2<T>{static_cast<T>(x), static_cast<T>(y)};
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

struct rVector3 {
	rVector3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
	int x = 0;
	int y = 0;
	int z = 0;
};

typedef struct rTransform {
	rTransform(rVector3 position, rVector3 rotation) : position(position), rotation(rotation) {}
	rVector3 position;
	rVector3 rotation;
} rTransform;

typedef struct rRectangle {
	rRectangle(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), w(w), h(h) {}
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
} rRectangle;

inline rVector3 operator+(const rVector3& lhs, const rVector3& rhs) {
	return rVector3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

inline rVector3 operator-(const rVector3& lhs, const rVector3& rhs) {
	return rVector3{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

inline rVector3 operator*(const rVector3& lhs, const rVector3& rhs) {
	return rVector3{ lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

inline rVector3 operator/(const rVector3& lhs, const rVector3& rhs) {
	return rVector3{ lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
}

inline void operator+=(rVector3& lhs, rVector3& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z += rhs.z;
}

inline void operator-=(rVector3& lhs, rVector3& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z -= rhs.z;
}

inline void operator*=(rVector3& lhs, rVector3& rhs) {
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	lhs.z *= rhs.z;
}

inline void operator/=(rVector3& lhs, rVector3& rhs) {
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
	lhs.z /= rhs.z;
}

inline bool operator==(const rVector3& lhs, const rVector3& rhs) {
	return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}

inline bool operator!=(const rVector3& lhs, const rVector3& rhs) {
	return (lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z);
}

inline bool operator==(const rColor& lhs, const rColor& rhs) {
	return { lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a };
}

inline bool operator!=(const rColor& lhs, const rColor& rhs) {
	return { lhs.r != rhs.r || lhs.g != rhs.g || lhs.b != rhs.b || lhs.a != rhs.a };
}

class rAsset {
public:
	virtual void load(std::string filename) = 0;

	bool isValid() {
		return valid;
	}

	~rAsset() {
		valid = false;
	}
protected:
	bool valid = false;
};

template <typename T>
class rList {
public:
	void add(T item) {
		list.push_back(item);
	}

	void insert(int index, T item) {
		auto iter = list.begin();
		advance(iter, index);
		list.insert(iter, item);
	}

	T at(int index) {
		auto iter = list.begin();
		advance(iter, index);

		return *iter;
	}

	void set(int index, T item) {
		auto iter = list.begin();
		advance(iter, index);
		*iter = item;
	}

	int size() {
		return list.size();
	}

	void pushBack(T item) {
		list.push_back(item);
	}

	void pushFront(T item) {
		list.push_front(item);
	}

	void popBack() {
		list.pop_back();
	}

	void popFront() {
		list.pop_front();
	}

	void erase(int index) {
		auto iter = list.begin();
		advance(iter, index);
		list.erase(iter);
	}

	void erase(T pointer) {
		list.remove(pointer);
	}

	auto begin() {
		return list.begin();
	}

	auto end() {
		return list.end();
	}

	T back() {
		return list.back();
	}
	
	T front() {
		return list.front();
	}

	void clear() {
		list.clear();
	}

	std::list<T> getBase() {
		return list;
	}

	void resize(int size, T val = NULL) {
		if (val) {
			list.resize(size, val);
		}
		else {
			list.resize(size);
		}
		
	}

protected:
	std::list<T> list;
};

template <typename T> 
class rGrid {
public:
	rGrid(rVector2<unsigned int> _size) {
		resize(_size);
	}

	void clear() {
		list.clear();
	}

	void resize(rVector2<unsigned int> _size, T val = NULL) {
		clear();
		// rList will check if val is valid
		size = _size;
		list.resize(size.x * size.y, val);
	}

	void set(rVector2<unsigned int> position, T val) {
		list[getIndex(position)] = val;
	}

	T get(rVector2<unsigned int> position) {
		return list[getIndex(position)];
	}

	rVector2<unsigned int> getSize() {
		return size;
	}

private:
	int getIndex(rVector2<unsigned int> position) {
		rVector2 size = getSize();

		return (position.x + (position.y * size.y));
	}

	rList<T> list;

	rVector2<unsigned int> size;
};