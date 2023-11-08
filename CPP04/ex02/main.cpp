/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:05 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 12:00:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal*	array[4];

	std::cout << std::endl;
	std::cout << std::endl;

	for(int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			try {
				array[i] = new Cat();
			} catch (const std::bad_alloc& err) {
				std::cerr << "Caught bad_alloc exception: " << err.what() << std::endl;
				array[i] = NULL;
			}
		}
		else
		{
			try {
				array[i] = new Dog();
			} catch (const std::bad_alloc& err) {
				std::cerr << "Caught bad_alloc exception: " << err.what() << std::endl;
				array[i] = NULL;
			}
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < 4; i++)
		array[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete array[i];
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
