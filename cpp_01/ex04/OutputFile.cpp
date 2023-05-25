/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:45:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 23:41:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OutputFile.hpp"

OutputFile::OutputFile(std::string file_name): _file_name(file_name) { }
OutputFile::~OutputFile() { }

void OutputFile::WriteFile(std::string strToWrite)
{
	this->_output_file_stream.open(this->_file_name.c_str());
	if (this->_output_file_stream.is_open())
		this->_output_file_stream << strToWrite;
	else
		std::cout << "Unable to create the file" << std::endl;
	this->_output_file_stream.close();
}
