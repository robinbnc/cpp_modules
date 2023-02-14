/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:27:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/08 19:46:07 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int	main( void )
{
	int					i = 0;
	MutantStack<int>	test;

	test.push(1);
	test.push(5);
	test.push(4);
	test.push(2);

	std::cout << "stack size = " << test.size() << std::endl;
	for (MutantStack<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "\telement index [" << i++ << "] accessed by iterator = " << *it << std::endl;
	(test.empty())
		? std::cout << "Mutant stack is empty." << std::endl
		: std::cout << "Mutant stack is not empty." << std::endl;
	
	MutantStack<int>	test2 = test;
	for (MutantStack<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "\telement index [" << i++ << "] accessed by iterator = " << *it << std::endl;
	test.pop();
	test.pop();
	test.pop();
	test.pop();
	std::cout << "stack size = " << test.size() << std::endl;
	(test.empty())
		? std::cout << "Mutant stack is empty." << std::endl
		: std::cout << "Mutant stack is not empty." << std::endl;
	return (0);
}
