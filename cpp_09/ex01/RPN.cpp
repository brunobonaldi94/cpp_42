/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/31 21:18:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	debug("RPN default constructor called", BLUE);
}

RPN::RPN(RPN const &src)
{
	debug("RPN copy constructor called", BLUE);
	*this = src;
}

RPN::~RPN(void)
{
	debug("RPN destructor called", BLUE);
}

RPN &RPN::operator=(RPN const &rhs)
{
	debug("RPN assignation operator called", BLUE);
	if (this != &rhs)
		this->_stack = rhs._stack;
	return (*this);
}

RPN::BinaryOperation RPN::GetOperatorFunction(std::string op)
{
	RPN::operations_map::iterator it = RPN::operations.find(op);
	if (it == RPN::operations.end())
		return (NULL);
	return it->second;
}

int RPN::Pop()
{
	if (this->_stack.size() == 0)
		throw std::runtime_error("Invalid Expression");
	int num = this->_stack.top();
	this->_stack.pop();
	return num;
}

void RPN::Push(std::string value)
{
	if (value.length() > 1 || !std::isdigit(value[0]))
		throw std::runtime_error("Error");

	int num = static_cast<char>(value[0]) - '0';
	this->_stack.push(num);
}

void RPN::DoOperation(RPN::BinaryOperation opFunction)
{
	int num1 = this->Pop();
	int num2 = this->Pop();
	int result = opFunction(num2, num1);
	this->_stack.push(result);
}

void RPN::ParseArgv(std::string arg)
{
	std::stringstream ss(arg);
	std::string currentString;
	while(std::getline(ss, currentString, ' '))
		this->_queue.push(currentString);
}

void RPN::Calculate(std::string arg)
{
	try 
	{
		RPN::getOperations();
		this->ParseArgv(arg);
		if (this->_queue.size() < 2)
			throw std::runtime_error("Not enough arguments");
		while (!this->_queue.empty())
		{
			std::string arg = this->_queue.front();
			RPN::BinaryOperation opFunction = this->GetOperatorFunction(arg);
			if (opFunction)
				this->DoOperation(opFunction);
			else
				this->Push(arg);
			this->_queue.pop();
		}
		if (this->_stack.size() != 1)
			throw std::runtime_error("Invalid expression");
		std::cout << this->_stack.top() << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int division(int a, int b)
{
	if (b == 0)
		throw std::runtime_error("Division by zero");
	return a / b;
}

RPN::operations_map RPN::operations;

RPN::operations_map& RPN::getOperations() {
    if (RPN::operations.empty()) {
        RPN::operations.insert(std::make_pair("+", &add));
        RPN::operations.insert(std::make_pair("-", &sub));
        RPN::operations.insert(std::make_pair("*", &mul));
        RPN::operations.insert(std::make_pair("/", &division));
    }
    return operations;
}
