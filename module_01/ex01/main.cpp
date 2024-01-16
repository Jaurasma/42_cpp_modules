/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:06:34 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/27 11:34:02 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int	size;

	size = 10;
	Zombie *horde = zombieHorde(size, "Bombie The Zombie");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
