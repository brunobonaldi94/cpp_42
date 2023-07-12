/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/11 18:06:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FLOAT_DATA_HPP
# define FLOAT_DATA_HPP

#include "AData.hpp"

class FLoatData: public AData<float>
{
	public:
		FLoatData();
		FLoatData(std::string param);
		~FLoatData();
		FLoatData(FLoatData const &src);
		FLoatData & operator=(const FLoatData &rhs);

		char TryToCovert();
		void printConverted();
};

#endif
