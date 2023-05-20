/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:05:08 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/19 21:25:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_str_toupper(const char *str)
{
	for ( ; *str; str++)
		std::cout << static_cast<char>(std::toupper(*str));
}

int main(int argc, char *argv[])
{
	const char *NO_ARGS = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc == 1)
		print_str_toupper(NO_ARGS);
	for (int i = 1; i < argc; i++)
		print_str_toupper(argv[i]);
	std::cout << std::endl;
	return (0);
}
