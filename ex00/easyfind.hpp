/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:13:13 by maustel           #+#    #+#             */
/*   Updated: 2025/04/23 15:18:18 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <algorithm>  // For std::find
#include <iterator>   // For iterator utilities
#include <stdexcept>  // For exception handling
#include <vector>
#include <list>
#include <array>
#include <iostream>

/*
std::find(first, last, value)
first: An iterator pointing to the start of the search range (container.begin())
last: An iterator pointing to one position past the end of the search range (container.end())
value: The element to search for

Iterators are designed to abstract away the complexities of different container implementations
while providing pointer-like functionality. They're not necessarily pointers themselves, but
rather objects that implement pointer-like behavior specifically for traversing containers
safely and efficiently.
*/
template <typename T>
typename T::iterator easyfind(T& container, int val)
{
	typename T::iterator i = std::find(container.begin(), container.end(), val);
	if (i == container.end())
	{
		throw std::runtime_error("Value not found in container");
	}
	return (i);
}

#endif