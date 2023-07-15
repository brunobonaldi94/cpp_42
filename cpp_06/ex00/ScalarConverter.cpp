/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:05:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 15:40:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::converter(std::string param)
{

	CharData dataChar(param);
	IntData dataInt(param);
	FloatData dataFloat(param);
	DoubleData dataDouble(param);

	dataChar.printConverted();
	dataInt.printConverted();
	dataFloat.printConverted();
	dataDouble.printConverted();
}
