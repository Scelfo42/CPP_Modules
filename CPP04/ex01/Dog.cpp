/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:41:51 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 11:56:34 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//========= CONSTRUCTOR =========//

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch(const std::bad_alloc& err) {
		std::cerr << "Caught bad_alloc: " << err.what() << '\n';
		this->_brain = NULL;
	}
}

Dog::Dog( const Dog& sourceClass ) : Animal(sourceClass) { std::cout << "Dog copy constructor called" << std::endl; }

//========= DESTRUCTOR =========//

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Dog&	Dog::operator=( const Dog& sourceClass )
{
	std::cout << "Dog assignment operator called" << std::endl;
	Animal::operator=(sourceClass);
	return *this;
}

//========= MEMBER FUNCTION =========//

void	Dog::makeSound( void ) const { std::cout << "Woof woof!" << std::endl; }