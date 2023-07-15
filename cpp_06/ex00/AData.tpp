/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AData.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:32:01 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 11:28:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AData.hpp"

template <typename T, typename R>

AData<T, R>::AData() : _param(""), _isPseudoLiteral(false)
{
	debug("AData default constructor called", BLUE);
}

template <typename T, typename R>

AData<T, R>::AData(std::string param) : _param(param), _isPseudoLiteral(false)
{
	debug("AData parametric constructor called", BLUE);
}

template <typename T, typename R>

AData<T, R>::~AData()
{
	debug("AData destructor called", BLUE);
}

template <typename T, typename R>

AData<T, R>::AData(AData const &data)
{
	debug("AData copy constructor called", BLUE)
	*this = data;
}

template <typename T, typename R>

AData<T, R> & AData<T, R>::operator=(AData<T, R> const &rhs)
{
	debug("AData assignation operator called", BLUE);
	if (this != &rhs)
		this->_param = rhs._param;
	return (*this);
}

template<typename T, typename R>
bool AData<T, R>::isAll(int (*f)(int), std::string param) const
{
	if (param.length() == 0)
		return false;
	for (size_t i = 0; i < param.length(); i++)
	{
		if (!f(static_cast<int>(param[i])))
			return false;
	}
	return true;
}

template<typename T, typename R>
size_t AData<T, R>::count_chars(std::string param, char c) const
{
	size_t count = 0;

	for (size_t i = 0; i < param.length(); i++)
	{
		if (param[i] == c)
			count++;
	}
	return count;
}

template<typename T, typename R>
std::string AData<T, R>::eraseParamFromChar(std::string param, char c) const
{
	size_t pos = param.find(c);
	if (pos != std::string::npos)
		param.erase(pos, 1);
	return param;
}

template<typename T, typename R>
std::string AData<T, R>::getPseudoLiterals(std::string param)
{
	bool isFloatingPoint = typeid(T) == typeid(float) || typeid(T) == typeid(double);
	int const countPseudoLiterals = 8;

	std::string pseudoLiterals[countPseudoLiterals] = {
		"nanf", "inff", "+inff", "-inff",
		"nan", "inf", "+inf", "-inf",

	};

	for (int i = 0; i < countPseudoLiterals; i++)
	{
		if (param == pseudoLiterals[i])
		{
			if (isFloatingPoint && param[0] == 'n')
				this->_resultOverUnderFlow = std::numeric_limits<T>::quiet_NaN();
			else if (isFloatingPoint)
				this->_resultOverUnderFlow =  std::numeric_limits<T>::infinity();
			this->_isPseudoLiteral = true;
			return pseudoLiterals[i];
		}
	}
	return "";
}

template<typename T, typename R>
bool AData<T, R>::checkConversion(R paramConverted) const
{
	bool isIntOrChar = typeid(T) == typeid(char) || typeid(T) == typeid(int);
	if (isIntOrChar)
	{
		if (paramConverted > std::numeric_limits<T>::max() || paramConverted < std::numeric_limits<T>::min())
		{
			debug("Overflow or underflow.", RED);
			return false;
		}
		return true;
	}
	else
	{

		if (paramConverted > std::numeric_limits<T>::max() || paramConverted < -std::numeric_limits<T>::max())
		{
			debug("Overflow or underflow.", RED);
			return false;
		}
		if (paramConverted > 0 && paramConverted < std::numeric_limits<T>::min())
		{
			debug("Overflow or underflow.", RED);
			return false;
		}
		return true;
	}
}

template<typename T, typename R>
AData<T, R>::BadCast::BadCast(std::string result): _result(result){}

template<typename T, typename R>
const char * AData<T, R>::BadCast::what() const throw()
{
	return (this->_result.c_str());
}

template<typename T, typename R>
std::string AData<T, R>::BadCast::getResult() const
{
	return (this->_result.c_str());
}

template<typename T, typename R>
AData<T, R>::BadCast::~BadCast() throw (){}
