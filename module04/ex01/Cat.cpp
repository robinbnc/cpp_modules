/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal()
{
	std::cout << "Default Cat constructor called" << std::endl;
	m_type = "Cat";
	m_brain = new Brain();
	m_brain->setBrainIdeas("DORMIR");
}

Cat::Cat( Cat &copy ):  Animal()
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = copy;
}

void	Cat::makeSound( void ) const
{
	std::cout << "MIAOU, MIAOU !" << std::endl;
}

Cat &Cat::operator=( Cat &a )
{
	if (this == &a)
		return (*this);
	m_type = a.m_type;
	m_brain = new Brain(*a.m_brain);
	return (*this);
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << "Destructor Cat called" << std::endl;
}