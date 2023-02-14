/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:37:14 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/07 19:26:06 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"
 
class Dog: public Animal
{
	private:
		Brain		*m_brain;

	public:
		Dog();
		Dog( Dog &copy );
		Dog	&operator=( Dog& a );
		virtual ~Dog();

		void 	makeSound() const;
		Brain const	*getBrain() const;
};

#endif