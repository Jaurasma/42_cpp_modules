/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:42:35 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:22:16 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>

class BitcoinExchange {
    private:
    std::map<std::string, double> _database;
    BitcoinExchange(BitcoinExchange &copy);
    BitcoinExchange& operator=(BitcoinExchange &copy);

    public:
    BitcoinExchange(void);
    ~BitcoinExchange(void);
    void extractDatabase(void);
    void processInput(const std::string& inputFile);
    class OpeningFailed : public std::exception { 
        public:
            virtual const char* what() const throw();
    };
    class InvalidHeaderFormat : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif
