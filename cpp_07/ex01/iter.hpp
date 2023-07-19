/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:00:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/18 22:11:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
#include "colors.hpp"

template <typename T>
void	iter(T *array, size_t size, void (*fn)(T const &value))
{
	for (size_t i = 0; i < size; i++)
		fn(array[i]);
}

#endif
