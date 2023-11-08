/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:32:11 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 11:56:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//========= CONSTRUCTOR =========//

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch(const std::bad_alloc& err) {
		std::cerr << "Caught bad_alloc: " << err.what() << '\n';
		this->_brain = NULL;
	}
}

Cat::Cat( const Cat& sourceClass ) : Animal(sourceClass) { std::cout << "Cat copy constructor called" << std::endl; }

//========= DESTRUCTOR =========//

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Cat&	Cat::operator=( const Cat& sourceClass )
{
	std::cout << "Cat assignment operator called" << std::endl;
	Animal::operator=(sourceClass);
	return *this;
}

//========= MEMBER FUNCTION =========//

void	Cat::makeSound( void ) const { std::cout << "Meow meow!" << std::endl; }
