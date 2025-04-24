/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:24:59 by maustel           #+#    #+#             */
/*   Updated: 2025/04/24 12:18:23 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*--------------------------------------------------------------------*/
/*----------------------------- CANONICAL FORM -----------------------*/
/*--------------------------------------------------------------------*/

/*-----------------------------------------------------------
 _vector()  // Initialize empty list
------------------------------------------------------------*/
Span::Span(): _N(0)
{}

/*-------------------------------------------------------
initializes empty list
_vector.reserve(N):
Allocates memory for N elements upfront
Sets the vector's capacity to at least N
Doesn't change the vector's size (size remains 0)
---------------------------------------------------------*/
Span::Span(unsigned int N): _N(N)
{}

/*--------------------------------------------------------------------------------------
one of the key benefits of using STL containers - they handle their own memory management
will be automatically destroyed
----------------------------------------------------------------------------------------*/
Span::~Span()
{}

/*------------------------------------------------------------------------------
_vector(other._vector):
A new vector is created for the new Span object
The vector allocates fresh memory for its array
Each integer is copied from the original vector's array to the new vector's array
Both vectors independently own their arrays
-----------------------------------------------------------------------------*/
Span::Span(const Span &other): _N(other._N), _vector(other._vector)
{}

/*-------------------------------------------------------------------------
The STL container assignment operator performs a deep copy automatically
--------------------------------------------------------------------------*/
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_vector = other._vector;
	}
	return(*this);
}

/*--------------------------------------------------------------------*/
/*----------------------------- MEMBER FUNCTIONS ---------------------*/
/*--------------------------------------------------------------------*/

void Span::addNumber(int element)
{
	if (this->_vector.size() == this->_N)
		throw (VectorFullException());
	else
		this->_vector.push_back(element);
}

int Span::shortestSpan()
{
	return (0);
}

std::vector<int> Span::getVector() const
{
	return (this->_vector);
}

int getRandomNumber()
{
	return (std::rand() % 100 + 1);
}

/*-----------------------------------------------------------------------
After resizing, the vector contains 10 default-initialized elements
This creates a valid range between begin() and end()
std::generate can now safely iterate over this range
-----------------------------------------------------------------------*/
void Span::fillSpan()
{
	_vector.resize(_N);
	std::srand(std::time(nullptr));
	std::generate(_vector.begin(), _vector.end(), getRandomNumber);
}

/*--------------------------------------------------------------------*/
/*------------------------------- EXCEPTIONS -------------------------*/
/*--------------------------------------------------------------------*/
const char *Span::VectorFullException::what() const noexcept
{
	return ("Span exception: Vector is already full!");
}

/*--------------------------------------------------------------------*/
/*------------------------------- OTHERS -----------------------------*/
/*--------------------------------------------------------------------*/

/*------------------------------------------------------------------
const int& element : span.getVector()
const: Ensures the element cannot be modified
int&: Creates a reference to the actual vector element
->can also be int, but then values are copied, which is inefficient
element: The variable that takes on the value of each element
span.getVector(): the range, being iteratoed over
--------------------------------------------------------------------*/
std::ostream &operator<<(std::ostream &os, const Span &span)
{
	os << "Vector content: [ ";
	for (const int& element : span.getVector())
	{
		os << element << " " ;
	}
	os << "]" << std::endl;
	return (os);
}
