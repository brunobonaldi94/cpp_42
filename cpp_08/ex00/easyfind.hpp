/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:29:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/25 22:00:51 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <ctime>
#include <cstdlib>
# include "colors.hpp"

template <typename T>
typename T::iterator easyfind(T & intContainer, int intToFind);

# include "easyfind.tpp"

#endif
