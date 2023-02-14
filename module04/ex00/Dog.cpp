/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal()
{
	m_type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog( Dog &copy ):  Animal()
{
	*this = copy;
	std::cout << "Copy Dog constructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "WOUAF, WOUAF !" << std::endl;
}

Dog &Dog::operator=( Dog &a )
{
	if (this == &a)
		return (*this);
	m_type = a.m_type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
}