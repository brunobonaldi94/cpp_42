/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:45:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 23:31:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputFile.hpp"

InputFile::InputFile(std::string file_name): _file_name(file_name) { }

InputFile::~InputFile(){ }

std::string InputFile::readFile()
{
	std::string	line;
	std::string	all_lines = "";

	this->_input_file_stream.open(this->_file_name.c_str());

	if (this->_input_file_stream.is_open())
	{
		while (getline(this->_input_file_stream, line))
		{
			all_lines += line;
			if (!this->_input_file_stream.eof())
				all_lines += "\n";
		}
	}
	else 
		std::cout << "Unable to open the file" << std::endl;

	this->_input_file_stream.close();
	return all_lines;
}
