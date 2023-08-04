/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:22:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/08/03 23:04:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include "colors.hpp"
#include "defines.hpp"
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
	public:
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &obj);
		virtual ~PmergeMe(void);
		PmergeMe	&operator = (const PmergeMe &obj);

		void Sort(void);
		long long GetTime(void);
		int JacobsThal(int n);

		void CreateDequePairs(void);
		void SortDequePairs(void);
		void MergeDequePairs(std::deque<std::pair<int, int> > & dequePairs, int left, int middle ,int right);
		void MergeSortDequePairs(std::deque<std::pair<int, int> > & dequePairs, int left, int right);
		void CreateMainChainAndPendingElementsDeque(void);
		
		int BinarySearchDeque(std::deque <int> deque, int left, int right, int x);
		void CreateJacobsthalDequeSequence(void);
		void CreatePositionsDeque(void);
		void insertIntoMainDequeChain(void);
		
		void FordJohnsonAlgorithmDeque(void);

		void CreateVectorPairs(void);
		void SortVectorPairs(void);
		void MergeVectorPairs(std::vector<std::pair<int, int> > & vectorPairs, int left, int middle, int right);
		void MergeSortVectorPairs(std::vector<std::pair<int, int> > & vectorPairs, int left, int right);
		void CreateMainChainAndPendingElementsVector(void);

		int BinarySearchVector(std::vector<int> vector, int left, int right, int x);
		void CreateJacobsthalVectorSequence(void);
		void CreatePositionsVector(void);
		void insertIntoMainVectorChain(void);

		void FordJohnsonAlgorithmVector(void);

		void PrintElementsBefore();
		void PrintElementsAfter();
		void Print(void);
	private:
		std::deque <int> _deque;
		std::deque <std::pair<int, int> > _dequePairs;
		std::deque <int> _mainChainDeque;
		std::deque <int> _pendingElementsDeque;
		std::deque <int> _jacobsthalSequenceDeque;
		std::deque <int> _positionsDeque;
		long double _time_deque;

		std::vector <int> _vector;
		std::vector <std::pair<int, int> > _vectorPairs;
		std::vector <int> _mainChainVector;
		std::vector <int> _pendingElementsVector;
		std::vector <int> _jacobsthalSequenceVector;
		std::vector <int> _positionsVector;
		long double _time_vector;
};

void debug(std::string param, std::string color);
#endif
