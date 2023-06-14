/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:03:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/13 21:15:13 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() :  _nbr_contacts( 0 ), _next_contact_index( 0 ) , _is_running( true ) { }
PhoneBook::~PhoneBook() { }

bool	PhoneBook::getIsRunning(void) const
{
	return (this->_is_running);
}

void	PhoneBook::setIsRunning(bool is_running)
{
	this->_is_running = is_running;
}

int		PhoneBook::getNextContactIndex(void) const
{
	return this->_next_contact_index;
}
void	PhoneBook::setNextContactIndex(int lastContactIndexAdded)
{
	if (lastContactIndexAdded == this->MAX_SIZE - 1)
		this->_next_contact_index = 0;
	else
		this->_next_contact_index = lastContactIndexAdded + 1;

}

void	PhoneBook::handleExit(void)
{
	std::cout << GREEN << "Exiting..." << RESET << std::endl;
	setIsRunning(false);
}


void	PhoneBook::handleAddContact()
{
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;

	this->setString("Please add a First Name", first_name);
	this->setString("Please add a Last Name", last_name);
	this->setString("Please add a Nick Name", nick_name);
	this->setString("Please add a Phone Number", phone_number);
	this->setString("Please add a Darkest Secret", darkest_secret);
	
	Contact current_contact(
		first_name,
		last_name,
		nick_name,
		phone_number,
		darkest_secret
	);
	this->addContact(current_contact);
}

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
	if (this->_nbr_contacts < this->MAX_SIZE)
		this->_nbr_contacts++;
	int	index = this->getNextContactIndex();
	this->_contacts[index] = contact;
	setNextContactIndex(index);
}
bool		PhoneBook::isAllWhiteSpace(std::string str) const
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}
void PhoneBook::setString(std::string label, std::string &str)
{
	while (true)
	{
		std::cout << GREEN << label <<  RESET << std::endl;
		std::getline(std::cin, str);
		if (!str.empty() && !this->isAllWhiteSpace(str))
			break;
		else
			std::cout << RED << "It cannot be empty or only have white space" << RESET << std::endl;
	}
}

void	PhoneBook::handleSearchContact(void) const
{
	if (!this->displayContacts())
		return ;
	this->searchContactByIndex();
}

void	PhoneBook::searchContactByIndex(void) const
{
	std::string	index_str;
	int 		index;

	std::cout << GREEN << "Please select a contact by `Index` field to display" << RESET << std::endl;
	std::getline(std::cin, index_str);
	if (isValidIndex(index_str))
	{
		std::stringstream ss(index_str);
		ss >> index;
		this->displayFullContactFields(index - 1);
	}
}

bool PhoneBook::displayContacts() const
{
	if (this->_nbr_contacts == 0)
	{
		std::cout << RED << "No contacts to display" << RESET << std::endl;
		return (false);
	}
	this->printHeaders();
	for (int i = 0; i < this->_nbr_contacts; i++)
		displayContactOnSearchMenu(i);
	std::cout << std::endl;
	return (true);
}

void	PhoneBook::displayContactOnSearchMenu(int index) const
{
	std::string first_name, last_name, nick_name;
	if (index < 0 || index > this->_nbr_contacts)
		return ;
	this->printEachField((index + 1), false);
	first_name = this->limitFieldUpToLength(this->_contacts[index].getFirstName());
	this->printEachField(first_name, false);
	
	last_name = this->limitFieldUpToLength(this->_contacts[index].getLastName());
	this->printEachField(last_name, false);
	
	nick_name = this->limitFieldUpToLength(this->_contacts[index].getNickName());
	this->printEachField(nick_name, true);
}

void PhoneBook::displayFullContactFields(int index) const
{
	if (index < 0 || index > this->_nbr_contacts - 1)
	{
		std::cout << "Invalid Contact Index" << std::endl;
		return ;
	}
	std::cout << BLUE << "Index: " << index + 1 << std::endl;
	std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << RESET <<std::endl;
}

std::string	PhoneBook::limitFieldUpToLength(std::string str, size_t length) const
{
	if (str.length() > length)
		return str.substr(0, length - 1) + ".";
	return str;
}

void	 PhoneBook::printHeaders(void) const 
{
	this->printEachField("Index", false);
	this->printEachField("First Name", false);
	this->printEachField("Last Name", false);
	this->printEachField("Nick Name", true);
}

void	PhoneBook::printEachField(std::string field, bool shouldEndLine) const
{
	if (shouldEndLine)
		std::cout << YELLOW << std::right << std::setw(10) << field << RESET << std::endl;
	else
		std::cout << YELLOW << std::right << std::setw(10) << field << RESET << " | ";
}

void	PhoneBook::printEachField(int field, bool shouldEndLine) const
{
	if (shouldEndLine)
		std::cout << YELLOW << std::right << std::setw(10) << field << RESET << std::endl;
	else
		std::cout << YELLOW << std::right << std::setw(10) << field << RESET << " | ";
}

bool PhoneBook::isValidIndex(std::string str) const
{
	if (str.empty())
	{
		std::cout << RED << "It cannot be empty" << RESET << std::endl;
		return (false);
	}
	
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << RED << "Invalid Index, it must be numeric" << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

void	PhoneBook::printSeparator(void) const
{
	 std::cout << std::string(100, '-') << std::endl;
}
