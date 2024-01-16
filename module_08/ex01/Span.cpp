/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:47:21 by jaurasma          #+#    #+#             */
/*   Updated: 2023/12/08 16:08:37 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N): _N(N) {}

Span::~Span(){}

Span::Span(const Span& copy) {
    this->_N = copy._N;
    this->_data = copy._data;    
}

Span& Span::operator=(const Span& copy) {
    if (this != &copy) {
        this->_N = copy._N;
        this->_data = copy._data;    
    }
    return *this;
}

void Span::addNumber(int num){
    if (this->_data.size() >= this->_N)
        throw ContainerFull();
    _data.push_back(num);
}

void Span::addNumbers(int amount){
    srand(static_cast<unsigned int>(time(NULL)));
    if (this->_data.size() + amount > this->_N)
        throw ContainerWillBeTooFull();
    for (int i = 0; i < amount; i++) {
        _data.push_back(rand());
    }
}

int Span::shortestSpan() {
    if (this->_data.size() < 2)
        throw NoSpan();
    std::size_t shortestSpanValue = std::numeric_limits<std::size_t>::max();
    for (std::size_t i = 0; i  < _data.size(); i++){
        for (std::size_t j = i + 1; j  < _data.size(); j++){
            std::size_t span = (_data[j] > _data[i]) ? (_data[j] - _data[i]) : (_data[i] - _data[j]);
            shortestSpanValue = std::min(span, shortestSpanValue);
        }
    }
    return shortestSpanValue;
}

int Span::longestSpan() {
    if (this->_data.size() < 2)
        throw NoSpan();
    std::size_t longestSpanValue = std::numeric_limits<std::size_t>::min();
    for (std::size_t i = 0; i  < _data.size(); i++){
        for (std::size_t j = i + 1; j  < _data.size(); j++){
            std::size_t span = (_data[j] > _data[i]) ? (_data[j] - _data[i]) : (_data[i] - _data[j]);
            longestSpanValue = std::max(span, longestSpanValue);
        }
    }
    return longestSpanValue;
}

const char* Span::ContainerWillBeTooFull::what() const throw() {
	return "Container will be too full";
}

const char* Span::ContainerFull::what() const throw() {
	return "Container is full";
}

const char* Span::NoSpan::what() const throw() {
	return "There is no span";
}