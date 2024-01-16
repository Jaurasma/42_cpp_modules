/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:39:29 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/17 13:36:29 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
		private:
				Brain* brain;
		public:
				Cat();
				Cat(const Cat& copy);
				Cat &operator=(const Cat& copy);
				~Cat();
				void makeSound() const;
};

#endif
 