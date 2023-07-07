/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:15:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 21:53:59 by bbonaldi         ###   ########.fr       */
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

std::string getCatIdea(Cat &cat, int index)
{
	std::string idea = cat.getBrain()->getIdeaByIndex(index);
	return idea;
}

std::string getDogIdea(Dog &dog, int index)
{
	std::string idea = dog.getBrain()->getIdeaByIndex(index);
	return idea;
}

void printAnimal(Animal &animal, std::string idea)
{
	animal.makeSound();
	std::cout << BLUE << "Type: " << animal.getType() << std::endl << "Idea: " << idea << RESET << std::endl;
}

void deepCopyTest()
{
	int index = 0;
	Cat cat1;
	cat1.getBrain()->setIdeaByIndex(index, "New Cat Idea");
	Cat cat2(cat1);
	Cat cat3;
	cat3 = cat1;
	printAnimal(cat1, getCatIdea(cat1, index));
	printAnimal(cat2, getCatIdea(cat2, index));
	printAnimal(cat3, getCatIdea(cat3, index));

	Dog dog1;
	dog1.getBrain()->setIdeaByIndex(index, "New Dog Idea");
	Dog dog2(dog1);
	Dog dog3;
	dog3 = dog1;
	printAnimal(dog1, getDogIdea(dog1, index));
	printAnimal(dog2, getDogIdea(dog2, index));
	printAnimal(dog3, getDogIdea(dog3, index));
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
