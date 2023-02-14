/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:44:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 17:02:19 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	m_name;

	public:
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap &copy );
		DiamondTrap &operator=( DiamondTrap& a );
		~DiamondTrap();

		void	attack(const std::string& target);
		void	whoAmI();
};

#endif