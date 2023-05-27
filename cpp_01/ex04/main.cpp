/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:36:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/25 18:33:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int	main( void )
{
	//FAZER TESTES COM NULL,"" etc, file que nao existe
	MySed mysed("Makefile", "NAME", "RATINHOOOOOOO!");
	mysed.replaceS1byS2();
	return (0);
}
