/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:58 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 10:57:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

int	main( void )
{
	Base *base1 = generate();
	sleep(1);
	Base *base2 = generate();
	sleep(1);
	Base *base3 = generate();

	std::cout << "-----------Identifying base1:-----------\n";
	std::cout << "By pointer: ";
	identify(base1);
	std::cout << "By reference: ";
	identify(*base1);
	std::cout << "-----------Identifying base2:-----------\n";
	std::cout << "By pointer: ";
	identify(base2);
	std::cout << "By reference: ";
	identify(*base2);
	std::cout << "-----------Identifying base3:-----------\n";
	std::cout << "By pointer: ";
	identify(base3);
	std::cout << "By reference: ";
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;

	return 0;
}