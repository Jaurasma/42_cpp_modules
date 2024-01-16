/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:32 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 13:40:34 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* meta = new Animal();

    std::cout << std::endl;
    std::cout << "j is a " << j->getType() << std::endl;
    std::cout << "i is a " << i->getType() << std::endl;
    std::cout << "meta is a " << meta->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "j->makeSound():" << std::endl;
    j->makeSound();
    std::cout << "i->makeSound():" << std::endl;
    i->makeSound();
    std::cout << "meta->makeSound():" << std::endl;
    meta->makeSound();
    std::cout << std::endl;

    const WrongAnimal* wcat = new WrongCat();
    std::cout << "wcat is a " << wcat->getType() << std::endl;
    std::cout << "wcat->makeSound():" << std::endl;
    wcat->makeSound();
    std::cout << std::endl;

    delete j;
    delete i;
    delete meta;
    delete wcat;
    return 0;
}
