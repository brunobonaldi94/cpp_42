/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:38:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/20 14:54:58 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact(Contact &contact);
		void	displayContact(int index) const;
		void	displayContacts(void) const;
		void	searchContactByIndex(void) const;
		// void	exitPhoneBook(void) const;
		// void	runPhoneBook(void);

	private:
	 	static const int MAX_SIZE = 8;
		Contact	_contacts[MAX_SIZE];
		int		_nbr_contacts;
};

#endif
