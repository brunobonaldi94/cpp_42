/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:12:12 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/26 22:16:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include "colors.hpp"
#include "defines.hpp"
#include <list>
#include <map>
#include <fstream>
#include <sstream>
#include <stdlib.h>

class BitcoinExchange
{
	private:
		std::string _filename;
		std::ifstream *_file;
		std::map<std::string, std::string> _data;
		bool IsValidPrice(std::string price);
		bool IsValidDate(std::string date);
		bool CheckDatePart(std::string datePart, size_t len,int min, int max);

	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		void ReadInputFile(void);
		void openFile(std::string filename);
		void getDataFromFile(void);
		class BadDateException : public std::exception
		{
			public:
				BadDateException(std::string date);
				virtual const char* what() const throw();
				virtual ~BadDateException() throw();
			
			private:
				std::string _errorMessage;
		};

		class BadPriceException : public std::exception
		{
			public:
				BadPriceException(std::string errorMessage);
				virtual const char* what() const throw();
				virtual ~BadPriceException() throw();
			
			private:
				std::string _errorMessage;
		};

		class FileErrorException : public std::exception
		{
			public:
				FileErrorException(std::string errorMessage);
				virtual const char* what() const throw();
				virtual ~FileErrorException() throw();
			
			private:
				std::string _errorMessage;
		};


};
void debug(std::string param, std::string color);

#endif
