/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:15:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/19 23:25:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::string(50, '-') << std::endl;

	Animal* animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::string(50, '-') << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			Dog *dog;
			dog = dynamic_cast<Dog *>(animals[i]);
			std::cout << dog->getBrain()->getIdeaByIndex(i) << std::endl;
		}
		else
		{
			Cat *cat;
			cat = dynamic_cast<Cat *>(animals[i]);
			std::cout << cat->getBrain()->getIdeaByIndex(i) << std::endl;
		}	
		delete animals[i];
	}
	
	return 0;
}
