/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ): m_type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal( Animal &copy ):  m_type(copy.m_type)
{
	std::cout << "Copy Animal constructor called" << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal sound !" << std::endl;
}

std::string	Animal::getType() const
{
	return (m_type);
}

Animal &Animal::operator=( Animal &a )
{
	m_type = a.m_type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}