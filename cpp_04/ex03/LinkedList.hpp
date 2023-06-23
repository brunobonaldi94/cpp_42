/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:38:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/22 23:00:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

#include "AMateria.hpp"

struct Node
{
	AMateria *materia;
	Node *next;
};

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		LinkedList(Node *node);
		LinkedList(LinkedList const &src);
		LinkedList &operator=(LinkedList const &src);

		Node *createNode(AMateria *materia);
		void add(AMateria *materia);
	private:
		Node *head;
};

#endif
