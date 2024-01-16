/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:45:55 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 11:05:36 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK
#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
	private:
	int		size;
	Contact	contacts[8];
	int		index;
	
	public:
	PhoneBook() : size (0), index (0) {}
	void	AddData(std::string data[5]);
	void	SearchResult();
	void	PrintContact(int searchindex);
	int 	get_size(void) const;
};

#endif