/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 15:01:38 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
	this->m_attack_damage = 30;
	this->m_hit_points = 100;
	this->m_energy_points = 100;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap &copy ): ClapTrap(copy)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
}

void	FragTrap::attack( const std::string &target )
{
	if (!m_energy_points)
		std::cout << "FragTrap " << m_name << " not enough energy point!" << std::endl;
	else if (!m_hit_points)
		std::cout << "FragTrap " << m_name << " not enough hit point!" << std::endl;
	else
	{
		std::cout << "FragTrap " << m_name << " attacks " << target
			<< ", causing " << m_attack_damage << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys( void )
{
		std::cout << "FragTrap " << m_name << " is giving a high Five !" << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap &a )
{
	m_name = a.m_name;
	m_attack_damage = a.m_attack_damage;
	m_energy_points = a.m_energy_points;
	m_hit_points = a.m_hit_points;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}