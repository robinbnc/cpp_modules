/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:37:14 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/17 18:10:37 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
 
class WrongAnimal
{
	protected:
		std::string	m_type;

	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal &copy );
		WrongAnimal	&operator=( WrongAnimal& a );
		virtual ~WrongAnimal();

		void		makeSound() const;
		std::string	getType() const;
};

#endif