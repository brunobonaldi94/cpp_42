/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:13:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/24 13:49:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "LinkedList.hpp"

class Character : public ICharacter
{
	public:
		Character();
		~Character();
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
		static const int INV_SIZE = 4;
		AMateria *inventory[INV_SIZE];
		int	inventory_count;
		LinkedList	*unused_materia;
};

#endif
