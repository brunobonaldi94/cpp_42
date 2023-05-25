/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:45:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 23:37:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUTFILE_H
# define OUTPUTFILE_H

#include <iostream>
#include <fstream>

class OutputFile
{
	public:
		OutputFile(std::string file_name);
		~OutputFile();
		void	WriteFile( std::string strToWrite);

	private:
		std::string		_file_name;
		std::ofstream	_output_file_stream;
};

#endif
