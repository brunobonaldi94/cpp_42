/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:14:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/25 19:16:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl reclamao;
	reclamao.complain("debug");
	reclamao.complain("info");
	reclamao.complain("warning");
	reclamao.complain("error");
	reclamao.complain("error2");
	return (0);
}
