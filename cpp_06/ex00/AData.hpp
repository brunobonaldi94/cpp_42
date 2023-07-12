#ifndef ADATA_HPP
#define ADATA_HPP

#include <iostream>
#include <exception>
#include "colors.hpp"
#include <cstdlib>

template <typename T>
class AData
{
	public:
		class BadCast : public std::exception
		{
			public:
				BadCast(std::string result);
				virtual const char* what() const throw();
				virtual ~BadCast() throw ();
				std::string getResult() const;
			private:
				std::string _result;
		};
		AData();
		AData(std::string param);
		virtual ~AData();
		AData(AData const &rhs);
		AData & operator=(AData const &rhs);

		void setParam(std::string param);
		std::string getParam() const;
		bool isAll(int (*f)(int), std::string param) const;
		int  count_chars(std::string param, char c) const;
		
		virtual T tryToConvert() = 0;
		virtual void printConverted() = 0;
	private:
		std::string _param;
		std::string _result;
};
#endif
