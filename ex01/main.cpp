/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:14:12 by maustel           #+#    #+#             */
/*   Updated: 2025/07/23 16:54:57 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main ()
{
	//-------------[GENERAL TEST]------------------------
	try
	{
		std::cout << MAG << "-------- [General tests:] -------- \n" << RESET;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << MAG << "\n -------- [Exception test:] --------\n" << RESET;
		sp.addNumber(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	//-------------[BIG SPAN TEST]------------------------
	try
	{
		std::cout << MAG << "\n -------- [Big span tests:] -------- \n" << RESET;
		Span sp = Span(10000);
		sp.fillSpan();
		// std::cout << sp;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << MAG << "\n -------- [Exception test:] -------- \n" << RESET;
		sp.addNumber(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	//-------------[EXCEPTION TEST]------------------------
	std::cout << MAG << "\n -------- [More exception tests:] -------- \n" << RESET;
	try
	{
		Span sp = Span(10);
		sp.addNumber(6);
		std::cout << sp;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	try
	{
		Span sp = Span(10);
		sp.addNumber(6);
		std::cout << sp;
		std::cout << "Longest span: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	
	return (0);
}
