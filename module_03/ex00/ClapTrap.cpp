/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:47:30 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/15 12:17:18 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _hitPoints(10), _energyPoints(10), _attackDamage(0){
	this->_name = name;
	std::cout << "Default constructor called" << std::endl;
} 

ClapTrap::ClapTrap(const ClapTrap& copy): _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        // Perform deep copy of member variables
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack without energy points" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout  << "ClapTrap " << _name << " cannot attack without hit points" << std::endl;
		return ;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks target " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount == 0) {
        std::cout << "ClapTrap " << _name << " takes no damage." << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed, could you please stop, this does not make any sense" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    if (_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " is destroyed, are you proud of yourself?" << std::endl;
    } 
	else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot be reapaired without energy points" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0) {
		std::cout  << "ClapTrap " << _name << " is already dead, zombies were in module 01" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " gets repaired by " << amount << " hit points" << std::endl;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " has now " << _hitPoints << " hit points" << std::endl;
	return ;
}
