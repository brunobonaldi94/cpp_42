/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:15:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/15 23:09:31 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << std::string(50, '-') << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound(); //will output the animal sound!
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wc;

	return 0;
}
