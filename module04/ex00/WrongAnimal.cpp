/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): m_type("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal &copy ):  m_type(copy.m_type)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound !" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (m_type);
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal &a )
{
	if (this == &a)
		return (*this);
	m_type = a.m_type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}