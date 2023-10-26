/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 17:23:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << std::endl << "=============MEMORY ADDRESSES=============" << std::endl;
	std::cout << "String variable: " << &string << std::endl;
	std::cout << "StringPTR: " << stringPTR << std::endl;
	std::cout << "StringREF: " << &stringREF << std::endl;
	std::cout << std::endl << "=============VALUES=============" << std::endl;
	std::cout << "String variable: " << string << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl << std::endl;
	return 0;
}