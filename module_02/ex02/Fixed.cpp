/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:43:11 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/28 14:42:23 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed &copy) {
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
	return (out);
}

bool    Fixed::operator>(const Fixed  &copy) const{
	return (this->toFloat() > copy.toFloat());
}

bool    Fixed::operator<(const Fixed  &copy) const{
	return (this->toFloat() < copy.toFloat());
}

bool    Fixed::operator>=(const Fixed  &copy) const{
	return (this->toFloat() >= copy.toFloat());   
}

bool    Fixed::operator<=(const Fixed  &copy) const{
	return (this->toFloat() <= copy.toFloat());     
}

bool    Fixed::operator==(const Fixed  &copy) const{
	return (this->toFloat() == copy.toFloat());  
}

bool    Fixed::operator!=(const Fixed  &copy) const{
	return (this->toFloat() != copy.toFloat());  
}

Fixed    Fixed::operator+(const Fixed  &copy) const{
	return (this->toFloat() + copy.toFloat());
}

Fixed    Fixed::operator-(const Fixed  &copy) const{
	return (this->toFloat() - copy.toFloat());
}

Fixed    Fixed::operator*(const Fixed  &copy) const{
	return (this->toFloat() * copy.toFloat());
}

Fixed    Fixed::operator/(const Fixed  &copy) const{
	return (this->toFloat() / copy.toFloat());
}

Fixed& Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a.toFloat() <= b.toFloat())
		return (a);
	return(b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a.toFloat() <= b.toFloat())
		return (a);
	return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a.toFloat() >= b.toFloat())
		return (a);
	return(b);
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b){
	if (a.toFloat() >= b.toFloat())
		return (a);
	return(b);
}