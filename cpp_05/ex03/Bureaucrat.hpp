/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:55:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/05 21:47:42 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include <sstream>
#include "AForm.hpp"

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

class AForm;

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(std::string name, int grade);
				virtual const char* what() const throw();
				virtual ~GradeTooHighException() throw();
			private:
				std::string const 	_nameEx;
				int const 			_gradeEx;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(std::string name, int grade);
				virtual const char* what() const throw();
				virtual ~GradeTooLowException() throw();
			private:
				std::string const 	_nameEx;
				int const 			_gradeEx;
		};

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const & form);

	private:
		std::string	const	_name;
		int					_grade;
		static const int 	_maxGrade = 1;
		static const int 	_minGrade = 150;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);


#endif
