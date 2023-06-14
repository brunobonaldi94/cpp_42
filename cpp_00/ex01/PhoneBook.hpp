/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:38:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/13 21:08:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include "Contact.hpp"
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

class PhoneBook
{
	public:

		PhoneBook();
		~PhoneBook();

		bool		getIsRunning(void) const;
		void		setIsRunning(bool is_running);
		int			getNextContactIndex(void) const;
		void		setNextContactIndex(int lastIndexAdded);

		void		setString(std::string name, std::string &str);
		void		addContact(Contact &contact);
		void		handleAddContact(void);

		bool 		isValidIndex(std::string str) const;
		bool		isAllWhiteSpace(std::string str) const;
		std::string	limitFieldUpToLength(std::string name, size_t length = 10) const;
		void		printEachField(std::string field, bool shouldEndLine) const;
		void		printEachField(int field, bool shouldEndLine) const;
		void	 	printHeaders(void) const;
		void		printSeparator(void) const;
		void		displayFullContactFields(int index) const;
		void		displayContactOnSearchMenu(int index) const;
		void		handleSearchContact(void) const;
		bool		displayContacts(void) const;
		void		searchContactByIndex(void) const;

		void		handleExit(void);

	private:
	 	static const int MAX_SIZE = 8;
		Contact	_contacts[MAX_SIZE];
		int		_nbr_contacts;
		int		_next_contact_index;
		int		_is_running;
};

#endif
