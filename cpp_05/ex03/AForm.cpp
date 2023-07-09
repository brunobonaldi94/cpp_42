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

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _grade(150), _exec(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}
AForm::AForm(std::string name, int grade, int exec): _name(name), _isSigned(false), _grade(grade), _exec(exec)
{
	std::cout << "AForm Named constructor called" << std::endl;
	if (grade < this->_maxGrade)
		throw AForm::GradeTooHighException(name, grade, false);
	if (exec < this->_maxGrade)
		throw AForm::GradeTooHighException(name, exec, true);
	if (grade > this->_minGrade)
		throw AForm::GradeTooLowException(name, grade, false);
	if (exec > this->_minGrade)
		throw AForm::GradeTooLowException(name, exec, true);
}

AForm::AForm(AForm const &src): _name(src.getName()), _grade(src.getGrade()), _exec(src.getExec())
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_isSigned = rhs.getIsSigned();
		const_cast<int &>(this->_grade) = rhs.getGrade();
		const_cast<int &>(this->_exec) = rhs.getExec();
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getExec() const
{
	return (this->_exec);
}


int AForm::getGrade() const
{
	return (this->_grade);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGrade())
			throw AForm::GradeTooLowException(this->getName(), bureaucrat, this->getGrade(), false);
	this->_isSigned = true;
}

AForm::GradeTooHighException::GradeTooHighException(std::string name, int grade, bool wasRaisedByExec) : _nameEx(name), _gradeEx(grade), _wasRaisedByExec(wasRaisedByExec)
{
	std::cout << YELLOW << "AForm GradeTooHighException Constructor called" << RESET << std::endl;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << YELLOW << "AForm GradeTooHighException Destructor called" << RESET << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	std::string gradeOrExec = this->_wasRaisedByExec ? "exec" : "grade";
	std::cerr << this->_nameEx << ": " << this->_nameEx << " - tried to set " << gradeOrExec << " for : " << this->_gradeEx << std::endl;
	return "AForm: GradeTooHighException: The Max Grade is 1, it cannot be higher than this";
}

AForm::GradeTooLowException::GradeTooLowException(std::string name, int grade, bool wasRaisedByExec) : _nameEx(name), _gradeEx(grade), 
	_bureaucrat(NULL), _wasRaisedByExec(wasRaisedByExec)
{
	std::cout << YELLOW << this->_nameEx << ": GradeTooLowException Constructor called" << RESET << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException(std::string name, Bureaucrat const &bureaucrat, int grade, bool wasRaisedByExec) : 
	_nameEx(name), _gradeEx(grade), _wasRaisedByExec(wasRaisedByExec)
{
	std::cout << YELLOW << this->_nameEx << ": GradeTooLowException Constructor called" << RESET << std::endl;
	this->_bureaucrat = new Bureaucrat(bureaucrat.getName(), bureaucrat.getGrade());
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << YELLOW << this->_nameEx << ": GradeTooLowException Destructor called" << std::endl;
	if (this->_bureaucrat)
		delete this->_bureaucrat;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	std::string gradeOrExec = this->_wasRaisedByExec ? "exec" : "grade";
	if (this->_bureaucrat)
	{
		std::string signOrExec = this->_wasRaisedByExec ? "executed" : "signed";
		std::cerr << this->_nameEx << ": " << this->_nameEx << " cannot be " << signOrExec << " by " << this->_bureaucrat->getName() 
		<< " because his/her grade is " << this->_bureaucrat->getGrade()
		<< " and the AForm requires " << this->_gradeEx
		<< std::endl;
	}
	else
		std::cerr << this->_nameEx << ": " << this->_nameEx << " - tried to set " << gradeOrExec <<  " for : " << this->_gradeEx << std::endl;
	return "AForm: GradeTooLowException: The Min Grade is 150, it cannot be lower than this";
}

AForm::FormNotSignedException::FormNotSignedException()
{
	std::cout << YELLOW << "AForm: FormNotSignedException Constructor called" << std::endl;
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{
	std::cout << YELLOW << "AForm: FormNotSignedException Destructor called" << std::endl;
}


const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm: FormNotSignedException: Form was not signed";
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExec())
			throw AForm::GradeTooLowException(this->getName(), executor, this->getExec(), true);
	if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
	return ;
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << YELLOW <<  src.getName() << ", AForm grade " << src.getGrade() 
	<< ", is signed: " << (src.getIsSigned() ? "true" : "false")
	<< ", exec grade: " << src.getExec()
	<< RESET <<std::endl;
	return (o);
}

