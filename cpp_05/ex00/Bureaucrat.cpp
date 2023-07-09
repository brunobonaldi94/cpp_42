/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:01:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/09 18:37:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string NumberToString ( int Number )
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(this->_minGrade)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Named constructor called" << std::endl;
	if (grade < this->_maxGrade)
		throw Bureaucrat::GradeTooHighException(name, grade);
	if (grade > this->_minGrade)
		throw Bureaucrat::GradeTooLowException(name, grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < this->_maxGrade)
		throw Bureaucrat::GradeTooHighException(this->getName(), this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > this->_minGrade)
		throw Bureaucrat::GradeTooLowException(this->getName(), this->_grade + 1);
	this->_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string name, int grade) : _nameEx(name), _gradeEx(grade)
{
	std::cout << YELLOW << "Bureaucrat: GradeTooHighException Constructor called" << RESET << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << YELLOW << "Bureaucrat: GradeTooHighException Destructor called" << RESET << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cerr << "Bureaucrat: " << this->_nameEx << " - tried to set grade for : " << this->_gradeEx << std::endl;
	return "Bureaucrat: GradeTooHighException: The Max Grade is 1, it cannot be higher than this";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string name, int grade) : _nameEx(name), _gradeEx(grade)
{
	std::cout << YELLOW << "Bureaucrat: GradeTooLowException Constructor called" << RESET << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << YELLOW << "Bureaucrat: GradeTooLowException Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cerr << "Bureaucrat: " << this->_nameEx << " - tried to set grade for : " << this->_gradeEx << std::endl;
	return "Bureaucrat: GradeTooLowException: The Min Grade is 150, it cannot be lower than this";
}
std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (o);
}
