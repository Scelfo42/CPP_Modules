/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:46:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/20 11:33:13 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	exchange(av[1]);
}