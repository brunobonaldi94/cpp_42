/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 15:34:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FLOAT_DATA_HPP
# define FLOAT_DATA_HPP

#include "AData.hpp"

class FloatData: public AData<float, double>
{
	public:
		FloatData();
		FloatData(std::string param);
		~FloatData();
		FloatData(FloatData const &src);
		FloatData & operator=(FloatData const &rhs);

		float tryToConvert();
		void printConverted();
		bool checkLimits(double paramConverted);
		double handleResultOverUnderFlow(std::string param);
	private:
		bool dealPseudoLiterals();
		bool dealFloatingPoint();

};

#endif
