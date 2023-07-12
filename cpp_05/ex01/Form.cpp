/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:14:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/04 19:05:45 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _grade(150), _exec(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}
Form::Form(std::string name, int grade, int exec): _name(name), _isSigned(false), _grade(grade), _exec(exec)
{
	std::cout << "Form Named constructor called" << std::endl;
	if (grade < this->_maxGrade)
		throw Form::GradeTooHighException(name, grade, false);
	if (exec < this->_maxGrade)
		throw Form::GradeTooHighException(name, exec, true);
	if (grade > this->_minGrade)
		throw Form::GradeTooLowException(name, grade, false);
	if (exec > this->_minGrade)
		throw Form::GradeTooLowException(name, exec, true);
}

Form::Form(Form const &src): _name(src.getName()), _grade(src.getGrade()), _exec(src.getExec())
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
		const_cast<int &>(this->_exec) = rhs.getExec();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getExec() const
{
	return (this->_exec);
}


int Form::getGrade() const
{
	return (this->_grade);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGrade())
			throw Form::GradeTooLowException(this->getName(), bureaucrat, this->getGrade(), false);
	this->_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(std::string name, int grade, bool wasRaisedByExec) : _nameEx(name), _gradeEx(grade), _wasRaisedByExec(wasRaisedByExec)
{
	std::cout << YELLOW << "Form GradeTooHighException Constructor called" << RESET << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << YELLOW << "Form GradeTooHighException Destructor called" << RESET << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	std::string gradeOrExec = this->_wasRaisedByExec ? "exec" : "grade";
	std::cerr << this->_nameEx << ": " << this->_nameEx << " - tried to set " << gradeOrExec << " for : " << this->_gradeEx << std::endl;
	return "Form: GradeTooHighException: The Max Grade is 1, it cannot be higher than this";
}

Form::GradeTooLowException::GradeTooLowException(std::string name, int grade, bool wasRaisedByExec) : _nameEx(name), _gradeEx(grade), 
	_bureaucrat(NULL), _wasRaisedByExec(wasRaisedByExec)
{
	std::cout << YELLOW << this->_nameEx << ": GradeTooLowException Constructor called" << RESET << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(std::string name, Bureaucrat const &bureaucrat, int grade, bool wasRaisedByExec) : 
	_nameEx(name), _gradeEx(grade), _wasRaisedByExec(wasRaisedByExec)
{
	std::cout << YELLOW << this->_nameEx << ": GradeTooLowException Constructor called" << RESET << std::endl;
	this->_bureaucrat = new Bureaucrat(bureaucrat.getName(), bureaucrat.getGrade());
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << YELLOW << this->_nameEx << ": GradeTooLowException Destructor called" << std::endl;
	if (this->_bureaucrat)
		delete this->_bureaucrat;
}

const char* Form::GradeTooLowException::what() const throw()
{
	std::string gradeOrExec = this->_wasRaisedByExec ? "exec" : "grade";
	if (this->_bureaucrat)
	{
		std::string signOrExec = this->_wasRaisedByExec ? "executed" : "signed";
		std::cerr << this->_nameEx << ": " << this->_nameEx << " cannot be " << signOrExec << " by " << this->_bureaucrat->getName() 
		<< " because his/her grade is " << this->_bureaucrat->getGrade()
		<< " and the Form requires " << this->_gradeEx
		<< std::endl;
	}
	else
		std::cerr << this->_nameEx << ": " << this->_nameEx << " - tried to set " << gradeOrExec <<  " for : " << this->_gradeEx << std::endl;
	return "Form: GradeTooLowException: The Min Grade is 150, it cannot be lower than this";
}

Form::FormNotSignedException::FormNotSignedException()
{
	std::cout << YELLOW << "Form: FormNotSignedException Constructor called" << std::endl;
}

Form::FormNotSignedException::~FormNotSignedException() throw()
{
	std::cout << YELLOW << "Form: FormNotSignedException Destructor called" << std::endl;
}


const char* Form::FormNotSignedException::what() const throw()
{
	return "Form: FormNotSignedException: Form was not signed";
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << YELLOW <<  src.getName() << ", AForm grade " << src.getGrade() 
	<< ", is signed: " << (src.getIsSigned() ? "true" : "false")
	<< ", exec grade: " << src.getExec()
	<< RESET <<std::endl;
	return (o);
}

