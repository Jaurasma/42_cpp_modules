/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:22 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 14:27:32 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain) {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
	if (this->brain)
        delete brain;
    this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy) {
		Cat::operator=(copy);
        if (this->brain)
            delete brain;
        this->brain = new Brain(*copy.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void  Cat::makeSound() const{
	std::cout << "MEEOW" << std::endl;
}
