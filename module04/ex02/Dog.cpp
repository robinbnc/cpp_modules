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
	m_brain = new Brain();
	m_brain->setBrainIdeas("MANGER");
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog( Dog &copy ):  Animal()
{
	if (this != &copy)
		*this = copy;
}

void	Dog::makeSound( void ) const
{
	std::cout << "WOUAF, WOUAF !" << std::endl;
}

Brain const	*Dog::getBrain() const
{
	return (m_brain);
}

Dog &Dog::operator=( Dog &a )
{
	if (this == &a)
		return (*this);
	m_type = a.m_type;
	m_brain = new Brain(*a.m_brain);
	return (*this);
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << "Destructor Dog called" << std::endl;
}