/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:14:40 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/13 15:09:08 by cscelfo          ###   ########.fr       */
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
		std::cout << "Stack operation: pushed 0" << std::endl << "------------------" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		MutantStack<int>::reverseIterator rIt = mstack.reverseBegin();
		MutantStack<int>::reverseIterator rItEnd = mstack.reverseEnd();
		std::cout << "Iterating through the stack: " << *it << std::endl;
		++it;
		std::cout << "Moving iterator to the second element: " << *it << std::endl;
		--it;
		std::cout << "Moving back iterator to the first element: " << *it << std::endl << "------------------" << std::endl;
		for (; it != ite; ++it)
			std::cout << *it << std::endl;
		std::cout << "------------------" << std::endl << "Iterating through the stack in reverse: " << *rIt << std::endl << "------------------" << std::endl;
		for (; rIt != rItEnd; ++rIt)
			std::cout << *rIt << std::endl;
		std::cout << "------------------" << std::endl;
	}
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
		std::cout << "list operation: pushed 0" << std::endl << "------------------" << std::endl;
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		std::list<int>::reverse_iterator rIt = list.rbegin();
		std::list<int>::reverse_iterator rItEnd = list.rend();
		std::cout << "Iterating through the list: " << *it << std::endl;
		++it;
		std::cout << "Moving iterator to the second element: " << *it << std::endl;
		--it;
		std::cout << "Moving back iterator to the first element: " << *it << std::endl << "------------------" << std::endl;
		for (; it != ite; ++it)
			std::cout << *it << std::endl;
		std::cout << "------------------" << std::endl << "Iterating through the list in reverse: " << *rIt << std::endl << "------------------" << std::endl;
		for (; rIt != rItEnd; ++rIt)
			std::cout << *rIt << std::endl;		
	}
	return 0;
}
