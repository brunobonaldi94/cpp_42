/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/13 21:28:24 by bbonaldi         ###   ########.fr       */
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
		FloatData(FloatData const &data);
		FloatData & operator=(FloatData const &data);

		float tryToConvert();
		void printConverted();
		bool checkLimits();
		double handleResultOverUnderFlow(std::string param);
};

#endif
