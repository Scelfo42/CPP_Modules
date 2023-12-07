/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:40:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/07 14:50:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main( void )
{
	std::vector<int>::iterator	results_vector[2];
	std::deque<int>::iterator	results_deque[2];
	std::list<int>::iterator	results_list[2];
	std::vector<int>	vector;
	std::deque<int>		deque;
	std::list<int>		list;

	for (int i = 0; i < 5; i++)
	{
		vector.push_back(i);
		deque.push_back(i);
		list.push_back(i);
	}

	try
	{
		results_vector[0] = easyfind(vector, 3);
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try
	{
		results_deque[0] = easyfind(deque, 3);
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try
	{
		results_list[0] = easyfind(list, 3);
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try
	{
		std::cout << "vector results: '" << *results_vector[0] << "' | '";
		results_vector[1] = easyfind(vector, 42);
	}
	catch(const std::exception& e) { std::cerr << e.what() << "'\n"; }
	try
	{
		std::cout << "deque results: '" << *results_deque[0] << "' | '";
		results_deque[1] = easyfind(deque, 42);
	}
	catch(const std::exception& e) { std::cerr << e.what() << "'\n"; }
	try
	{
		std::cout << "list results: '" << *results_list[0] << "' | '";
		results_list[1] = easyfind(list, 42);
	}
	catch(const std::exception& e) { std::cerr << e.what() << "'\n"; }
	
	return 0;
}
