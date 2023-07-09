/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:36:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/08 23:17:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default Constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Named Constructor called!" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), src.getGrade(), src.getExec())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called!" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called!" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm Copy Assignment called!" << std::endl;
	if (this != &rhs)
		this->_target = this->_target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
		
	std::ofstream file(this->_target.c_str());
	if (file.is_open())
	{
		file << "      /\\      " << std::endl;
		file << "     /\\/\\     " << std::endl;
		file << "    /\\/\\/\\    " << std::endl;
		file << "   /\\/\\/\\/\\   " << std::endl;
		file << "  /\\/\\/\\/\\/\\  " << std::endl;
		file << " /\\/\\/\\/\\/\\/\\ " << std::endl;
		file << "/\\/\\/\\/\\/\\/\\/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file.close();
	}
}
