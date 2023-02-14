/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/05 21:23:33 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
	this->m_attack_damage = 20;
	this->m_hit_points = 100;
	this->m_energy_points = 50;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap &copy ): ClapTrap(copy)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
}

void	ScavTrap::attack( const std::string &target )
{
	if (!m_energy_points)
		std::cout << "ScavTrap " << m_name << " not enough energy point!" << std::endl;
	else if (!m_hit_points)
		std::cout << "ScavTrap " << m_name << " not enough hit point!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << m_name << " attacks " << target
			<< ", causing " << m_attack_damage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
		std::cout << "ScavTrap " << m_name << " is guarding gate !" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap &a )
{
	m_name = a.m_name;
	m_attack_damage = a.m_attack_damage;
	m_energy_points = a.m_energy_points;
	m_hit_points = a.m_hit_points;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}