/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:45:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/25 18:43:20 by bbonaldi         ###   ########.fr       */
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
		bool		fileExists( std::string file_name);
		bool		getFileExists( void );
		std::string & getFileName( void );
	private:
		std::string		_file_name;
		std::ifstream	_input_file_stream;
		bool			_file_exists;
};

#endif
