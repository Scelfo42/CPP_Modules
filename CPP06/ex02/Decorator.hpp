/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Decorator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:13:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 11:34:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DECORATOR_HPP
# define DECORATOR_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class Base;

template <typename T, typename X, typename Y>

void tryIdentify( Base& p, const std::string derivedName )
{
	try
	{
		(void)dynamic_cast<T&>(p);
		std::cout << "The actual type of the object pointed to by p is: " << derivedName[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<X&>(p);
			std::cout << "The actual type of the object pointed to by p is: " << derivedName[1] << std::endl;
			return ;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<Y&>(p);
				std::cout << "The actual type of the object pointed to by p is: " << derivedName[2] << std::endl;
				return ;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
			std::cerr << e.what() << std::endl;
		}
		std::cerr << e.what() << std::endl;
	}
}

Base*	generate( void );
void	identify( Base* );
void	identify( Base& );

#endif
