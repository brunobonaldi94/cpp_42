/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:37:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 23:49:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MYSED_H
# define MYSED_H

#include "InputFile.hpp"
#include "OutputFile.hpp"

class	MySed
{
	public:
		MySed(std::string file_name, std::string s1, std::string s2);
		~MySed();

		void	replaceS1byS2();

	private:
		InputFile*	_input_file;
		OutputFile*	_output_file;
		std::string	_s1;
		std::string	_s2;
};

#endif
