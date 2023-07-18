/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:26:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/17 22:14:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Derived.hpp"
#include <time.h>
#include <stdlib.h>

Base *generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	switch(i)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << p << " is type A (cast from pointer)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << p << " is type B (cast from pointer)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << p << "is type C (cast from pointer)" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << &a <<  " is type A (cast from reference)" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << &b <<  " is type B (cast from reference)" << std::endl;
		return ;
	}
	catch(std::exception& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << &c << " is type C (cast from reference)" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}

int	main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
