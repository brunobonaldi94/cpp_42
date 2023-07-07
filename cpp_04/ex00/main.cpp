/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:15:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 20:25:36 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void pdfTest()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << BLUE << j->getType() << RESET << std::endl;
	std::cout << BLUE << i->getType() << RESET << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

void wrongAnimalTest()
{
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	std::cout << BLUE << wc->getType() << RESET << std::endl;
	wc->makeSound(); //will output the animal sound!
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wc;
}

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	test();
	printSeparator();
}

int main()
{
	int const testNumbers = 2;
	void (*testFunctions[testNumbers])(void) = {
		pdfTest, wrongAnimalTest
	};
	std::string testNames[testNumbers] = {
		"PDF", "Wrong Animal"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
