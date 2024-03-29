/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:25:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 22:53:57 by bbonaldi         ###   ########.fr       */
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

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(std::string name, int grade, bool wasRaisedByExec);
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
			private:
				std::string const	_nameEx;
				int			const	_gradeEx;
				bool				_wasRaisedByExec;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(std::string name, int grade, bool wasRaisedByExec);
				GradeTooLowException(std::string name, Bureaucrat const &bureaucrat, int grade, bool wasRaisedByExec);
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();

			private:
				std::string const	_nameEx;
				int const 			_gradeEx;
				Bureaucrat const	*_bureaucrat;
				bool				_wasRaisedByExec;
		};
		class FormNotSignedException: public std::exception
		{
			public: 
				FormNotSignedException();
				virtual ~FormNotSignedException() throw();
				virtual const char* what() const throw();
		};

		Form();
		Form(std::string name, int grade, int exec);
		Form(Form const &src);
		virtual ~Form();
		Form & operator=(Form const &rhs);

		std::string getName() const;
		int 		getGrade() const;
		bool 		getIsSigned() const;
		int 		getExec() const;
	
		void beSigned(const Bureaucrat &bureaucrat);

	private:
		std::string	const	_name;
		bool				_isSigned;
		int const 			_grade;
		int const			_exec;
		static const int 	_maxGrade = 1;
		static const int 	_minGrade = 150;
};

std::ostream &operator<<(std::ostream &o, Form const &AForm);

#endif
