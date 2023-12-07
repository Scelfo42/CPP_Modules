/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:17:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/07 18:19:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
{
	std::string input;
	long int n;

	std::cout << "A number is mandatory." << std::endl << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Enter the size of the container: ";
		std::getline(std::cin, input);
		if (input.empty() || std::cin.eof())
			break ;
		else
		{
			for (int i = 0; i < input.size(); i++)
			{
				if (!isdigit(input[i]))
				{
					std::cout << "Input must be a number." << std::endl;
					continue ;
				}
			}
			n = std::atol(input.c_str());
			if (n >= 0 && n < std::numeric_limits<unsigned int>::max())
			{
				this->_maxSize = static_cast<unsigned int>(n);
				return ;
			}
			std::cout << "The container size must be an unsigned int." << std::endl;
			continue ;
		}
	}
	std::cout << std::endl;
	std::cerr << "Input got destroyed or was empty, constructing with a default size (0)..." << std::endl;
	this->_maxSize = 0;
}

Span::Span( unsigned int n ) : _maxSize(n) { }

Span::Span( const Span& src ) { *this = src; }

Span::~Span( void ) { }

Span&	Span::operator=( const Span& src )
{
	if (this != &src)
		this->_container = src._container;
	return *this;
}

void	Span::addNumber( int number )
{
	try
	{
		if (_container.size() == _maxSize)
			throw Span::ContainerFullException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	_container.push_back(number);	
}

static bool isContainerOrdered(std::vector<int>& container)
{
	return std::is_sorted(container.begin(), container.end());
}

int	Span::shortestSpan( void )
{
	if (isContainerOrdered(_container))
		return _container[1] - _container[0];
}
