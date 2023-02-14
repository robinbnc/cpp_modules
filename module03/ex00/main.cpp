/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:59:20 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:45:42 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	clap("Bernard");
	ClapTrap	copy(clap);
	ClapTrap	assigned = copy;

	std::cout << "\n" << std::endl;
	clap.print();
	copy.print();
	assigned.print();

	std::cout << "\n" << std::endl;
	for (int i = 0; i < 11; i++)
		clap.beRepaired(1);
	std::cout << "\n" << std::endl;
	for (int i = 0; i < 11; i++)
		copy.takeDamage(1);
	std::cout << "\n" << std::endl;
	clap.attack("Bernard");
	assigned.attack("Bernard");
	std::cout << "\n" << std::endl;
	return (0);
}