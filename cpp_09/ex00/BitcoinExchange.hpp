/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:12:12 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/28 23:57:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include "colors.hpp"
#include "defines.hpp"
#include <list>
#include <algorithm>
#include <map>
#include <climits>
#include <fstream>
#include <sstream>
#include <stdlib.h>

struct CompareKeys {
    bool operator()(const std::pair<const std::string, float>& lhs, const std::string& rhs) const;
};
class BitcoinExchange
{
	private:
		std::string _filename;
		std::ifstream *_fileInput;
		std::ifstream *_fileData;
		std::map<std::string, float> _data;
		bool IsValidPrice(std::string price, size_t max);
		bool IsValidDate(std::string date);
		bool CheckDatePart(std::string datePart, size_t len,int min, int max);
		std::list<std::string> split(std::string str, char delimeter);
		std::string trim(std::string str);
		std::string ReadLineInputFile(bool & isEOF);
		void openFile(std::string filename);
		void DoExchangeEachLine(std::string line);
		float getExchangeRate(std::string date);
		void getDataFromFile(void);


	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		void DoExchange(void);
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
