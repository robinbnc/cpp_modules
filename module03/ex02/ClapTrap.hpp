/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:37:14 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 11:42:20 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
 
class ClapTrap
{
	protected:
		std::string	m_name;
		int			m_attack_damage;
		int			m_hit_points;
		int			m_energy_points;

	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap &copy );
		ClapTrap &operator=( ClapTrap& a );
		~ClapTrap();

		virtual void 	attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		void 			print( void );
};

#endif