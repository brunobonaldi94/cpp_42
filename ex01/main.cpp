/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:43:04 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/20 15:24:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <typeinfo>

#define NAME_OF( name ) ((void) sizeof(typeid(name)), #name)

void	set_string(std::string name, std::string &str)
{
	std::cout << "please add a " << name << std::endl;
	std::cin >> str;
}

int	main(void)
{
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;
	std::string	command;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "please select an action: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			set_string("First Name", first_name);
			set_string("Last Name", last_name);
			set_string("Nick Name", nick_name);
			set_string("Phone Number", phone_number);
			set_string("Darkest Secret", darkest_secret);
			Contact current_contact(first_name, last_name, nick_name, phone_number, darkest_secret);
			phonebook.addContact(current_contact);
			break ;
		}
		break ;
	}
	phonebook.displayContacts();
	return (0);
}
