/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:27:52 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/05 13:53:12 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array(): _elements(NULL), _arraySize(0) {
	this->_elements = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): _arraySize(n) {
	this->_elements = new T[_arraySize];
}

template <typename T>
Array<T>::Array(const Array& copy) : _arraySize(copy._arraySize) {
	this->_elements = new T[_arraySize];
	for (unsigned int i = 0; i < _arraySize; ++i) {
		_elements[i] = copy._elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
	if (this != &copy) {
		delete[] _elements;
		_arraySize = copy._arraySize;
		_elements = new T[_arraySize];
		for (unsigned int i = 0; i < _arraySize; i++) {
			_elements[i] = copy._elements[i];
		}
	}
	return *this;  
}

template <typename T>
Array<T>::~Array() {
	if (this->_elements)
		delete[] this->_elements;
	return ;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_arraySize || index < 0)
		throw IndexOutOfBounds();
	return this->_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_arraySize || index < 0)
		throw IndexOutOfBounds();
	return this->_elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_arraySize;
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw() {
		return "Index is out of bounds";
}
