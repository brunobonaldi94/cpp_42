/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:53:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 10:13:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include "CharData.hpp"
#include "IntData.hpp"
#include "FloatData.hpp"
#include "DoubleData.hpp"

class ScalarConverter
{
	public:
		static void converter(std::string param);
	private:
		ScalarConverter();
};

#endif
