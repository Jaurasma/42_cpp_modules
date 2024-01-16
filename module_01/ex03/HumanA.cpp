/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:14:07 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/25 14:14:10 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
    std::cout << "object HumanA " << _name << " created with ";
    std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "object HumanA " << _name << " destroyed" << std::endl;
}

void    HumanA::attack(void)
{
     std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void    HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}
