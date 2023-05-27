/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:41:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/25 18:31:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

MySed::MySed(const char* file_name, const char* s1, const char* s2)
{
	if (s1 == NULL || s2 == NULL || file_name == NULL)
		throw std::invalid_argument("it cannot be NULL");
	this->_s1 = static_cast<std::string>(s1);
	this->_s2 = static_cast<std::string>(s2);
	std::string	new_file_name = static_cast<std::string>(file_name);
	this->_input_file = new InputFile(new_file_name);
	if (this->_input_file->getFileExists())
		this->_output_file = new OutputFile(new_file_name + ".replace");
	else
		this->_output_file = NULL;
}

MySed::~MySed()
{
	delete this->_input_file;
	delete this->_output_file;
}

void	MySed::replaceS1byS2()
{
	if (this->_s1.empty() || this->_input_file == NULL || this->_output_file == NULL)
		return ;
	std::string	fileContent = this->_input_file->readFile();
	size_t	len_s1 = this->_s1.length();
	size_t 	found = 1;
	size_t	initial_pos = 0;
	std::string	result = "";
	while ((found = fileContent.find(this->_s1, initial_pos)) != std::string::npos)
	{
		int len = found - initial_pos;
		result += (fileContent.substr(initial_pos, len) + this->_s2);
		initial_pos = found + len_s1;
	}
	if (initial_pos < fileContent.length())
		result += fileContent.substr(initial_pos, fileContent.length() - initial_pos);
	this->_output_file->WriteFile(result);
}
