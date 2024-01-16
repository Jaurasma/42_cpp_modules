/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:00 by jaurasma          #+#    #+#             */
/*   Updated: 2023/07/25 15:55:43 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream input(filename);
	if (!input.is_open())
	{
		std::cerr << "Error: Unable to open input file: " << filename << std::endl;
		return ;
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream output(outputFilename);
	if (!output.is_open())
	{
		std::cerr << "Error: Unable to create output file: " << outputFilename << std::endl;
		input.close();
		return ;
	}
	std::string line;
	while (std::getline(input, line))
	{
		size_t pos = 0;
		std::stringstream result;
		while (pos < line.length())
		{
			size_t foundPos = line.find(s1, pos);
			if (foundPos == std::string::npos)
			{
				result << line.substr(pos);
				break ;
			}
			else
			{
				result << line.substr(pos, foundPos - pos);
				result << s2;
				pos = foundPos + s1.length();
			}
		}
		output << result.str() << std::endl;
	}
	input.close();
	output.close();
}

int main(int argc, char **argv) 
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replaceInFile(filename, s1, s2);
	return 0;
}
