/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Decorator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:13:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:47 by cscelfo          ###   ########.fr       */
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

template <typename T>

void tryIdentify( Base& p, const std::string derivedName )
{
	try
	{
		(void)dynamic_cast<T&>(p);
		std::cout << "The actual type of the object pointed to by p is: " << derivedName << std::endl;
	}
	catch(const std::exception& e) { }
}

Base*	generate( void );
void	identify( Base* );
void	identify( Base& );

#endif
