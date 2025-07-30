/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:32:06 by maustel           #+#    #+#             */
/*   Updated: 2025/07/24 11:32:06 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
 {
	//------------- TEST FROM SUBJECT --------------
	std::cout << MAG << "Test from subject with MutantStack: \n" << RESET;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << YEL << "mstack.top() :" << RESET;
	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << YEL << "mstack.size() :" << RESET;
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	//------------- TEST FROM SUBJECT WITH LIST --------------
	std::cout << MAG << "\nTest from subject with list: \n" << RESET;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << YEL << "mlist.back() :" << RESET;
	std::cout << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << YEL << "mlist.size() :" << RESET;
	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::list<int>::iterator i = mlist.begin();
	std::list<int>::iterator iter = mlist.end();
	++i;
	--i;
	while (i != iter)
	{
		std::cout << *i << std::endl;
		++i;
	}


	//------------- TESTS WITH REVERSE ITERATOR --------------
	std::cout << MAG << "\nTests with reverse iterators: \n" << RESET;

	MutantStack<int> rmstack;
	rmstack.push(1);
	rmstack.push(2);
	rmstack.push(3);
	rmstack.push(4);

	std::cout << "mstack in reversed order:" << std::endl;
	for (MutantStack<int>::reverse_iterator j = rmstack.rbegin(); j != rmstack.rend(); ++j)
		std::cout << *j << " ";
	std::cout << std::endl;
	return 0;
}
