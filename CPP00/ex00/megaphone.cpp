/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:59:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/11 15:15:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( int argc, char *argv[] )
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j] != '\0'; j++)
			std::cout << (char)std::toupper( argv[i][j] );
	std::cout << std::endl;
	return 0;
}
