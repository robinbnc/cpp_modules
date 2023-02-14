/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:44:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 11:38:25 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap &copy );
		ScavTrap &operator=( ScavTrap& a );
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif