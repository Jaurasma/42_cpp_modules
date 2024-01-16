/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:06:28 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/25 14:05:48 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout<<"Zombie object " << _name << " created" << std::endl;
}

Zombie::Zombie(void)
{
	this->_name = "Not named";
	std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout<<"Zombie object " << _name << " destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout<< _name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}
