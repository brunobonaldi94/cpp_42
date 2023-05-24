/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:42:41 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/20 13:17:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){ }

Contact::Contact(const std::string& first_name, const std::string& last_name,
				const std::string& nick_name, const std::string& phone_number,
				const std::string& darkest_secret) : _first_name(first_name), 
				_last_name(last_name), _nick_name(nick_name), _phone_number(phone_number),
				_darkest_secret(darkest_secret) { }

Contact::~Contact(void){ }

std::string	Contact::getFirstName() const
{
	return this->_first_name;
}

void	Contact::setFirstName(const std::string& first_name)
{
	this->_first_name = first_name;
}

std::string	Contact::getLastName() const
{
	return this->_last_name;
}

void	Contact::setLastName(const std::string& last_name)
{
	this->_last_name = last_name;
}
std::string	Contact::getNickName() const
{
	return this->_nick_name;
}

void	Contact::setNickName(const std::string& nick_name)
{
	this->_nick_name = nick_name;
}
std::string	Contact::getPhoneNumber() const
{
	return this->_phone_number;
}

void	Contact::setPhoneNumber(const std::string& phone_number)
{
	this->_phone_number = phone_number;
}
std::string	Contact::getDarkestSecret() const
{
	return this->_darkest_secret;
}

void	Contact::setDarkestSecret(const std::string& darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
