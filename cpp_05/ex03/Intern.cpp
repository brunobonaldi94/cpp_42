/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:25:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/13 00:39:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called!" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called!" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called!" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern Assignation operator called!" << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

AForm * Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}
AForm * Intern::createRobotomyRequest(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::createPresidentialPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

bool Intern::compareToLowerCase(std::string str1, std::string str2)
{
	if (str1.size() != str2.size())
		return false;
	for (size_t i = 0; i < str1.size(); i++)
	{
		if (std::tolower(str1[i]) != std::tolower(str2[i]))
			return false;
	}
	return true;
}

AForm * Intern::makeForm(std::string formName, std::string target)
{

	int const formQty = 3;
	std::string formNames[formQty] = { 
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*formCreation[formQty])(std::string target) = { 
		&Intern::createShrubbery, 
		&Intern::createRobotomyRequest, 
		&Intern::createPresidentialPardon,
	};
	for (int i = 0; i < formQty; i++)
	{
		if (compareToLowerCase(formName, formNames[i]))
		{
			std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
			return (this->*formCreation[i])(target);
		}
	}
	throw Intern::FormNotFoundException(formName);
}

Intern::FormNotFoundException::FormNotFoundException(std::string formName): _formName(formName)
{
	std::cout << "FormNotFoundException Named Constructor called" << std::endl;

}

Intern::FormNotFoundException::~FormNotFoundException() throw()
{
	std::cout << "FormNotFoundException Destructor called" << std::endl;
}

const char * Intern::FormNotFoundException::what() const throw()
{
	std::cerr << "Form Name: " << this->_formName << std::endl; 
	return "Intern: FormNotFoundException: Form Not Found";
}

std::string Intern::castIntToString(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}
