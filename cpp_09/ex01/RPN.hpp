/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:30:14 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/31 21:13:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream> 
#include "colors.hpp"

class RPN
{
	public:
		typedef int (*BinaryOperation)(int, int);
		typedef std::multimap<std::string, BinaryOperation> operations_map;
		RPN();
		RPN(RPN const &src);
		~RPN(void);
		RPN &operator=(RPN const &rhs);
		void Calculate(std::string arg);
		 static operations_map& getOperations();

	private:
		int	Pop();
		void Push(std::string value);
		BinaryOperation GetOperatorFunction(std::string arg);
		void DoOperation(RPN::BinaryOperation opFunction);
		void ParseArgv(std::string arg);
		std::stack<int> _stack;
		std::queue<std::string> _queue;
		static operations_map operations;
};
void debug(std::string param, std::string color);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int division(int a, int b);
#endif
