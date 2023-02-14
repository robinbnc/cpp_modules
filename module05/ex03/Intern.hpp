/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:37:14 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/16 11:23:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern( void );
		Intern( Intern &copy );
		Intern	&operator=( Intern& a );
		~Intern();

		int 	get_form_type(std::string form_name) const;
		Form	*makeForm( std::string form_name, std::string target );
};

#endif