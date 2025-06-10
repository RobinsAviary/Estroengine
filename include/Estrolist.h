#pragma once

#include <algorithm>
#include <list>

#include "Estrodefs.h"

#define ListIterator std::list<T>::iterator

// Due to a quirk in C++ builds system templated objects must be implemented in their header file.

// Interface

namespace Estro {
	TemplateType
	class List {
		public:
			/*!@brief Returns the std::list that makes up this list internally.
			@return The std::list that this list uses internally.
			*/
			std::list<T> getInternal();

			void add(T value);
			void remove(T value);
			void erase(unsigned int index);
			bool has(T value);
			void insert(unsigned int index, T value);
			void pushBack(T value);
			void pushFront(T value);

			/*!@brief Appends a list to the end of another list.
			@param _list The list to append to the other.
			*/
			void append(List<T> _list);
			//void prepend(List<T> _list);

			/*!@brief Clears the list of all values.
			*/
			void clear();

			/*!@brief Find the index of the specified value in the list.

			Returns zero if the value is not found, so use ::has() or ::count() in order to check if the value is in the list first.
			@param value Value to search for.
			@return Index of the value in the list.
			*/
			unsigned int find(T value);

			/*!@brief Find the indices of a value in the list.
			@param value Value to search for.
			@return A List of indices in the list that match the given value.
			*/
			List<unsigned int> findAll(T value);

			/*!@brief Get the number of items in the list.
			@return The number of items in the list.
			*/
			unsigned int size();

			/*!@brief Get the number of times a given value appears in the list.
			@return The number of times the given value appears in the list.
			*/
			unsigned int count(T value);

			typename std::list<T>::iterator begin();

			typename std::list<T>::iterator end();

			/*!@brief Remove the first item of the list.*/
			void popFront();
			/*!@brief Remove the last item of the list.*/
			void popBack();
			/*!@brief Get the first item of the list.
			@return The first item of the list.
			*/
			T front();
			/*!@brief Get the last item of the list.
			@return The last item of the list.
			*/
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