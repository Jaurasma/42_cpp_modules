/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:57:31 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 14:53:12 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);

Zombie* newZombie(std::string name);

int main(void)
{
    Zombie *zombo = new Zombie("George A. Romero");
    zombo->announce();
    randomChump("Danny Boyle");
    delete zombo;
    return (0);
}