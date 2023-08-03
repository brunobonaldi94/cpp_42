/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:41:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/08/02 21:38:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isOnlyDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	debug("PmergeMe Constructor called", GREEN);
	for (int i = 1; i < argc; i++)
	{
		if (!isOnlyDigit(argv[i]))
			throw std::invalid_argument("It must be numeric arguments");
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

void PmergeMe::InsertionSortDeque(std::deque<int> & deque, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = deque[i];
        int j = i - 1;

        while (j >= left && deque[j] > key) {
            deque[j + 1] = deque[j];
            j--;
        }
        deque[j + 1] = key;
    }
}

void PmergeMe::MergeDeque(std::deque<int> & deque, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
	std::deque<int> L(n1);
    std::deque<int> R(n2);
	for (int i = 0; i < n1; i++) {
        L[i] = deque[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = deque[mid + 1 + j];
    }

	int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deque[k] = L[i];
            i++;
        } else {
            deque[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        deque[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        deque[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::SortDeque(std::deque<int> & deque, int left, int right)
{
	 if (right - left <= this->INSERTION_SORT_THRESHOLD) {
        this->InsertionSortDeque(deque, left, right);
    } else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            this->SortDeque(deque, left, mid);
            this->SortDeque(deque, mid + 1, right);
            this->MergeDeque(deque, left, mid, right);
        }
    }
}

void PmergeMe::InsertionSortVector(std::vector<int> & vector, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = vector[i];
        int j = i - 1;

        while (j >= left && vector[j] > key) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
}

void PmergeMe::MergeVector(std::vector<int> & vector, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
	std::vector<int> L(n1);
    std::vector<int> R(n2);
	for (int i = 0; i < n1; i++) {
        L[i] = vector[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vector[mid + 1 + j];
    }

	int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        } else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vector[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vector[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::SortVector(std::vector<int> & vector, int left, int right)
{
	 if (right - left <= this->INSERTION_SORT_THRESHOLD) {  // Threshold for switching to insertion sort
        this->InsertionSortVector(vector, left, right);
    } else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            this->SortVector(vector, left, mid);
            this->SortVector(vector, mid + 1, right);
            this->MergeVector(vector, left, mid, right);
        }
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

void PmergeMe::PrintElements(bool isBefore)
{
	std::cout << (isBefore ? "Before: " : "After: ");
	size_t const MAX_SIZE = this->_vector.size();
	for (size_t i = 0; i < this->_vector.size() && i < MAX_SIZE; i++)
		std::cout << this->_vector[i] << " ";
	if (this->_vector.size() > MAX_SIZE)
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::Print(void)
{
	this->PrintElements(true);
	this->Sort();
	this->PrintElements(false);
	std::cout << "Time to process a range of: " << this->_vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << this->_time_vector  << " us" << std::endl;
	std::cout << "Time to process a range of: " << this->_deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << this->_time_deque << " us" << std::endl;
}
