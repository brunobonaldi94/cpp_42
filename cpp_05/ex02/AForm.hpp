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

#ifndef AForm_H
# define AForm_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

		AForm();
		AForm(std::string name, int grade, int exec);
		AForm(AForm const &src);
		virtual ~AForm() = 0;
		AForm & operator=(AForm const &rhs);

		std::string getName() const;
		int 		getGrade() const;
		bool 		getIsSigned() const;
		int 		getExec() const;
	
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

	private:
		std::string	const	_name;
		bool				_isSigned;
		int const 			_grade;
		int const			_exec;
		static const int 	_maxGrade = 1;
		static const int 	_minGrade = 150;

	protected:	
		std::string			_target;

};

std::ostream &operator<<(std::ostream &o, AForm const &AForm);

#endif
