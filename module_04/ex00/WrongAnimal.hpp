/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:03 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/17 13:27:52 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal {
		protected:
				std::string type;
		public:
				WrongAnimal();
				WrongAnimal(const WrongAnimal& copy);
				WrongAnimal &operator=(const WrongAnimal& copy);
				~WrongAnimal();
				std::string getType(void) const;
				void makeSound(void) const;
};

#endif
