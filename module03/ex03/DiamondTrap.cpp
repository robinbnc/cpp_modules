/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 17:16:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), m_name(name)
{
	m_energy_points = ScavTrap::m_energy_points_heritage;
	std::cout << "Default DiamondTrap constructor called " << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap &copy ): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
}

void	DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "ClapTrap name = " << ClapTrap::m_name << " | DiamondTrap name = " << m_name  << std::endl;	
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap &a )
{
	m_name = a.m_name;
	m_attack_damage = a.m_attack_damage;
	m_energy_points = a.m_energy_points;
	m_hit_points = a.m_hit_points;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}