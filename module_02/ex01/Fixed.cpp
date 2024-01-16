/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:43:11 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/28 14:13:17 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/*Int constructor called
Float constructor called*/
const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    std::cout << "Int constructor called" << std::endl;
    this->_value = value * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &copy): _value(copy._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_value = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

int Fixed::toInt() const {
    return (_value >> _fractionalBits);
}

float Fixed::toFloat() const {
    return ((float)_value) / (float)(1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}