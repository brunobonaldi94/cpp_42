/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:36:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/05 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Default Constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Named Constructor called!" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), src.getGrade(), src.getExec())
{
	std::cout << "PresidentialPardonForm Copy Constructor called!" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called!" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
		std::cout << "PresidentialPardonForm Copy Assignment called!" << std::endl;
	if (this != &rhs)
		this->_target = this->_target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try 
	{
		AForm::execute(executor);
		std::cout << GREEN << this->_target << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
	} 
	catch(std::exception &e) 
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

}
