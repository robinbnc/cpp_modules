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
	m_type = "Cat";
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( Cat &copy ):  Animal()
{
	*this = copy;
	std::cout << "Copy Cat constructor called" << std::endl;
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
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called" << std::endl;
}