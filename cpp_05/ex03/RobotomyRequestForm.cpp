/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:36:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/08 23:17:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Default Constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Named Constructor called!" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getGrade(), src.getExec())
{
	std::cout << "RobotomyRequestForm Copy Constructor called!" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called!" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
		std::cout << "RobotomyRequestForm Copy Assignment called!" << std::endl;
	if (this != &rhs)
		this->_target = this->_target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
			
	std::cout << "Bzz" << std::endl;
	srand((unsigned) time(NULL));
	int random = rand() % 2;
	if (random == 0)
		std::cout << GREEN << this->_target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << this->_target << " has not been robotomized" << RESET << std::endl;
}
