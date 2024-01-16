/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:43 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 11:23:59 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::get_size() const
{
	return (this->size);
}

void PhoneBook::AddData(std::string data[5])
{
	if (index == 8)
		index = 0;
	contacts[index].set_firstname(data[0]);
	contacts[index].set_lastname(data[1]);
	contacts[index].set_nickname(data[2]);
	contacts[index].set_phonenum(data[3]);
	contacts[index].set_secret(data[4]);
	contacts[index].set_index(index);
	index++;
	if (size <= 7)
		size++;
}

void PhoneBook::SearchResult()
{
	for (int i = 0; i < size; i++)
	{
		contacts[i].printTruncContact();
	}
}

void PhoneBook::PrintContact(int searchindex)
{
	if (searchindex > size - 1 || searchindex < 0)
	{
		std::cout << "Try to search again and input a proper index" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		contacts[searchindex].printFullContact();
		std::cout << std::endl;
	}
}
