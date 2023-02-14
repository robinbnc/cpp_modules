/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:54:11 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/25 18:13:19 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include "easyfind.hpp"

int	main( void )
{
	std::ostream_iterator<std::string> out_iterator(std::cout);

	{
		*out_iterator = "\n___EASY FIND ON VECTORS___\n";
		std::vector<int> test_vector(6, 4);

		(::easyfind(test_vector, 4) != test_vector.end())
			? *out_iterator = "La valeur '4' est présente dans le container\n"
			: *out_iterator = "La valeur '4' n'est pas présente dans le container\n";
		(::easyfind(test_vector, 10) != test_vector.end())
			? *out_iterator = "La valeur '10' est présente dans le container\n"
			: *out_iterator = "La valeur '10' n'est pas présente dans le container\n";
	}
	{
		*out_iterator = "\n___EASY FIND ON LISTS___\n";
		std::list<int> test_list(6, 4);

		(::easyfind(test_list, 4) != test_list.end())
			? *out_iterator = "La valeur '4' est présente dans le container\n"
			: *out_iterator = "La valeur '4' n'est pas présente dans le container\n";
		(::easyfind(test_list, 10) != test_list.end())
			? *out_iterator = "La valeur '10' est présente dans le container\n"
			: *out_iterator = "La valeur '10' n'est pas présente dans le container\n";
	}
	{
		*out_iterator = "\n___EASY FIND ON DEQUE___\n";
		std::deque<int> test_deque(6, 4);

		(::easyfind(test_deque, 4) != test_deque.end())
			? *out_iterator = "La valeur '4' est présente dans le container\n"
			: *out_iterator = "La valeur '4' n'est pas présente dans le container\n";
		(::easyfind(test_deque, 10) != test_deque.end())
			? *out_iterator = "La valeur '10' est présente dans le container\n"
			: *out_iterator = "La valeur '10' n'est pas présente dans le container\n";
	}
	{
		*out_iterator = "\n___EASY FIND ON MAP___\n";
		std::deque<int> test_deque(6, 4);

		(::easyfind(test_deque, 4) != test_deque.end())
			? *out_iterator = "La valeur '4' est présente dans le container\n"
			: *out_iterator = "La valeur '4' n'est pas présente dans le container\n";
		(::easyfind(test_deque, 10) != test_deque.end())
			? *out_iterator = "La valeur '10' est présente dans le container\n"
			: *out_iterator = "La valeur '10' n'est pas présente dans le container\n";
	}
	return (0);
}
