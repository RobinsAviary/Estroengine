#pragma once

#include "estrocolors.hpp"
#include "estrovector.hpp"
#include <list>
#include <algorithm>
#include <string>

// Estrotypes, created for estroengine by Robin <3

struct rTransform {
	rTransform(rVector3<float> position, rVector3<float> rotation) : position(position), rotation(rotation) {}
	rVector3<float> position;
	rVector3<float> rotation;
};

template <typename T>
struct rRectangle {
	rRectangle(T x = 0, T y = 0, T w = 0, T h = 0) : x(x), y(y), w(w), h(h) {}
	T x = 0;
	T y = 0;
	T w = 0;
	T h = 0;
};

class rAsset {
public:
	virtual bool load(std::string filename) = 0;

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

	bool has(T val) {
		return (std::find(list.begin(), list.end(), val) != list.end());
	}

protected:
	std::list<T> list;
};

template <typename T> 
class rGrid {
public:
	rGrid() {
		resize(rVector2<unsigned int>{0, 0});
	}

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

	void fill(T value) {
		setAll(value);
	}

	void setAll(T value) {
		std::fill(list.begin(), list.end(), value);
	}

	void set(rVector2<unsigned int> position, T value) {
		list.set(getIndex(position), value);
	}

	T get(rVector2<unsigned int> position) {
		return list.at(getIndex(position));
	}

	T at(rVector2<unsigned int> position) {
		return get(position);
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