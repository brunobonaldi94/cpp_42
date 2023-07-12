/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AData.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:32:01 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/11 22:41:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AData.hpp"

template <typename T>
AData<T>::AData() : _param("")
{
	std::cout << "AData default constructor called" << std::endl;	
}

template <typename T>
AData<T>::AData(std::string param) : _param(param)
{
	std::cout << "AData parametric constructor called" << std::endl;	
}

template <typename T>
AData<T>::~AData()
{
	std::cout << "AData destructor called" << std::endl;	
}

template <typename T>
AData<T>::AData(AData const &data)
{
	std::cout << "AData copy constructor called" << std::endl;	
	*this = data;
}

template <typename T>
AData<T> & AData<T>::operator=(AData<T> const &rhs)
{
	std::cout << "AData assignation operator called" << std::endl;	
	if (this != &rhs)
		this->_param = rhs._param;
	return (*this);
}

template <typename T>
void AData<T>::setParam(std::string param)
{
	this->_param = param;
}

template <typename T>
std::string AData<T>::getParam() const
{
	return (this->_param);
}

template<typename T>
bool AData<T>::isAll(int (*f)(int), std::string param) const
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

template<typename T>
int AData<T>::count_chars(std::string param, char c) const
{
	int count = 0;

	for (size_t i = 0; i < param.length(); i++)
	{
		if (param[i] == c)
			count++;
	}
	return count;
}

template<typename T>
AData<T>::BadCast::BadCast(std::string result): _result(result){}

template<typename T>
const char * AData<T>::BadCast::what() const throw()
{
	return (this->_result.c_str());
}


template<typename T>
std::string AData<T>::BadCast::getResult() const
{
	return (this->_result.c_str());
}

template<typename T>
AData<T>::BadCast::~BadCast() throw (){}


template class AData<int>;
template class AData<char>;
template class AData<float>;
template class AData<double>;
