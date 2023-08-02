/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:41:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/08/01 22:15:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
	debug("PmergeMe Constructor called", GREEN);
	for (int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		if (num < 0)
			throw std::invalid_argument("Negative numbers are not allowed");
		this->_deque.push_back(num);
		this->_vector.push_back(num);
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	debug("PmergeMe Copy Constructor called", GREEN);
	*this = obj;
}

PmergeMe::~PmergeMe(void)
{
	debug("PmergeMe Destructor called", GREEN);
}

PmergeMe	&PmergeMe::operator = (const PmergeMe &obj)
{
	debug("PmergeMe Assignation operator called", GREEN);
	if (this != &obj)
	{
		this->_deque = obj._deque;
		this->_vector = obj._vector;
	}
	return (*this);
}

void PmergeMe::InsertionSortDeque(std::deque<int> & deque,  int l,  int r)
{
	for (int i = l; i < r; i++) {
		int tempVal = deque[i + 1];
		int j = i + 1;
		while (j > l && deque[j - 1] > tempVal) {
			deque[j] = deque[j - 1];
			j--;
		}
		deque[j] = tempVal;
	}
}

void PmergeMe::MergeDeque(std::deque<int> & deque,  int l,  int m,  int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	std::deque< int> LA(deque.begin() + l, deque.begin() + m + 1);
	std::deque< int> RA(deque.begin() + m + 1, deque.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = l; i < r - l + 1; i++) {
		if (RIDX == n2) {
			deque[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			deque[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			deque[i] = LA[LIDX];
			LIDX++;
		} else {
			deque[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void PmergeMe::SortDeque(std::deque<int> & deque, int l, int r)
{
	if (r - l > this->INSERTION_SORT_THRESHOLD) {
		int q = (l + r) / 2;
		this->SortDeque(deque, l, q);
		this->SortDeque(deque, q + 1, r);
		this->MergeDeque(deque, l, q, r);
	} else {
		this->InsertionSortDeque(deque, l, r);
	}
}



void PmergeMe::InsertionSortVector(std::vector<int> & vector,  int l,  int r)
{
	for (int i = l; i < r; i++) {
		int tempVal = vector[i + 1];
		int j = i + 1;
		while (j > l && vector[j - 1] > tempVal) {
			vector[j] = vector[j - 1];
			j--;
		}
		vector[j] = tempVal;
	}
}

void PmergeMe::MergeVector(std::vector<int> & vector,  int l,  int m,  int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	std::vector< int> LA(vector.begin() + l, vector.begin() + m + 1);
	std::vector< int> RA(vector.begin() + m + 1, vector.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = l; i < r - l + 1; i++) {
		if (RIDX == n2) {
			vector[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			vector[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			vector[i] = LA[LIDX];
			LIDX++;
		} else {
			vector[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void PmergeMe::SortVector(std::vector<int> & vector, int l, int r)
{
	if (r - l > this->INSERTION_SORT_THRESHOLD) {
		int q = (l + r) / 2;
		this->SortVector(vector, l, q);
		this->SortVector(vector, q + 1, r);
		this->MergeVector(vector, l, q, r);
	} else {
		this->InsertionSortVector(vector, l, r);
	}
}

long long PmergeMe::GetTime(void)
{
	timeval tv;
	gettimeofday(&tv, NULL);
    return static_cast<long long>(tv.tv_sec) * 1000000 + static_cast<long long>(tv.tv_usec);
}

void PmergeMe::Sort(void)
{
	long long start_time = this->GetTime();
	this->SortDeque(this->_deque, 0, this->_deque.size() - 1);
	long long end_time = this->GetTime();
	this->_time_deque = end_time - start_time;

	start_time = this->GetTime();
	this->SortVector(this->_vector, 0, this->_vector.size() - 1);
	end_time = this->GetTime();
	this->_time_vector = end_time - start_time;
}

void PmergeMe::Print(void)
{
	std::cout << "Before: ";
	if (this->_vector.size() < 5)
		for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
			std::cout << *it << " ";
	else
		for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.begin() + 4; it++)
			std::cout << *it << " ";
	std::cout << "[...]" << std::endl;
	this->Sort();
	std::cout << "After: ";
	if (this->_vector.size() < 5)
		for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
			std::cout << *it << " ";
	else
		for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.begin() + 4; it++)
			std::cout << *it << " ";
	std::cout << "[...]" << std::endl;
	std::cout << "Time to process a range of: " << this->_vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << this->_time_vector  << " us" << std::endl;
	std::cout << "Time to process a range of: " << this->_deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << this->_time_deque << " us" << std::endl;
}
