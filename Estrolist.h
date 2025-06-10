#pragma once

#include <algorithm>
#include <list>

#include "Estrodefs.h" // For TemplateType

#define ListIterator std::list<T>::iterator

// Due to a quirk in C++ builds system templated objects must be implemented in their header file.

// Interface

namespace Estro {
	TemplateType
	class List {
		public:
			std::list<T> getInternal();

			void add(T value);
			void remove(T value);
			void erase(unsigned int index);
			bool has(T value);
			void insert(unsigned int index, T value);
			void pushBack(T value);
			void pushFront(T value);

			void append(List<T> _list);
			//void prepend(List<T> _list);

			void clear();

			unsigned int find(T value);
			List<unsigned int> findAll(T value);

			unsigned int size();
			inline unsigned int length(){ return size(); }
			unsigned int count(T value);

			std::list<T>::iterator begin();
			std::list<T>::iterator end();

			void popFront();
			void popBack();
			T front();
			T back();
			T at(unsigned int index);
			void set(unsigned int, T value);

		private:


		protected:
			std::list<T> list;
	};
}

// Implementations

using namespace Estro;

TemplateType
void List<T>::append(List<T> _list) {
	for (T item : _list) {
		add(item);
	}
}

TemplateType
unsigned int List<T>::size() {
	return static_cast<int>(list.size());
}

TemplateType
void List<T>::clear() {
	list.clear();
}

TemplateType
std::list<T> List<T>::getInternal() {
	return list;
}

TemplateType
void List<T>::add(T value) {
	list.push_back(value);
}

TemplateType
void List<T>::pushBack(T value) {
	list.push_back(value);
}

TemplateType
void List<T>::pushFront(T value){
	list.push_front(value);
}

TemplateType
void List<T>::popBack() {
	list.pop_back();
}

TemplateType
void List<T>::popFront() {
	list.pop_front();
}

TemplateType
T List<T>::front() {
	return list.front();
}

TemplateType
T List<T>::back() {
	return list.back();
}

TemplateType
void List<T>::remove(T value) {
	list.remove(value);
}

TemplateType
void List<T>::erase(unsigned int index) {
	auto iter = list.begin();
	advance(iter, index);
	list.erase(iter); // Place last element at the end of the list
	popBack(); // Remove last element
}

TemplateType
bool List<T>::has(T value) {
	for (T item : list) {
		if (item == value) {
			return true;
		}
	}

	return false;
}

TemplateType
void List<T>::insert(unsigned int index, T value) {
	auto iter = list.begin();

	advance(iter, index);
	list.insert(iter, value);
}

TemplateType
T List<T>::at(unsigned int index) {
	return *next(list.begin(), index);
}

TemplateType
void List<T>::set(unsigned int index, T value) {
	auto iter = list.begin();
	advance(iter, index);
	*iter = value;
}

TemplateType
ListIterator List<T>::begin() {
	return list.begin();
}

TemplateType
ListIterator List<T>::end() {
	return list.end();
}

TemplateType
unsigned int List<T>::find(T value) {
	unsigned int result = 0;
	
	for (T item : list) {
		if (item == value) {
			return result;
		}

		result++;
	}

	return NULL;
}

TemplateType
List<unsigned int> List<T>::findAll(T value) {
	unsigned int index = 0;
	List<unsigned int> result;

	for (T item : list) {
		if (item == value) {
			result.add(index);
		}

		index++;
	}

	return result;
}

TemplateType
unsigned int List<T>::count(T value) {
	unsigned int result = 0;
	
	for (T item : list) {
		if (item == value) {
			result++;
		}
	}

	return result;
}