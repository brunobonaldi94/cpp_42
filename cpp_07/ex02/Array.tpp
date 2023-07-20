/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:30:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/19 21:56:41 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _n(0), _array(NULL)
{
	debug("Default constructor called", YELLOW);
	this->_array = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
	debug("Parametric constructor called", YELLOW);
	if (n == 0)
	{
		this->_array = NULL;
		return;
	}
	this->_array = new T[n];
}

template <typename T>
Array<T>::Array(Array<T> const &src): _n(0), _array(NULL)
{
	debug("Copy constructor called", YELLOW);
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	debug("Destructor called", YELLOW);
	if (!this->isEmpty())
		delete [] this->_array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const &rhs)
{
	debug("Assignation operator called", YELLOW);
	if (this != &rhs)
	{
		if (!this->isEmpty())
			delete [] this->_array;
		this->_n = rhs.size();
		this->_array = new T[this->size()];
		for (size_t i = 0; i < this->size(); i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->size())
		throw Array::OutOfBoundsException(index, this->size());
	return (this->_array[index]);
}

template <typename T>
const T&  Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size())
		throw Array::OutOfBoundsException(index, this->size());
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_n);
}

template <typename T>
bool Array<T>::isEmpty() const
{
	return (this->size() == 0);
}

template <typename T>
std::ostream &operator<<(std::ostream &os,  Array<T> const &src)
{
	os << YELLOW << "Array size: " << src.size() << RESET << std::endl;
	os << BLUE << "Array content: [";
	for (unsigned int i = 0; i < src.size(); i++)
	{
		os << src[i];
		if (i < src.size() - 1)
			os << ", ";
	}
	os << "]" << RESET << std::endl;
	return (os);
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(unsigned int index, unsigned int n) : _index(index), _n(n)
{
	debug("OutOfBoundsException constructor called", RED);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	std::cout  << RED << "Index " << this->_index << " is out of bounds, size is " << this->_n << RESET << std::endl;
	return "OutOfBoundsException: Index is out of bounds\n";
}
