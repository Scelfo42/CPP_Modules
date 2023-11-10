/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:05 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/10 15:43:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();

	std::cout << std::endl << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound();
	std::cout << wrongMeta->getType() << " " << std::endl;
	wrongMeta->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;
	delete wrongI;
	delete wrongMeta;

	return 0;
}
