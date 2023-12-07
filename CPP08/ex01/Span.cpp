/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:17:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/07 19:34:04 by cscelfo          ###   ########.fr       */
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
			for (size_t i = 0; i < input.size(); i++)
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

static bool isContainerOrdered( std::vector<int>::iterator it, const std::vector<int>::iterator& it_end )
{
	for (; it != it_end - 1; it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

static int longest( std::vector<int>& container )
{
	return container[container.size() - 1] - container[0];
}

static int shortest( std::vector<int>::iterator& it, const std::vector<int>::iterator& it_end )
{
	int shortest = std::numeric_limits<int>::max();
	int relativeDiff = 0;

	for (; it != it_end - 1; it++)
	{
		relativeDiff = *(it + 1) - *it;
		if (relativeDiff < shortest)
			shortest = relativeDiff;
	}

	return shortest;
}

static int calculateSpan(std::vector<int>& container, const int& request)
{
	std::vector<int>::iterator it = container.begin();
	std::vector<int>::iterator it_end = container.end();

	if (!isContainerOrdered(it, it_end))
		std::sort(it, it_end);
	return (request == 0 ? shortest(it, it_end) : longest(container));
}

int	Span::shortestSpan( void )
{
	return calculateSpan(_container, 0);
}

int	Span::longestSpan( void )
{
	return calculateSpan(_container, 1);
}
