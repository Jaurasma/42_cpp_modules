/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:15:05 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/25 14:31:12 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}
const std::string& Weapon::getType(void)
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}
