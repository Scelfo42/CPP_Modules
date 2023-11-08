/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:31:00 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 11:55:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//========= CONSTRUCTOR =========//

Brain::Brain( void ) { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain( const Brain& sourceClass )
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = sourceClass;
}

//========= DESTRUCTOR =========//

Brain::~Brain( void ) { std::cout << "Brain destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Brain&	Brain::operator=( const Brain& sourceClass )
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &sourceClass)
	{
		for (int i = 0; i < 100; i++)
			this->setIdea(i, sourceClass.getIdea(i));
	}
	return *this;
}

//========= GETTER =========//

std::string	Brain::getIdea( int index ) const { return this->_ideas[index]; }

//========= SETTER =========//

void	Brain::setIdea( int index, std::string idea ) { this->_ideas[index] = idea; }
