/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:13:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/20 22:54:13 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(Character const &src);
		Character &operator=(Character const &src);

		std::string const &getName() const;
		void setName(std::string name);
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
	private:
		std::string name;
};

#endif
