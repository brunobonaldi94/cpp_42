/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:39:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/22 23:03:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"

LinkedList::LinkedList()
{
	std::cout << "LinkedList Default Constructor called" << std::endl;
	this->head = NULL;
}

LinkedList::LinkedList(Node *head)
{
	std::cout << "LinkedList named Constructor called" << std::endl;
	this->head = head;
}

LinkedList::~LinkedList()
{
	std::cout << "LinkedList Destructor called" << std::endl;
	Node *temp;
	temp = this->head;
	while (this->head)
	{
		temp = this->head->next;
		delete this->head;
		this->head = temp;
	}
}

LinkedList::LinkedList(LinkedList const &src)
{
	*this = src;
}

LinkedList &LinkedList::operator=(LinkedList const &rhs)
{
	if (this != &rhs)
		this->head = rhs.head;
	return *this;
}


Node *LinkedList::createNode(AMateria *materia)
{
	Node *node = new Node;
	node->materia = materia;
	node->next = NULL;
	return node;
}
void LinkedList::add(AMateria *materia)
{
	Node *node = createNode(materia);
	node->next = this->head;
	this->head = node;
}
