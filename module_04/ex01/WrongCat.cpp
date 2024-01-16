/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:16 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 13:40:18 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal() {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &copy) {
        WrongCat::operator=(copy);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void  WrongCat::makeSound() const{
    std::cout << "WOEEM" << std::endl;
}
