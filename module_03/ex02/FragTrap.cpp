/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:20 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/04 15:49:13 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy) {
        ClapTrap::operator=(copy);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot attack without energy points" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot attack without hit points" << std::endl;
        return;
    } else {
        _energyPoints--;
        std::cout << "FragTrap " << _name << " attacks target " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    static std::mt19937 rng(std::time(0)); // Seed the random number generator only once
    static std::uniform_int_distribution<int> dist(0, 9); // Uniform distribution for indices 0 to 9
    std::string highFiveRequests[] = {
    " Hey there, buddy! How about a high five to start the day?",
    " Great job, minion! High five for your epic skills!",
    " High five, partner! Let's conquer Pandora together!",
    " Up top, Vault Hunter! Time for a legendary high five!",
    " Looking good, amigo! How about a celebratory high five?",
    " Awesome work, recruit! High five for your bravery!",
    " You're a vault-cracking pro! High five, my friend!",
    " Ha! We make a great team! Let's seal it with a high five!",
    " You're on fire, Vault Hunter! High five for your firepower!",
    " Claptrap dance party! High five for joining the fun!"
    };
    int random_num = dist(rng);
     if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot highfive without energy points" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot highfive because it is dead" << std::endl;
        return;
    } else {
        _energyPoints--;
        std::cout << "FragTrap " << _name << highFiveRequests[random_num] << std::endl; //thanks gpt for the messages
    }   
}