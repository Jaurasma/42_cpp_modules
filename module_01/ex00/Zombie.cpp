/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:57:25 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 17:30:16 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
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
