/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:13:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/08 23:31:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <cctype>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		class FormNotFoundException : public std::exception
		{
			public:
				FormNotFoundException(std::string formName);
				virtual ~FormNotFoundException() throw();
				virtual const char* what() const throw();
			private:
				std::string _formName;
		};
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(Intern const &rhs);

		AForm *createShrubbery(std::string target);
		AForm *createPresidentialPardon(std::string target);
		AForm *createRobotomyRequest(std::string target);

		AForm *makeForm(std::string formName, std::string target);

		static std::string castIntToString(int number);

		private:
			bool compareToLowerCase(std::string str1, std::string str2);
};

#endif
