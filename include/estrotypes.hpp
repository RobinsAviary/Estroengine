#pragma once

#include "estrocolors.hpp"
#include <list>
#include <algorithm>

typedef struct rVector2 {
	rVector2(int x = 0, int y = 0) : x(x), y(y) {}
	int x = 0;
	int y = 0;
} rVector2;

rVector2 rVector2Zero = { 0, 0 };

rVector2 rVector2Left = { -1, 0 };
rVector2 rVector2Right = { 1, 0 };
rVector2 rVector2Up = { 0, -1 };
rVector2 rVector2Down = { 0, 1 };

rVector2 rVector2NE = { 1, -1 };
rVector2 rVector2SE = { 1, 1 };
rVector2 rVector2NW = { -1, -1 };
rVector2 rVector2SW = { -1, 1 };

typedef struct rVector3 {
	rVector3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
	int x = 0;
	int y = 0;
	int z = 0;
} rVector3;

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

// A buncha inline implimentations that are implied in most languages.

inline rVector2 operator+(const rVector2& lhs, const rVector2& rhs) {
	return rVector2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

inline rVector2 operator-(const rVector2& lhs, const rVector2& rhs) {
	return rVector2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

inline rVector2 operator*(const rVector2& lhs, const rVector2& rhs) {
	return rVector2{ lhs.x * rhs.x, lhs.y * rhs.y };
}

inline rVector2 operator/(const rVector2& lhs, const rVector2& rhs) {
	return rVector2{ lhs.x / rhs.x, lhs.y / rhs.y };
}

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

inline rVector2 operator+(const rVector2& lhs, const int& rhs) {
	return rVector2{ lhs.x + rhs, lhs.y + rhs };
}

inline rVector2 operator-(const rVector2& lhs, const int& rhs) {
	return rVector2{ lhs.x - rhs, lhs.y - rhs };
}

inline rVector2 operator/(const rVector2& lhs, const int& rhs) {
	return rVector2{ lhs.x / rhs, lhs.y / rhs };
}

inline rVector2 operator*(const rVector2& lhs, const int& rhs) {
	return rVector2{ lhs.x * rhs, lhs.y * rhs };
}

inline rVector3 operator+(const rVector3& lhs, const int& rhs) {
	return rVector3{ lhs.x + rhs, lhs.y + rhs };
}

inline rVector3 operator-(const rVector3& lhs, const int& rhs) {
	return rVector3{ lhs.x - rhs, lhs.y - rhs };
}

inline rVector3 operator/(const rVector3& lhs, const int& rhs) {
	return rVector3{ lhs.x / rhs, lhs.y / rhs };
}

inline rVector3 operator*(const rVector3& lhs, const int& rhs) {
	return rVector3{ lhs.x * rhs, lhs.y * rhs };
}

inline void operator+=(rVector2& lhs, rVector2& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
}

inline void operator-=(rVector2& lhs, rVector2& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
}

inline void operator*=(rVector2& lhs, rVector2& rhs) {
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
}

inline void operator/=(rVector2& lhs, rVector2& rhs) {
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
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

inline bool operator==(const rVector2& lhs, const rVector2& rhs) {
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

inline bool operator!=(const rVector2& lhs, const rVector2& rhs) {
	return (lhs.x != rhs.x || lhs.y != rhs.y);
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
	/*inline void operator=(rList& rhs) {
		//clear();

		for (auto item : rhs.getBase()) {
			add(item);
		}
	}*/

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

protected:
	std::list<T> list;
};