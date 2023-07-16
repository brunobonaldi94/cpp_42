/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:31:41 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/16 18:48:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data(42);
	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "address: " << data << " - value: " <<  data->getValue() << std::endl;
	std::cout << "address: " << data2 << " - value: " <<  data2->getValue() << std::endl;
	delete data;
	return (0);
}
