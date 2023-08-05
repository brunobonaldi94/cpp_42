/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:41:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/08/05 11:27:46 by bbonaldi         ###   ########.fr       */
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
		if (argc < 2 || !isOnlyDigit(argv[i]))
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

long long PmergeMe::GetTime(void)
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<long long>(tv.tv_sec) * 1000000 + static_cast<long long>(tv.tv_usec);
}

void PmergeMe::PrintElementsBefore()
{
	size_t const MAX_SIZE = this->_vector.size();
	std::cout << "Before: ";
	for (size_t i = 0; i < MAX_SIZE; i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::PrintElementsAfter()
{
	std::cout << "After: ";
	size_t const MAX_SIZE = this->_mainChainVector.size();
	for (size_t i = 0; i < MAX_SIZE; i++)
		std::cout << this->_mainChainVector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::CreateDequePairs(void)
{
	size_t const MAX_SIZE = this->_deque.size() - 1;
	for (size_t i = 0; i < MAX_SIZE; i += 2)
		this->_dequePairs.push_back(std::make_pair(this->_deque[i], this->_deque[i + 1]));
}

void PmergeMe::SortDequePairs(void)
{
	size_t size = this->_dequePairs.size();
	for (size_t i = 0; i < size; i++)
	{
		int first = this->_dequePairs[i].first;
		int second = this->_dequePairs[i].second; 
		if (first < second)
		{
			this->_dequePairs[i].first = second;
			this->_dequePairs[i].second = first;
		}
	}
}


void PmergeMe::MergeDequePairs(std::deque<std::pair<int, int> > & dequePairs, int left, int middle, int right)
{
	std::deque<std::pair<int, int> > leftDeque(dequePairs.begin() + left, dequePairs.begin() + middle + 1);
	std::deque<std::pair<int, int> > rightDeque(dequePairs.begin() + middle + 1, dequePairs.begin() + right + 1);

	size_t i = 0;
	size_t j = 0;
	int k = left;

	while (i < leftDeque.size() && j < rightDeque.size())
	{
		if (leftDeque[i].first <= rightDeque[j].first)
		{
			dequePairs[k] = leftDeque[i];
			i++;
		} 
		else 
		{
			dequePairs[k] = rightDeque[j];
			j++;
		}
		k++;
	}

	while (i < leftDeque.size())
	{
		dequePairs[k] = leftDeque[i];
		i++;
		k++;
	}

	while (j < rightDeque.size())
	{
		dequePairs[k] = rightDeque[j];
		j++;
		k++;
	}
}

void PmergeMe::MergeSortDequePairs(std::deque<std::pair<int, int> > & dequePairs, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		this->MergeSortDequePairs(dequePairs, left, middle);
		this->MergeSortDequePairs(dequePairs, middle + 1, right);
		this->MergeDequePairs(dequePairs, left, middle, right);
	}
}

void PmergeMe::CreateMainChainAndPendingElementsDeque()
{
	size_t i;

	this->_mainChainDeque.push_back(this->_dequePairs.at(0).second);

	i = 0;
	while (i < this->_dequePairs.size())
	{
		this->_mainChainDeque.push_back(this->_dequePairs.at(i).first);
		this->_pendingElementsDeque.push_back(this->_dequePairs.at(i).second);
		i++;
	}
}

void PmergeMe::CreateJacobsthalDequeSequence()
{
	size_t size = this->_pendingElementsDeque.size();

	for (size_t index = 3; index < size; ++index)
	{
		size_t jcobstalIndex = this->JacobsThal(index);
		if (jcobstalIndex >= size - 1)
			break;
		this->_jacobsthalSequenceDeque.push_back(jcobstalIndex);
	}

}

void PmergeMe::CreatePositionsDeque(void)
{
	if (!this->_pendingElementsDeque.empty())
	{
		this->CreateJacobsthalDequeSequence();
		size_t lastPos = 1;
		size_t val = 1;
		
		while (!this->_jacobsthalSequenceDeque.empty())
		{
			val = this->_jacobsthalSequenceDeque.front();
			this->_jacobsthalSequenceDeque.pop_front();
			this->_positionsDeque.push_back(val);

			for (size_t pos = val - 1; pos > lastPos; pos--)
				this->_positionsDeque.push_back(pos);
			lastPos = val;
		}
		size_t size = this->_pendingElementsDeque.size();
		while (val++ < size)
			this->_positionsDeque.push_back(val);
	}
}

int PmergeMe::BinarySearchDeque(std::deque <int> deque, int x, int left, int right)
{
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (x == deque.at(mid))
			return (mid);

		if (x > deque.at(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (x > deque.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::insertIntoMainDequeChain()
{
	std::deque<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t pos;
	bool isOdd = this->_deque.size() % 2 != 0;

	this->CreatePositionsDeque();
	addedCount = 0;

	for (it = this->_positionsDeque.begin(); it < this->_positionsDeque.end(); it++)
	{
		target = this->_pendingElementsDeque.at(*it - 1);

		endPos = *it + addedCount;
		pos = this->BinarySearchDeque(this->_mainChainDeque, target, 0, endPos);
		this->_mainChainDeque.insert(this->_mainChainDeque.begin() + pos, target);
		addedCount++;
	}
	if (isOdd)
	{
		target = this->_deque.at(this->_deque.size() - 1);
		pos = this->BinarySearchDeque(this->_mainChainDeque, target, 0, this->_mainChainDeque.size() - 1);
		this->_mainChainDeque.insert(this->_mainChainDeque.begin() + pos, target);
	}
}

void PmergeMe::FordJohnsonAlgorithmDeque(void)
{
	if (this->_deque.size() == 1)
		return;
	this->CreateDequePairs();
	this->SortDequePairs();
	this->MergeSortDequePairs(this->_dequePairs, 0, this->_dequePairs.size() - 1);
	this->CreateMainChainAndPendingElementsDeque();
	this->insertIntoMainDequeChain();
}

void PmergeMe::CreateVectorPairs(void)
{
	size_t const MAX_SIZE = this->_vector.size() - 1;
	for (size_t i = 0; i < MAX_SIZE; i += 2)
		this->_vectorPairs.push_back(std::make_pair(this->_vector[i], this->_vector[i + 1]));
}

void PmergeMe::SortVectorPairs(void)
{
	size_t size = this->_vectorPairs.size();
	for (size_t i = 0; i < size; i++)
	{
		int first = this->_vectorPairs[i].first;
		int second = this->_vectorPairs[i].second; 
		if (first < second)
		{
			this->_vectorPairs[i].first = second;
			this->_vectorPairs[i].second = first;
		}
	}
}

void PmergeMe::MergeVectorPairs(std::vector<std::pair<int, int> > & vectorPairs, int left, int middle, int right)
{
	std::vector<std::pair<int, int> > leftVector(vectorPairs.begin() + left, vectorPairs.begin() + middle + 1);
	std::vector<std::pair<int, int> > rightVector(vectorPairs.begin() + middle + 1, vectorPairs.begin() + right + 1);

	size_t i = 0;
	size_t j = 0;
	int k = left;

	while (i < leftVector.size() && j < rightVector.size())
	{
		if (leftVector[i].first <= rightVector[j].first)
		{
			vectorPairs[k] = leftVector[i];
			i++;
		} 
		else 
		{
			vectorPairs[k] = rightVector[j];
			j++;
		}
		k++;
	}

	while (i < leftVector.size())
	{
		vectorPairs[k] = leftVector[i];
		i++;
		k++;
	}

	while (j < rightVector.size())
	{
		vectorPairs[k] = rightVector[j];
		j++;
		k++;
	}
}

void PmergeMe::MergeSortVectorPairs(std::vector<std::pair<int, int> > & vectorPairs, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		this->MergeSortVectorPairs(vectorPairs, left, middle);
		this->MergeSortVectorPairs(vectorPairs, middle + 1, right);
		this->MergeVectorPairs(vectorPairs, left, middle, right);
	}
}

int PmergeMe::JacobsThal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (JacobsThal(n - 1) + 2 * JacobsThal(n - 2));
}

void PmergeMe::CreateMainChainAndPendingElementsVector()
{
	size_t i;

	this->_mainChainVector.push_back(this->_vectorPairs.at(0).second);

	i = 0;
	while (i < this->_vectorPairs.size())
	{
		this->_mainChainVector.push_back(this->_vectorPairs.at(i).first);
		this->_pendingElementsVector.push_back(this->_vectorPairs.at(i).second);
		i++;
	}
}

void PmergeMe::CreateJacobsthalVectorSequence()
{
	size_t size = this->_pendingElementsVector.size();

	for (size_t index = 3; index < size; ++index)
	{
		size_t jcobstalIndex = this->JacobsThal(index);
		if (jcobstalIndex >= size - 1)
			break;
		this->_jacobsthalSequenceVector.push_back(jcobstalIndex);
	}

}

void PmergeMe::CreatePositionsVector(void)
{
	if (!this->_pendingElementsVector.empty())
	{
		this->CreateJacobsthalVectorSequence();
		size_t lastPos = 1;
		size_t val = 1;
		
		while (!this->_jacobsthalSequenceVector.empty())
		{
			val = this->_jacobsthalSequenceVector.front();
			this->_jacobsthalSequenceVector.erase(this->_jacobsthalSequenceVector.begin());
			this->_positionsVector.push_back(val);

			for (size_t pos = val - 1; pos > lastPos; pos--)
				this->_positionsVector.push_back(pos);
			lastPos = val;
		}
		size_t size = this->_pendingElementsDeque.size();
		while (val++ < size)
			this->_positionsVector.push_back(val);
	}
}

int PmergeMe::BinarySearchVector(std::vector<int> vector, int x, int left, int right)
{
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (x == vector.at(mid))
			return (mid);

		if (x > vector.at(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (x > vector.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::insertIntoMainVectorChain()
{
	std::vector<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t pos;
	bool isOdd = this->_deque.size() % 2 != 0;

	this->CreatePositionsVector();
	addedCount = 0;

	for (it = this->_positionsVector.begin(); it < this->_positionsVector.end(); it++)
	{
		target = this->_pendingElementsVector.at(*it - 1);

		endPos = *it + addedCount;
		pos = this->BinarySearchVector(this->_mainChainVector, target, 0, endPos);
		this->_mainChainVector.insert(this->_mainChainVector.begin() + pos, target);
		addedCount++;
	}
	if (isOdd)
	{
		target = this->_vector.at(this->_vector.size() - 1);
		pos = this->BinarySearchVector(this->_mainChainVector, target, 0, this->_mainChainVector.size() - 1);
		this->_mainChainVector.insert(this->_mainChainVector.begin() + pos, target);
	}
}

void PmergeMe::FordJohnsonAlgorithmVector(void)
{
	if (this->_vector.size() == 1)
		return;
	this->CreateVectorPairs();
	this->SortVectorPairs();
	this->MergeSortVectorPairs(this->_vectorPairs, 0, this->_vectorPairs.size() - 1);
	this->CreateMainChainAndPendingElementsVector();
	this->insertIntoMainVectorChain();
}

void PmergeMe::Sort(void)
{
	long long start_time = this->GetTime();
	this->FordJohnsonAlgorithmDeque();
	long long end_time = this->GetTime();
	this->_time_deque = end_time - start_time;

	start_time = this->GetTime();
	this->FordJohnsonAlgorithmVector();
	end_time = this->GetTime();
	this->_time_vector = end_time - start_time;
}

void PmergeMe::Print(void)
{
	if (this->_vector.size() == 0)
	{
		std::cout << "No elements to print" << std::endl;
		return;
	}
	this->PrintElementsBefore();
	this->Sort();
	this->PrintElementsAfter();
	std::cout << "Time to process a range of: " << this->_vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << this->_time_vector  << " us" << std::endl;
	std::cout << "Time to process a range of: " << this->_deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << this->_time_deque << " us" << std::endl;
}
