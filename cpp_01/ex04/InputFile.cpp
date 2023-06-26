/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:45:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/25 18:43:28 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputFile.hpp"

InputFile::InputFile(std::string file_name): _file_name(file_name)
{
	this->_file_exists = this->fileExists(file_name);
}

InputFile::~InputFile(){ }

bool InputFile::getFileExists()
{
	return this->_file_exists;
}
bool InputFile::fileExists( std::string file_name)
{
	std::ifstream file(file_name.c_str());
	if (!file.good())
		std::cout << "File " << file_name << " does not exist" << std::endl;
	return file.good();
}

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

std::string & InputFile::getFileName( void )
{
	return this->_file_name;
}
