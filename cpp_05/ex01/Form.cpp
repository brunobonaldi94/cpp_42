/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:14:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/09 19:11:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _grade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}
Form::Form(std::string name, int grade): _name(name), _isSigned(false), _grade(grade)
{
	std::cout << "Form Named constructor called" << std::endl;
	if (grade < this->_maxGrade)
		throw Form::GradeTooHighException(name, grade);
	if (grade > this->_minGrade)
		throw Form::GradeTooLowException(name, grade);
}

Form::Form(Form const &src): _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = src;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_isSigned = rhs.getIsSigned();
		const_cast<int &>(this->_grade) = rhs.getGrade();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGrade() const
{
	return (this->_grade);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGrade())
		throw Form::GradeTooLowException(this->getName(), bureaucrat, this->getGrade());
	this->_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(std::string name, int grade) : _nameEx(name), _gradeEx(grade)
{
	std::cout << YELLOW << "Form GradeTooHighException Constructor called" << RESET << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << YELLOW << "Form GradeTooHighException Destructor called" << RESET << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	std::cerr << "Form: " << this->_nameEx << " - tried to set grade for : " << this->_gradeEx << std::endl;
	return "Form: GradeTooHighException: The Max Grade is 1, it cannot be higher than this";
}

Form::GradeTooLowException::GradeTooLowException(std::string name, int grade) : _nameEx(name), _gradeEx(grade), _bureaucrat(NULL)
{
	std::cout << YELLOW << "Form: GradeTooLowException Constructor called" << RESET << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(std::string name, Bureaucrat const &bureaucrat, int grade) : _nameEx(name), _gradeEx(grade)
{
	std::cout << YELLOW << "Form: GradeTooLowException Constructor called" << RESET << std::endl;
	this->_bureaucrat = new Bureaucrat(bureaucrat.getName(), bureaucrat.getGrade());
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << YELLOW << "Form: GradeTooLowException Destructor called" << std::endl;
	if (this->_bureaucrat)
		delete this->_bureaucrat;
}

const char* Form::GradeTooLowException::what() const throw()
{
	if (this->_bureaucrat)
	{
		std::cerr << "Form: " << this->_nameEx << " cannot be signed by " << this->_bureaucrat->getName() 
		<< " because his/her grade is " << this->_bureaucrat->getGrade()
		<< " and the form requires " << this->_gradeEx
		<< std::endl;
	}
	else
		std::cerr << "Form: " << this->_nameEx << " - tried to set grade for : " << this->_gradeEx << std::endl;
	return "Form: GradeTooLowException: The Min Grade is 150, it cannot be lower than this";
}
std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << src.getName() << ", form grade " << src.getGrade() 
	<< ", is signed: " << (src.getIsSigned() ? "true" : "false")
	<< std::endl;
	return (o);
}
