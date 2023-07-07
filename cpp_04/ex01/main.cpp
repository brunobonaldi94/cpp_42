/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:15:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 20:59:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void pdfTest()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void halfDogHalfCatTest()
{
	int const QTY = 10;
	Animal* animals[QTY];
	for (int i = 0; i < QTY; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < QTY; i++)
	{
		if (i % 2 == 0)
		{
			Dog *dog;
			dog = dynamic_cast<Dog *>(animals[i]);
			dog->makeSound();
			std::cout << BLUE << "DOG: " << i << " " << dog->getBrain()->getIdeaByIndex(i) << RESET << std::endl;
		}
		else
		{
			Cat *cat;
			cat = dynamic_cast<Cat *>(animals[i]);
			cat->makeSound();
			std::cout << YELLOW << "CAT: " << i  << " " << cat->getBrain()->getIdeaByIndex(i) << RESET << std::endl;
		}
		delete animals[i];
	}
}


void printCatOrDog(Animal *animal, int index, bool isCat = true)
{
	std::string idea;
	if (!isCat)
		idea = dynamic_cast<Dog *>(animal)->getBrain()->getIdeaByIndex(index);
	else
		idea = dynamic_cast<Cat *>(animal)->getBrain()->getIdeaByIndex(index);
	animal->makeSound();
	std::cout << BLUE << "Type: " << animal->getType() << std::endl << "Idea: " << idea << RESET << std::endl;
}

void deepCopyTest()
{
	int index = 0;
	Animal *cat1 = new Cat;
	dynamic_cast<Cat *>(cat1)->getBrain()->setIdeaByIndex(index, "New Cat Idea");
	Animal *cat2(cat1);
	Animal *cat3;
	cat3 = cat1;
	printCatOrDog(cat1, index);
	printCatOrDog(cat2, index);
	printCatOrDog(cat3, index);
	delete cat1;
}

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	test();
	printSeparator();
}

int main()
{
	int const testNumbers = 3;
	void (*testFunctions[testNumbers])(void) = {
		pdfTest, halfDogHalfCatTest, deepCopyTest
	};
	std::string testNames[testNumbers] = {
		"PDF", "Half Dog,Half Cat",	"Deep Copy"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
