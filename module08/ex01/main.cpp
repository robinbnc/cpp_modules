/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:54:11 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/25 22:34:37 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iterator>
#include <exception>
#include <stdio.h>
#include "Span.hpp"

int	main( void )
{
	std::ostream_iterator<std::string>	out_iterator(std::cout);

	{
		*out_iterator = "\n___ASKED TESTS___\n";
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	}
	{
		*out_iterator = "\n___MY TESTS SMALL SPAN___\n";
		Span								test(10);

		for (int i = 0; i < 10; i++)
		{
			try {test.addNumber(i);}
			catch (std::exception & e) {*out_iterator = e.what();};
		}
		std::cout << test << std::endl;
		try {test.addNumber(20);}
		catch (std::exception & e) {*out_iterator = e.what();};
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test << std::endl;
	}
	{
		*out_iterator = "\n___MY TESTS BIG SPAN___\n";
		Span								test(20000);

		for (int i = 0; i < 20000; i++)
		{
			try {test.addNumber(i * 2);}
			catch (std::exception & e) {*out_iterator = e.what();};
		}
		try {test.addNumber(20);}
		catch (std::exception & e) {*out_iterator = e.what();};
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	}
	{
		*out_iterator = "\n___MY TESTS RANGE___\n";
		Span 					sp(6);
		std::vector<int>	test2(6, 14);

		try {sp.addRangeNumber(test2.begin(), test2.end());}
		catch (std::exception & e) {*out_iterator = e.what();}
		std::cout << sp << std::endl;
	}
	{
		*out_iterator = "\n___MY TESTS RANGE ERROR___\n";
		Span 					sp(5);
		std::vector<unsigned int>	test2(6, 2147483649);

		try {sp.addRangeNumber(test2.begin(), test2.end());}
		catch (std::exception & e) {*out_iterator = e.what();}
		std::cout << sp << std::endl;
	}

	return (0);
}
