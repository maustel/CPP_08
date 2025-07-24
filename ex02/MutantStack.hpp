/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:01:43 by maustel           #+#    #+#             */
/*   Updated: 2025/07/23 17:01:43 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <iostream>
#include <stack>
#include <iterator>

# include "colors.h"

/*-------------------------------------------------------------------------
I am using constructor = default because this class does not manage resources directly
So the compiler can generate highly optimized versions that are potentially
better than hand-written ones.

The c member is inherited from std::stack and provides direct access to the
container's iterator methods.

typedef typename std::stack<T>::container_type::iterator iterator;
creates iterator for this container
I do typedef because the example in the subject uses MutantStack::iterator
Container_type is a protected member of std::stack, therefore accessible
when creating a derived from it.
--------------------------------------------------------------------------*/

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
	MutantStack() = default;
	~MutantStack() = default;
	MutantStack( const MutantStack& other ) = default;
	MutantStack&	operator=( const MutantStack& other ) = default;

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void){return (this->c.begin());};
	iterator end(void){return (this->c.end());};
};

#endif
