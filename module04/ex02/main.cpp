/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:59:20 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/18 14:37:25 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{
	{
		// Animal			error;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\n" << std::endl;
		delete j;
		delete i;
	}
	std::cout << "\n" << std::endl;
	{
		Animal *tab[4];
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
			tab[i]->makeSound();
		}
		std::cout << "\n" << std::endl;
		for (int i = 0; i < 4; i++)
			delete tab[i];
	}
	std::cout << "\n" << std::endl;
	{
		Dog	origin;
		Dog	copy(origin);
		std::cout << "\n" << std::endl;
		std::cout << origin.getBrain() << std::endl;
		std::cout << copy.getBrain() << std::endl;
		std::cout << "\n" << std::endl;
	}
	return (0);
}