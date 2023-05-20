/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:42:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/19 22:37:28 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
	public:
		Contact();
		Contact(const std::string& first_name, const std::string& last_name,
				const std::string& nickname, const std::string& phone_number,
				const std::string& darkest_secret);
		~Contact();

		std::string getFirstName(void);
		void setFirstName(const std::string& first_name);
		std::string getLastName(void) const;
		void setLastName(const std::string& last_name);
		std::string getNickName(void) const;
		void setNickName(const std::string& nickname);
		std::string getPhoneNumber(void) const;
		void setPhoneNumber(const std::string& phone_number);
		std::string getDarkestSecret(void) const;
		void setDarkestSecret(const std::string& darkest_secret);
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
