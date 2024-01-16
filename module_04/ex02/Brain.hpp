/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:42:18 by jaurasma          #+#    #+#             */
/*   Updated: 2023/08/16 13:47:41 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class Brain {
		protected:
				std::string ideas[100];
		public:
				Brain();
				Brain(const Brain& copy);
				Brain &operator=(const Brain& copy);
				~Brain();
};

#endif
