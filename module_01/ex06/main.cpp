/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:05:55 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/27 11:27:48 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc < 2){
		std::cout << "[ INTERESTING HARL HAS NOTHING TO COMPLAIN ABOUT ]" << std::endl;
		return (0);
	}
	if (argc > 2){
		std::cout << "[ HARL OVERLOAD SHUTTING DOWN!!! ]" << std::endl;
		return  (0);
	}
	std::string level = argv[1];
	harl.complain(level);
	return (0);
}
