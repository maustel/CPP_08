/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:15:33 by maustel           #+#    #+#             */
/*   Updated: 2025/07/23 16:19:24 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <vector>
# include <stdexcept>
# include <random>
# include <algorithm>
# include <iterator>
# include <ctime>
# include <chrono>

# include "colors.h"

class Span
{
	private:
	unsigned int _N;
	std::vector<int> _vector;

	public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

	void addNumber(int element);
	int shortestSpan(void);
	int longestSpan(void);

	void fillSpan();

	std::vector<int> getVector(void) const;
};

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif
