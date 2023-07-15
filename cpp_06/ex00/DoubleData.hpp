/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:56:07 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 10:59:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_DATA_HPP
# define DOUBLE_DATA_HPP

#include "AData.hpp"

class DoubleData: public AData<double, long double>
{
	public:
		DoubleData();
		DoubleData(std::string param);
		~DoubleData();
		DoubleData(DoubleData const &src);
		DoubleData & operator=(DoubleData const &rhs);

		double tryToConvert();
		void printConverted();
		bool checkLimits();
		long double handleResultOverUnderFlow(std::string param);
	private:
		bool dealPseudoLiterals();
		bool dealFloatingPoint();
};

#endif
