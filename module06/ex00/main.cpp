/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:54:11 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/22 21:00:17 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "TypeConversion.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return (0);
	}
	try {
		TypeConversion test(av[1]);

		std::cout << test << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}