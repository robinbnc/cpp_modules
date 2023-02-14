/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:59:20 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 17:26:15 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// voir operateur assignation claptrap = scave trap ; Possible ?
int	main( void )
{
	DiamondTrap	diamond("Bernard");
	DiamondTrap	copy(diamond);
	DiamondTrap	assign = copy; 
	ClapTrap	*dmd_ptr = &diamond;


	std::cout << "\n" << std::endl;
	diamond.print();
	copy.print();
	dmd_ptr->print();
	assign.print();
	std::cout << "\n!-------- DiamondTrap Loop Constructor/destrucor order --------!" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "\n" << std::endl;
		DiamondTrap	loop("loop");
		loop.print();
	}

	std::cout << "\n!-------- ClapTrap Functions working on DiamondTrap --------!" << std::endl;
	std::cout << "\n" << std::endl;
	diamond.beRepaired(1);

	std::cout << "\n" << std::endl;
	diamond.takeDamage(1);

	std::cout << "\n!-------- Scavtrap && FragTrap Functions working on DiamondTrap --------!" << std::endl;
	std::cout << "\n" << std::endl;
	diamond.guardGate();

	std::cout << "\n" << std::endl;
	diamond.highFivesGuys();

	std::cout << "\n!-------- DiamondTrap own attack Functions like ScavTrap / pointer attack Working Too --------!" << std::endl;
	std::cout << "\n" << std::endl;
	diamond.attack("Bernard");
	dmd_ptr->attack("Tapi");

	std::cout << "\n!-------- DiamondTrap whoAmI Functions  --------!" << std::endl;
	std::cout << "\n" << std::endl;
	diamond.whoAmI();
	std::cout << "\n" << std::endl;
	return (0);
}
