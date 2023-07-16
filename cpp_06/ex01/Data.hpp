/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:02:12 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/16 18:39:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>
#include "defines.hpp"
#include "colors.hpp"

struct Data
{
	public:
		Data(void);
		Data(int value);
		~Data(void);
		Data(const Data &src);
		Data &operator=(const Data &rhs);
		int getValue(void) const;
	private:
		int _value;

};

std::ostream &operator<<(std::ostream &o, const Data &rhs);
void debug(std::string param, std::string color);

#endif
