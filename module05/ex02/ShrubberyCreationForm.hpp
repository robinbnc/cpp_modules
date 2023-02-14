/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:03:08 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/19 13:16:20 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	private:
		const std::string	m_target;

	public:
		ShrubberyCreationForm( const std::string name, const std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm &copy );
		ShrubberyCreationForm	&operator=( ShrubberyCreationForm& a );
		virtual ~ShrubberyCreationForm();

		void		execute(Bureaucrat const &executor) const;
};

#endif