/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 11:32:06 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ): m_name(name), m_attack_damage(0), m_hit_points(10), m_energy_points(10)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap &copy ):  m_name(copy.m_name), m_attack_damage(copy.m_attack_damage), m_hit_points(copy.m_hit_points), m_energy_points(copy.m_energy_points)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
}

void ClapTrap::print( void )
{
	std::cout << "name = " << m_name << " ";
	std::cout << "hit_points = " << m_hit_points << " ";
	std::cout << "attack = " << m_attack_damage << " ";
	std::cout << "energy = " << m_energy_points << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!m_hit_points)
		std::cout << "ClapTrap " << m_name << " not enough hit point!" << std::endl;
	else if (!m_energy_points)
		std::cout << "ClapTrap " << m_name << " not enough energy point!" << std::endl;
	else
	{
		m_energy_points--;
		m_hit_points -= amount;
		std::cout << "ClapTrap " << m_name << " took " << amount << " damages!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!m_hit_points)
		std::cout << "ClapTrap " << m_name << " not enough hit point!" << std::endl;
	else if (!m_energy_points)
		std::cout << "ClapTrap " << m_name << " not enough energy point!" << std::endl;
	else
	{
		m_hit_points += amount;
		m_energy_points--;
		std::cout << "ClapTrap " << m_name << " repared "
			<< amount << " points of energy!" << std::endl;
	}
}

void	ClapTrap::attack( const std::string &target )
{
	if (!m_energy_points)
		std::cout << "ClapTrap " << m_name << " not enough energy point!" << std::endl;
	else if (!m_hit_points)
		std::cout << "ClapTrap " << m_name << " not enough hit point!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << m_name << " attacks " << target
			<< ", causing " << m_attack_damage << " points of damage!" << std::endl;
	}
}

ClapTrap &ClapTrap::operator=( ClapTrap &a )
{
	m_name = a.m_name;
	m_attack_damage = a.m_attack_damage;
	m_energy_points = a.m_energy_points;
	m_hit_points = a.m_hit_points;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called" << std::endl;
}