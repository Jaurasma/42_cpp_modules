/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:47:12 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/24 11:30:11 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT
#include <string>
#include <iostream>

class Contact
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenum;
	std::string secret;
	int index;

	public:
	void printName(const std::string& name);
	void printTruncContact();
	void printFullContact();
	const   std::string& get_firstname();
	const   std::string& get_lastname();
	const   std::string& get_nickname();
	const   std::string& get_phonenum();
	const   std::string& get_secret();
	const	int	get_index();
	void	set_firstname(std::string firstname);
	void	set_lastname(std::string lastname);
	void	set_nickname(std::string nickname);
	void	set_phonenum(std::string phonenum);
	void	set_secret(std::string secret);
	void	set_index(int index);
};

#endif