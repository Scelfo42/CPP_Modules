/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Decorator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:59:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/29 17:03:25 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

Base*	generate( void )
{
	srand(time(NULL));
	int randomNum = rand() % 3;

	switch (randomNum)
	{
		case 0:
			return new A;
			break ;
		case 1:
			return new B;
			break ;
		case 2:
			return new C;
			break ;
		default:
			std::cerr << "Error: randomNum is not between 0 and 2" << std::endl;
			return NULL;
			break;
	}
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "The actual type of the object pointed to by p is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The actual type of the object pointed to by p is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The actual type of the object pointed to by p is: C" << std::endl;
	else
		std::cerr << "Error: p is not pointing to an instance of A, B or C" << std::endl;
}

void	identify( Base& p )
{
	tryIdentify<A>(p, "A");
	tryIdentify<B>(p, "B");
	tryIdentify<C>(p, "C");
}
