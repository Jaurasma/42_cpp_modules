/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:42:09 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 13:51:03 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = copy.ideas[i];
    }
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}