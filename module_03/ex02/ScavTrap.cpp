/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:49:58 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/04 16:05:25 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_gateStatus = false;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &copy) {
        ClapTrap::operator=(copy);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_gateStatus == true)
    {
        std::cout << "ScavTrap " << _name << " is guarding the gate so it cannot attack" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " cannot attack without energy points" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " cannot attack when destroyed" << std::endl;
        return;
    } else {
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks target " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate(void) {
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " cannot guard the gate without energy points" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is haunting the gate" << std::endl;
        return;
    }
    if (this->_gateStatus == false)
    {
        this->_gateStatus = true;
        std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
        this->_energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " is now in normal mode" << std::endl;
        this->_gateStatus = false;
        this->_energyPoints--;
    }
}
