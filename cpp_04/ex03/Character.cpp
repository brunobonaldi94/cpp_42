/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:53:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/22 23:10:54 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character Default Constructor" << std::endl;
}

Character::Character(std::string name): name(name),inventory_count(0)
{
	std::cout << "Character named Constructor called" << std::endl;
	this->unused_materia = new LinkedList();
}

Character::Character(Character const &src)
{
	*this = src;
}
Character::~Character(void)
{
	delete this->unused_materia;
}
Character &Character::operator=(Character const &src)
{
	std::cout << "Character Copy Assignment Operator called" << std::endl;
	if (this != &src)
	{
		this->setName(src.getName());
		this->inventory_count = inventory_count;
		for (int i = 0; i < this->INV_SIZE; i++)
			this->inventory[i] = src.inventory[i];

	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::setName(std::string name)
{
	this->name = name;
}

void Character::equip(AMateria *m)
{
	if (this->inventory_count >= this->INV_SIZE)
		return ;
	int index = this->inventory_count;
	this->inventory[index] = m;
	this->inventory_count++;
}

void Character::unequip(int index)
{
	if (index < 0 || index > this->inventory_count - 1)
		return ;
	this->unused_materia->add(this->inventory[index]);
	this->inventory[index] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > this->inventory_count - 1)
		return ;
	this->inventory[idx]->use(target);
}
