/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:38:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/19 22:37:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(Contact contacts[8]);
		~PhoneBook();

		void	addContact(Contact contact);
		void	displayContacts(void) const;
		void	searchContactByIndex(void) const;
		void	exitPhoneBook(void) const;

	private:
		Contact	contacts[8];

};

#endif
