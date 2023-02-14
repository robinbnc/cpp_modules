/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:10:45 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/09 12:19:43 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal()
{
	m_type = "WrongCat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat &copy ):  WrongAnimal()
{
	*this = copy;
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "MIAOU, MIAOU !" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat &a )
{
	if (this == &a)
		return (*this);
	m_type = a.m_type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called" << std::endl;
}