/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/17 13:25:54 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp" 

int main() {
    const int numAnimals = 10; 
    
    Animal* animals[numAnimals];
    //
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; ++i) {
        std::cout << "Type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    // Create a deep copy of the animal and test deep copy by making a sound
    for (int i = 0; i < numAnimals; ++i) {
        Animal* copy = new Animal(*animals[i]); 
        delete animals[i]; 
        copy->makeSound();
        delete copy;
    }

    return 0;
}
