/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:38:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 12:32:42 by bbonaldi         ###   ########.fr       */
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
		int	getSize() const;
		Node *createNode(AMateria *materia);
		void add(AMateria *materia);
	private:
		Node *head;
		int size;
};

#endif
