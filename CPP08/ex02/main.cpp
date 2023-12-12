/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:14:40 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/12 15:35:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main( void )
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		std::cout << "Stack operation: pushed 5" << std::endl;
		mstack.push(17);
		std::cout << "Stack operation: pushed 17" << std::endl;
		std::cout << "top of the stack: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Stack operation: popped" << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		std::cout << "Stack operation: pushed 3" << std::endl;
		mstack.push(5);
		std::cout << "Stack operation: pushed 5" << std::endl;
		mstack.push(737);
		std::cout << "Stack operation: pushed 737" << std::endl;
		mstack.push(0);
		std::cout << "Stack operation: pushed 0" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "Iterating through the stack: " << *it << std::endl;
		++it;
		std::cout << "Moving iterator to the second element: " << *it << std::endl;
		--it;
		std::cout << "Moving back iterator to the first element: " << *it << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::list<int> list;

		list.push_back(5);
		std::cout << "list operation: pushed 5" << std::endl;
		list.push_front(17);
		std::cout << "list operation: pushed 17" << std::endl;
		std::cout << "top of the list: " << *list.begin() << std::endl;
		list.pop_front();
		std::cout << "list operation: popped" << std::endl;
		std::cout << "list size: " << list.size() << std::endl;
		list.push_back(3);
		std::cout << "list operation: pushed 3" << std::endl;
		list.push_back(5);
		std::cout << "list operation: pushed 5" << std::endl;
		list.push_back(737);
		std::cout << "list operation: pushed 737" << std::endl;
		list.push_back(0);
		std::cout << "list operation: pushed 0" << std::endl;
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		std::cout << "Iterating through the list: " << *it << std::endl;
		++it;
		std::cout << "Moving iterator to the second element: " << *it << std::endl;
		--it;
		std::cout << "Moving back iterator to the first element: " << *it << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
