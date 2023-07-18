/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:23:29 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/17 21:59:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::Serializer(void)
{
	debug("Serializer default constructor called", GREEN);
}

Serializer::~Serializer(void)
{
	debug("Serializer destructor called", RED);
}

Serializer::Serializer(Serializer const &src)
{
	debug("Serializer copy constructor called", GREEN);
	*this = src;
}

Serializer & Serializer::operator=(Serializer const &rhs)
{
	debug("Serializer assignation operator called", GREEN);
	if (this != &rhs)
	{
	}
	return (*this);
}
