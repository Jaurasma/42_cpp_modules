/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:43 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/17 13:36:53 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
		private:
				Brain* brain;
		public:
				Dog();
				Dog(const Dog& copy);
				Dog &operator=(const Dog& copy);
				~Dog();
				void makeSound() const;
};

#endif
