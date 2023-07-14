/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntData.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:04 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/12 23:05:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INT_DATA_HPP
# define INT_DATA_HPP

#include "AData.hpp"

class IntData: public AData<int, long int>
{
	public:
		IntData();
		IntData(std::string param);
		~IntData();
		IntData(IntData const &data);
		IntData & operator=(IntData const &data);

		int tryToConvert();
		void printConverted();
		bool checkLimits();
		long int handleResultOverUnderFlow(std::string param);

	private:
		
};

#endif
