/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:42:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/20 13:30:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
	public:
		//Constructors and Destructors
		Contact(void);
		Contact(const std::string& first_name, const std::string& last_name,
				const std::string& nick_name, const std::string& phone_number,
				const std::string& darkest_secret);
		~Contact();

		//Getters and Setters
		std::string getFirstName(void) const;
		void setFirstName(const std::string& first_name);
		std::string getLastName(void) const;
		void setLastName(const std::string& last_name);
		std::string getNickName(void) const;
		void setNickName(const std::string& nick_name);
		std::string getPhoneNumber(void) const;
		void setPhoneNumber(const std::string& phone_number);
		std::string getDarkestSecret(void) const;
		void setDarkestSecret(const std::string& darkest_secret);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif
