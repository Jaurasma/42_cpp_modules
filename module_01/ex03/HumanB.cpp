/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:14:29 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/25 14:32:11 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
    this->_name = name;
    std::cout << "object HumanB " << _name << " created whitout a weapon" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "object HumanB " << _name << " destroyed" << std::endl;
}

void    HumanB::attack()
{
    if (this->_weapon)
    {
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << _name << " cannot attack without a weapon and runs to the nearest dumpster" << std::endl;
    }
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
