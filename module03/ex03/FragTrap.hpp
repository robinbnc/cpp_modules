/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:44:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 17:05:30 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap &copy );
		FragTrap &operator=( FragTrap& a );
		~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys();
};

#endif