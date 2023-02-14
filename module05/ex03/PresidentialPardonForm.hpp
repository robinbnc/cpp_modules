/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:03:08 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/19 13:16:20 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	private:
		const std::string	m_target;

	public:
		PresidentialPardonForm( const std::string name, const std::string target );
		PresidentialPardonForm( PresidentialPardonForm &copy );
		PresidentialPardonForm	&operator=( PresidentialPardonForm& a );
		virtual ~PresidentialPardonForm();

		void		execute(Bureaucrat const &executor) const;
};

#endif