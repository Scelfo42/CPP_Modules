/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:16:22 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 15:42:11 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie( void );
		~Zombie( void );

		void	announce( void );
		void	setName( std::string name );
};

	Zombie* zombieHorde( int N, std::string name );

#endif