/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:24:59 by maustel           #+#    #+#             */
/*   Updated: 2025/04/23 16:14:02 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
 _vector()  // Initialize empty list
*/
Span::Span(): _N(0), _vector()
{}

/*
initializes empty list
*/
Span::Span(unsigned int N): _N(N), _vector()
{}

/*
one of the key benefits of using STL containers - they handle their own memory management
will be automatically destroyed
*/
Span::~Span()
{}

/*
_vector(other._vector):
A new vector is created for the new Span object
The vector allocates fresh memory for its array
Each integer is copied from the original vector's array to the new vector's array
Both vectors independently own their arrays*/
Span::Span(const Span &other): _N(other._N), _vector(other._vector)
{}

/*
The STL container assignment operator performs a deep copy automatically
*/
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_vector = other._vector;
	}
	return(*this);
}

void Span::addNumber(int element)
{
	if (this->_vector.size() == this->_N)
		throw std::runtime_error("Vector is already full!");
	else
		this->_vector.push_back(element);
}
