/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:03:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/20 15:07:30 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() :  _nbr_contacts( 0 ) { }
PhoneBook::~PhoneBook() { }

void PhoneBook::addContact(Contact &contact)
{
	if (contact.getFirstName().empty() 
		|| contact.getLastName().empty() 
		|| contact.getNickName().empty()
		|| contact.getPhoneNumber().empty()
		|| contact.getDarkestSecret().empty()
		) 
		{
			std::cout << "All fields must be filled" << std::endl;
			return ;
		}
	int	index = _nbr_contacts % this->MAX_SIZE;
	this->_contacts[index] = contact;
	if (this->_nbr_contacts < this->MAX_SIZE)
		this->_nbr_contacts++;
}

void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index > this->_nbr_contacts)
		return ;
	std::cout << "Contact Number: " << index + 1 << std::endl;
	std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}
void PhoneBook::displayContacts() const
{
	if (this->_nbr_contacts == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_nbr_contacts; i++)
		displayContact(i);
}
