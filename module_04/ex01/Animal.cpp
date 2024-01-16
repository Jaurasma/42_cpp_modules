/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:03 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 13:39:05 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Super Animal"){
		std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy): type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		type = copy.type;
	}
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const{
	return this->type;
}

void Animal::makeSound(void) const{
		std::cout << "Animal sounds" << std::endl;

}
