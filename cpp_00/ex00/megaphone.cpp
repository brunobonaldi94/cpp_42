/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:05:08 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/21 19:09:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_str_toupper(std::string str)
{
	for (std::size_t i = 0; i < str.length(); i++)
		std::cout << static_cast<char>(std::toupper(str[i]));
}

int main(int argc, char *argv[])
{
	const std::string NO_ARGS = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc == 1)
		print_str_toupper(NO_ARGS);
	for (int i = 1; i < argc; i++)
		print_str_toupper(argv[i]);
	std::cout << std::endl;
	return (0);
}
