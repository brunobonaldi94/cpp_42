/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:36:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/20 19:33:51 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int & easyfind(T & intContainer, int intToFind)
{
	typename T::iterator it;
	typename T::iterator first = intContainer.begin();
	typename T::iterator last = intContainer.end();
	for (; first != last; ++first)
		if (*first == intToFind)
			return (*first);
	throw std::exception();
}
