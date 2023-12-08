/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:17:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/08 19:10:56 by cscelfo          ###   ########.fr       */
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

static long int longest( std::vector<int>& container )
{
	return static_cast<long int>(container[container.size() - 1]) - static_cast<long int>(container[0]);
}

static long int shortest( std::vector<int>::const_iterator& it, const std::vector<int>::const_iterator& itEnd )
{
	long int shortest = LONG_MAX;
	long int relativeDiff = 0;

	for (; it != itEnd - 1; it++)
	{
		relativeDiff = static_cast<long int>(*(it + 1)) - static_cast<long int>(*it);
		if (relativeDiff < shortest)
			shortest = relativeDiff;
	}

	return shortest;
}

static bool isContainerOrdered( std::vector<int>::const_iterator it, const std::vector<int>::const_iterator& itEnd )
{
	for (; it != itEnd - 1; it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

static void addNumberHelper( Span& instance, const int& number, const size_t& count)
{
	std::vector<int>&	container = instance.getContainer();
	const unsigned int		maxSize = instance.getMaxSize();

	if (container.size() + count > maxSize)
		throw Span::ContainerFullException();
	for (size_t i = 0; i < count; i++)
		container.push_back(number);
}

void	Span::addNumber( const int& number ) { addNumberHelper(*this, number, 1); }

void	Span::addNumber( const long int& ) { throw Span::InvalidNumberException(); }

void	Span::addNumber( const long int& number, const size_t& count )
{
	if (count == 0)
		return ;
	else if (number < INT_MIN || number > INT_MAX)
		throw Span::InvalidNumberException();
	const int castedNumber = static_cast<int>(number);
	addNumberHelper(*this, castedNumber, count);
}

void	Span::addNumber( const size_t& count, std::string str )
{
	if (count == 0 || str.compare("random"))
		return ;
	else if (this->_container.size() + count > this->_maxSize)
		throw Span::ContainerFullException();
	srand(time(NULL));
	for (size_t i = 0; i < count; i++)
	{
		int random = rand() % INT_MAX;
		_container.push_back(random);
	}
}

static long int calculateSpan( std::vector<int>& container, const size_t& request)
{
	std::vector<int>::const_iterator it = container.begin();
	std::vector<int>::iterator sortIt = container.begin();
	std::vector<int>::iterator sortItEnd = container.end();
	std::vector<int>::const_iterator itEnd = container.end();
	
	if (!isContainerOrdered(it, itEnd))
		std::sort(sortIt, sortItEnd);
	return (request == 0 ? shortest(it, itEnd) : longest(container));	
}

long int	Span::shortestSpan( void )
{
	if (_container.size() < 2)
		throw Span::ContainerFewElementsException();
	return calculateSpan(_container, 0);
}

long int	Span::longestSpan( void )
{
	if (_container.size() < 2)
		throw Span::ContainerFewElementsException();
	return calculateSpan(_container, 1);
}

std::vector<int>&	Span::getContainer( void ) { return _container; }

const unsigned int&		Span::getMaxSize( void ) const { return _maxSize; }
