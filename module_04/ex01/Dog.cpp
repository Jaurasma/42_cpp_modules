/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:35 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 14:26:03 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain) {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal() {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
    if (this->brain)
        delete brain;
    this->brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog& copy) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &copy) {
        Dog::operator=(copy);
        if (this->brain)
            delete brain;
        this->brain = new Brain(*copy.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void  Dog::makeSound() const{
    std::cout << "BARK" << std::endl;
}
