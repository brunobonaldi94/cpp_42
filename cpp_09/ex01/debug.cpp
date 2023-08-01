/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:21:07 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/26 18:09:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "defines.hpp"

void debug(std::string param, std::string color)
{
	if (DEBUG)
		std::cout << color << param << RESET << std::endl;
}
