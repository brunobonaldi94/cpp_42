/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:42:41 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/19 22:21:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName()
{
	return this->first_name;
}

void	Contact::setFirstName(const std::string& first_name)
{
	this->first_name = first_name;
}

std::string	Contact::getLastName() const
{
	return this->last_name;
}

void	Contact::setLastName(const std::string& last_name)
{
	this->last_name = last_name;
}
std::string	Contact::getNickName() const
{
	return this->nickname;
}

void	Contact::setNickName(const std::string& nickname)
{
	this->nickname = nickname;
}
std::string	Contact::getPhoneNumber() const
{
	return this->phone_number;
}

void	Contact::setPhoneNumber(const std::string& phone_number)
{
	this->phone_number = phone_number;
}
std::string	Contact::getDarkestSecret() const
{
	return this->darkest_secret;
}

void	Contact::setDarkestSecret(const std::string& darkest_secret)
{
	this->darkest_secret = darkest_secret;
}
