/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:10 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 14:31:15 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal {
		protected:
				std::string type;
		public:
				Animal();
				Animal(const Animal& copy);
				Animal &operator=(const Animal& copy);
				virtual ~Animal();
				std::string getType(void) const;
				virtual void makeSound(void) const = 0;
};

#endif
