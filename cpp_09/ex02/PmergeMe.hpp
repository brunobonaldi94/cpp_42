/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:22:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/08/02 22:07:22 by bbonaldi         ###   ########.fr       */
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

		void InsertionSortDeque(std::deque<int> & deque, int left, int right);
		void InsertionSortVector(std::vector<int> & vector, int left, int right);
		void MergeDeque(std::deque<int> & deque, int left, int mid, int right);
		void MergeVector(std::vector<int> & vector, int left, int mid, int right);
		void SortDeque(std::deque<int> & deque, int left, int right);
		void SortVector(std::vector<int> & vector, int left, int right);
		void Sort(void);
		long long GetTime(void);
		void PrintElements(bool isBefore);
		void Print(void);
	private:
		std::deque <int> _deque;
		long double _time_deque;
		std::vector <int> _vector;
		long double _time_vector;
		static const int INSERTION_SORT_THRESHOLD = 5;
};

void debug(std::string param, std::string color);
#endif
