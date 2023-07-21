/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:36:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/20 21:57:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T & intContainer, int intToFind)
{
	typename T::iterator it = std::find(
		intContainer.begin(),
		intContainer.end(),
		intToFind
	);
	if (it == intContainer.end())
		throw std::runtime_error("Not found");
	return (it);
}
