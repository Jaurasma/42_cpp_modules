/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:42:38 by jaurasma          #+#    #+#             */
/*   Updated: 2024/01/10 14:21:04 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange &copy){
        this->_database = copy._database;
}


BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &copy){
    if (this != &copy) {
        this->_database = copy._database;
    }
    return *this;
}
    

void BitcoinExchange::extractDatabase(){
    std::ifstream inputFile("data.csv");

    if (!inputFile.is_open()) {
        return throw OpeningFailed();
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        double rate;
        
        if (std::getline(iss, date, ',')) {
            iss >> rate;
            if (!iss.fail()) {
                this->_database[date] = rate;
            }
        } else {
            std::cout << "Invalid line format: " << line << std::endl;
        }
    }

    inputFile.close();
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int daysInMonth(int year, int month) {
    static const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysPerMonth[month];
    if (month == 2 && isLeapYear(year)) {
        days++;
    }
    return days;
}

static bool isValidDate(const std::string& dateStr) {
    int year, month, day;
    char dash;
    std::istringstream dateStream(dateStr);
    if (dateStream >> year >> dash >> month >> dash >> day) {
        if (month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth(year, month)) {
            return true;
        }
    }
    return false;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
        std::ifstream inputFileStream(inputFile.c_str());

        if (!inputFileStream.is_open()) {
            throw OpeningFailed();
        }

        std::string line;
        bool firstLine = true;
        while (std::getline(inputFileStream, line)) {
            if (firstLine) {
                firstLine = false;
                if (line != "date | value") {
                    throw InvalidHeaderFormat();
                }
                continue;
            }
            std::istringstream iss(line);
            std::string dateStr;
            double value;

            if (std::getline(iss, dateStr, '|') && iss >> value && iss.rdbuf()->in_avail() == 0) {
                if (!isValidDate(dateStr)) {
                    std::cout << "Error: invalid date format => " << dateStr << std::endl;
                    continue;
                }
                std::map<std::string, double>::iterator it = _database.lower_bound(dateStr);
                if (it == _database.begin() && dateStr < it->first) {
                    std::cout << "Error: no valid exchange rate found for date " << dateStr << std::endl;
                } else {
                    if (it != _database.begin() && it->first != dateStr) {
                        --it;  // Use the closest lower date
                    }
                    if (value < 0) {
                        std::cout << "Error: not a positive number." << std::endl;
                    } else if (value > INT_MAX) {
                        std::cout << "Error: too large a number." << std::endl;
                    } else {
                        double exchangeRate = it->second;
                        double result = value * exchangeRate;
                        std::cout << dateStr << " => " << value << " = " << result << std::endl;
                    }
                }
            } else {
                std::cout << "Error: bad input => " << line << std::endl;
            }
    }
    inputFileStream.close();



    
}

const char* BitcoinExchange::OpeningFailed::what() const throw() {
	return "Error: could not open file";
}


const char* BitcoinExchange::InvalidHeaderFormat::what() const throw() {
	return "Error: input file needs to start with date | value";
}