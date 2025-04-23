/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:13:10 by maustel           #+#    #+#             */
/*   Updated: 2025/04/23 15:10:11 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
The auto keyword lets the compiler deduce the correct iterator type based on the container being used.
*/


int main()
{
	std::vector<int> vec = {2, 4, 6, 8, 42};
	std::list<int> lst = {2, 4, 6, 8, 42};
	std::array<int, 5> arr = {2, 4, 6, 8, 42};

	//-------------[VECTOR TEST]------------------------
	try
	{
		auto iterator = easyfind(vec, 4);
		std::cout << "Value found in vec at position: " << *iterator << " with address: " << &(*iterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " vec" << '\n';
	}

	//-------------[LIST TEST]------------------------
	try
	{
		auto iterator = easyfind(lst, 8);
		std::cout << "Value found in lst at position: " << *iterator << " with address: " << &(*iterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " lst" << '\n';
	}

	//-------------[ARRAY TEST]------------------------
	try
	{
		auto iterator = easyfind(arr, 42);
		std::cout << "Value found in arr at position: " << *iterator << " with address: " << &(*iterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " arr" << '\n';
	}

	return (0);
}