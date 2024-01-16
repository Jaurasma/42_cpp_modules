/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:47:52 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/15 12:14:05 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib> // For generating random numbers
#include <ctime>   // For seeding the random number generator
#include <limits> // For numeric_limits
#include <sstream> // For stringstream

void displayMenuScav() {
	std::cout << "Choose an action:\n"
			  << "1. Attack\n"
			  << "2. Repair\n"
			  << "3. Guard the gate\n"
			  << "4. Quit\n"
			  << "Enter your choice: ";
}

void displayMenuCalp() {
	std::cout << "Choose an action:\n"
			  << "1. Attack\n"
			  << "2. Repair\n"
			  << "3. Quit\n"
			  << "Enter your choice: ";
}

void displayMenuFrag() {
	std::cout << "Choose an action:\n"
			  << "1. Attack\n"
			  << "2. Repair\n"
			  << "3. Highfive\n"
			  << "4. Quit\n"
			  << "Enter your choice: ";
}
int getChoice() {
	std::string choice_str;
	std::getline(std::cin, choice_str);
	try {
		return std::stoi(choice_str);
	}
	catch (const std::invalid_argument& e) {
		return -1; // Invalid input
	}
}

std::string getTargetName() {
	std::string target;
	std::cout << "Enter target name: ";
	std::getline(std::cin, target);
	return target;
}

int getRepairAmount() {
	int amount = 0;
	std::string input;
	do {
		std::cout << "Enter the amount of hit points to repair: ";
		std::getline(std::cin, input);

		// Use stringstream for conversion to int
		std::stringstream ss(input);
		if (ss >> amount) {
			// Check if there is any trailing input after the integer
			char remaining;
			if (ss >> remaining) {
				std::cout << "Invalid input. Please enter a valid integer.\n";
				continue;
			}
			break; // Valid input, break the loop
		} else {
			std::cout << "Invalid input. Please enter a valid integer.\nPress return button if understood";
		}

		// Clear any remaining characters in the input buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	return amount;
}

int main() {
	std::string name;
	std::srand(static_cast<unsigned int>(std::time(0)));

	std::cout << "Choose your character:\n"
			  << "1. ScavTrap\n"
			  << "2. FragTrap\n"
			  << "3. ClapTrap\n"
			  << "Enter your choice: ";
	
	int characterChoice = getChoice();
	if (characterChoice != 1 && characterChoice != 2 && characterChoice != 3) {
		std::cout << "Invalid choice. Exiting the program.\n";
		return 0;
	}

	std::cout << "Give your character a name: ";
	std::getline(std::cin, name);
	
	if (characterChoice == 1) {
		ScavTrap scavTrap(name);
		while (true) {
			displayMenuScav();
			int choice = getChoice();
			if (choice > 4 || choice < 1) { // Updated to include the new option
				std::cout << "Not a correct choice" << std::endl;
				continue;
			}
			switch (choice) {
			case 1: {
				std::string target = getTargetName();
				scavTrap.attack(target);
				break;
			}
			case 2: {
			int repairAmount;
			do {
				repairAmount = getRepairAmount();
				if (repairAmount < 0) {
					std::cout << "Invalid repair amount. Please try again.\n";
				}
			} while (repairAmount < 0);
				scavTrap.beRepaired(static_cast<unsigned int>(repairAmount));
				break;
			}
			case 3: {
				scavTrap.guardGate(); // New option for the guardGate feature
				break;
			}
			case 4: {
				std::cout << "Exiting the program.\n";
				return 0;
			}
			}
			std::cout << "The evil baddy will now attack!" << std::endl;
			int randomAttack = std::rand() % 11;
			scavTrap.takeDamage(randomAttack);
		}
	}
	else if (characterChoice == 2) {
	FragTrap fragTrap(name);
	while (true) {
		displayMenuFrag();
		int choice = getChoice();
		if (choice > 4 || choice < 1) { // Updated to include the new option
			std::cout << "Not a correct choice" << std::endl;
			continue;
		}
		switch (choice) {
		case 1: {
			std::string target = getTargetName();
			fragTrap.attack(target);
			break;
		}
		case 2: {
			int repairAmount;
			do {
				repairAmount = getRepairAmount();
				if (repairAmount < 0) {
					std::cout << "Invalid repair amount. Please try again.\n";
				}
			} while (repairAmount < 0);
			fragTrap.beRepaired(static_cast<unsigned int>(repairAmount));
			break;
		}
		case 3: {
			fragTrap.highFivesGuys(); // New option for the guardGate feature
			break;
		}
		case 4: {
			std::cout << "Exiting the program.\n";
			return 0;
		}
		}
		std::cout << "The evil baddy will now attack!" << std::endl;
		int randomAttack = std::rand() % 11;
		fragTrap.takeDamage(randomAttack);
	}
}
	else 
	{
		ClapTrap clapTrap(name);
		while (true) {
		displayMenuCalp();
		int choice = getChoice();
		if (choice > 3 || choice < 1) {
			std::cout << "Not a correct choice" << std::endl;
			continue;
		}
		switch (choice) {
		case 1: {
			std::string target = getTargetName();
			clapTrap.attack(target);
			break;
		}
		case 2: {
			int repairAmount;
			do {
				repairAmount = getRepairAmount();
				if (repairAmount < 0) {
					std::cout << "Invalid repair amount. Please try again.\n";
				}
			} while (repairAmount < 0);
			clapTrap.beRepaired(static_cast<unsigned int>(repairAmount));
			break;
		}
		case 3: {
			std::cout << "Exiting the program.\n";
			return 0;
		}
		}
		std::cout << "The evil baddy will now attack!" << std::endl;
		int randomAttack = std::rand() % 21;
		clapTrap.takeDamage(randomAttack);
	}
	}
	return 0;
}