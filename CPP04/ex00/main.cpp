/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:05 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 12:05:33 by cscelfo          ###   ########.fr       */
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

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongI->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrongI->makeSound();
	wrongMeta->makeSound();

	delete i;
	delete j;
	delete meta;
	delete wrongI;
	delete wrongMeta;

	return 0;
}
