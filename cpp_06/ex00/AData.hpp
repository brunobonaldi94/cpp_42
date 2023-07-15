#ifndef ADATA_HPP
#define ADATA_HPP

#include <iostream>
#include <exception>
#include "colors.hpp"
#include <cstdlib>
#include "defines.hpp"
#include <limits>
#include <typeinfo>

template <typename T, typename R>
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
		size_t  count_chars(std::string param, char c) const;
		std::string getPseudoLiterals(std::string param);
		bool checkConversion(R paramConverted) const;
		std::string eraseCharFromParam(std::string param, char c) const;
		std::string removeSign(std::string param) const;
		
		virtual T tryToConvert() = 0;
		virtual bool checkLimits() = 0;
		virtual R handleResultOverUnderFlow(std::string param) = 0;
		virtual void printConverted() = 0;

	protected:
		std::string _param;
		bool _isPseudoLiteral;
		T _result;
		R _resultOverUnderFlow;
};

void debug(std::string param, std::string color);

#include "AData.tpp"


#endif

