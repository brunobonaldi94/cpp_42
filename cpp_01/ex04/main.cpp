/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:36:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/25 00:17:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int	main( void )
{

	MySed mysed("Makefile", "NAME", "EOOOOOOOOOOOOOO");
	mysed.replaceS1byS2();
	return (0);
}
