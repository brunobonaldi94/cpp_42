/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:43:04 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/21 18:51:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	action;
	PhoneBook	phonebook;

	while (phonebook.getIsRunning())
	{
		phonebook.setString("please select an action: ADD, SEARCH or EXIT" , action);
		if (action.compare("ADD") == 0)
			phonebook.handleAddContact();
		else if (action.compare("SEARCH") == 0)
			phonebook.handleSearchContact();
		else if (action.compare("EXIT") == 0)
			phonebook.handleExit();
		else
			std::cout << RED << "Invalid action" << RESET << std::endl;
		phonebook.printSeparator();
	}
	return (0);
}
