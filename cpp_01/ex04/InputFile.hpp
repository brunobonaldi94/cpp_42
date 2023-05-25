/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:45:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 23:28:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTFILE_H
# define INPUTFILE_H

#include <iostream>
#include <fstream>

class InputFile
{
	public:
		InputFile(std::string file_name);
		~InputFile();
		std::string	readFile( void );
		void	setFileStream();

	private:
		std::string		_file_name;
		std::ifstream	_input_file_stream;
};

#endif
