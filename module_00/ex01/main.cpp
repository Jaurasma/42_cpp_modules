/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:19:35 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 11:11:28 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string searchindex;
	int			index;
	std::string input;
	std::string data[5];
	std::string addmessages[5];

	std::cout<<"Welcome to PHONENBOOK98 created by jaurasma"<< std::endl;
	addmessages[0] = "first name: ";
	addmessages[1] = "last name: ";
	addmessages[2] = "nickname: ";
	addmessages[3] = "phone number: ";
	addmessages[4] = "darkest secret: ";
	do
	{
		std::cout<<"Please ADD, SEARCH or EXIT"<< std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			for(int i = 0; i < 5; i++)
			{
				std::cout<<addmessages[i];
				std::getline(std::cin, data[i]);
				if (!data[i].empty())
					continue ;
				std::cout<<"please input something"<<std::endl;
				i--;
			}
			phonebook.AddData(data);
		}
		else if (input == "SEARCH")
		{
			if  (phonebook.get_size() > 0)
			{
				std::cout << "|    INEDX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
				phonebook.SearchResult();
				std::cout << "Insert index: ";
				std::getline(std::cin, searchindex);
				try
				{
					index = std::stoi(searchindex);
					phonebook.PrintContact(index);
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << "Invalid input. Please enter a valid index." << std::endl;
				}
			}
			else
				std::cout << "No results" << std::endl;
		}
	}
	while (input != "EXIT");
	return(0);
}
