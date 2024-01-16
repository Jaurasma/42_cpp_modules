/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:57 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 11:45:39 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::printName(const std::string& name)
{
	int NameLen = name.size();
	int WhiteSpace = 10 - NameLen;
	for (int i = 0; i < WhiteSpace; i++)
		std::cout << " ";
	std::cout << name;
	std::cout << "|";
}

void	Contact::printTruncContact()
{
	std::cout << "|        "<< index << "|";
	if (firstname.size() > 10)
		std::cout << firstname.substr(0, 9) << ".|";
	else
		printName(firstname);
	if (lastname.size() > 10)
		std::cout << lastname.substr(0, 9) << ".|";
	else
		printName(lastname);
	if (nickname.size() > 10)
		std::cout << nickname.substr(0, 9) << ".|";
	else
		printName(nickname);
	std::cout << std::endl;
}

void	Contact::printFullContact()
{
	std::cout << "First name:     " << firstname << std::endl;
	std::cout << "Last name:      " << lastname << std::endl;
	std::cout << "Nickname:       " << nickname << std::endl;
	std::cout << "Phonenumber:    " << phonenum << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

const	std::string& Contact::get_firstname()
{
	return(this->firstname);
}

const   std::string& Contact::get_lastname()
{
	return(this->lastname);
}

const   std::string& Contact::get_nickname()
{
	return(this->nickname);
}

const   std::string& Contact::get_phonenum()
{
	return(this->phonenum);
}

const   std::string& Contact::get_secret()
{
	return(this->secret);
}

const	int	Contact::get_index()
{
	return(this->index);
}

void	Contact::set_firstname(std::string firstname)
{
	this->firstname = firstname;
}

void	Contact::set_lastname(std::string lastname)
{
	this->lastname = lastname;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_phonenum(std::string phonenum)

{
	this->phonenum = phonenum;
}

void	Contact::set_secret(std::string secret)
{
	this->secret = secret;
}
void	Contact::set_index(int index)
{
	this->index = index;
}
