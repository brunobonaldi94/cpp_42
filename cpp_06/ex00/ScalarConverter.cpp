/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:05:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 10:13:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::converter(std::string param)
{
	CharData data(param);
	data.printConverted();
	IntData data2(param);
	data2.printConverted();
	FloatData data3(param);
	data3.printConverted();
	DoubleData data4(param);
	data4.printConverted();
}
