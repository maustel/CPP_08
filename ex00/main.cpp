/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:13:10 by maustel           #+#    #+#             */
/*   Updated: 2025/07/30 13:11:13 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
The auto keyword lets the compiler deduce the correct iterator type based on the
container being used.

Use arrays when size is fixed and known at compile time
Use vectors when you need dynamic sizing and random access
Use lists when frequent insertion/removal in middle positions is necessary

Vectors are generally the default choice unless you have a specific reason
to use something else, as they combine many advantages of arrays with the
flexibility of dynamic sizing.
*/

int main()
{
	std::vector<int> vec = {2, 4, 6, 8, 42, 2, 4, 6, 8, 42};
	std::list<int> lst = {2, 4, 6, 8, 42, 2, 4, 6, 8, 42};
	std::array<int, 10> arr = {2, 4, 6, 8, 42, 2, 4, 6, 8, 42};

	//-------------[VECTOR TEST]------------------------
	std::cout << MAG << "-------- [vector test:] -------- \n" << RESET;
	try
	{
		auto iterator = easyfind(vec, 4);
		std::size_t position = std::distance(vec.begin(), iterator);
		std::cout << "Value " << *iterator << " found in vec at position: " << position
					<< ", value address: " << &(*iterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << " vec" << RESET << '\n';
	}

	//-------------[LIST TEST]------------------------
	std::cout << MAG << "\n-------- [list test:] -------- \n" << RESET;
	try
	{
		auto iterator = easyfind(lst, 8);
		std::size_t position = std::distance(lst.begin(), iterator);
		std::cout << "Value " << *iterator << " found in vec at position: " << position
					<< ", value address: " << &(*iterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << " lst" << RESET << '\n';
	}

	//-------------[ARRAY TEST]------------------------
	std::cout << MAG << "\n-------- [array test:] -------- \n" << RESET;
	try
	{
		auto iterator = easyfind(arr, 42);
		std::size_t position = std::distance(arr.begin(), iterator);
		std::cout << "Value " << *iterator << " found in vec at position: " << position
					<< ", value address: " << &(*iterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << " arr" << RESET << '\n';
	}

	//-------------[EXCEPTION TEST]------------------------
	std::cout << MAG << "\n-------- [exception test:] -------- \n" << RESET;
	try
	{
		auto iterator = easyfind(arr, 1000);
		std::size_t position = std::distance(arr.begin(), iterator);
		std::cout << "Value " << *iterator << " found in vec at position: " << position
					<< ", value address: " << &(*iterator) << std::endl;}
	catch(const std::exception& e)
	{
		std::cerr << RED << "error: " << e.what() << " arr" << RESET << '\n';
	}


	return (0);
}
