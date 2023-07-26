/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:10:41 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/25 19:18:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Container.hpp"

template <typename T, class TBase>
Container<T, TBase>::Container() : TBase() {}

template <typename T, class TBase>
Container<T, TBase>::Container(Container const &src) : TBase(src) {}

template <typename T, class TBase>
Container<T, TBase>::~Container() {}

template <typename T, class TBase>
Container<T, TBase> &Container<T, TBase>::operator=(Container const &rhs)
{
	if (this != &rhs)
		TBase::operator=(rhs);
	return (*this);
}

template <typename T, class TBase>
void Container<T, TBase>::push(T const &value)
{
	TBase::push_back(value);
}

template <typename T, class TBase>
void Container<T, TBase>::pop(void)
{
	TBase::pop_back();
}

template <typename T, class TBase>
T & Container<T, TBase>::top(void)
{
	return (TBase::back());
}
