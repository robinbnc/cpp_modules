/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:59:20 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/09 12:21:31 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main( void )
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\n" << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n" << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << "\n" << std::endl;
		delete(meta);
		delete(j);
		delete(i);
	}
		std::cout << "\n !---- Wrong Method ----!" << std::endl;
	{
		const WrongAnimal* i = new WrongCat();
		const WrongAnimal* meta = new WrongAnimal();

		std::cout << "\n" << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n" << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete(meta);
		delete(i);
	}
	return (0);
}