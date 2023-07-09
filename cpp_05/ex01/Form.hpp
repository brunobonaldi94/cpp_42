/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:25:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/09 19:11:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int grade);
		Form(Form const &src);
		~Form();
		Form & operator=(Form const &rhs);

		std::string getName() const;
		int getGrade() const;
		bool getIsSigned() const;
	
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(std::string name, int grade);
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
			private:
				std::string const	_nameEx;
				int			const	_gradeEx;
		};
	class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(std::string name, int grade);
				GradeTooLowException(std::string name, Bureaucrat const &bureaucrat, int grade);
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();

			private:
				std::string const	_nameEx;
				int const 			_gradeEx;
				Bureaucrat const	*_bureaucrat;
		};

		void beSigned(Bureaucrat &bureaucrat);

	private:
		std::string	const	_name;
		bool				_isSigned;
		int const 			_grade;
		static const int 	_maxGrade = 1;
		static const int 	_minGrade = 150;
};

std::ostream &operator<<(std::ostream &o, Form const &form);

#endif
