/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:41:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/25 00:08:47 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

MySed::MySed(std::string file_name, std::string s1, std::string s2): _s1(s1), _s2(s2)
{
	this->_input_file = new InputFile(file_name);
	this->_output_file = new OutputFile(file_name + ".replace");
}

MySed::~MySed()
{
	delete this->_input_file;
	delete this->_output_file;
}

void	MySed::replaceS1byS2()
{
	std::string	fileContent = this->_input_file->readFile();
	size_t	len_s1 = this->_s1.length();
	size_t 	found = 1;
	size_t	initial_pos = 0;
	std::string	result = "";
	while ((found = fileContent.find(this->_s1, initial_pos)) != std::string::npos)
	{
		result += fileContent.substr(initial_pos, found) + this->_s2;
		initial_pos += found + len_s1 + 1;
	}
	this->_output_file->WriteFile(result);
}
