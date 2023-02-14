/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:03:08 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/19 13:16:20 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		const std::string	m_target;

	public:
		RobotomyRequestForm( const std::string name, const std::string target );
		RobotomyRequestForm( RobotomyRequestForm &copy );
		RobotomyRequestForm	&operator=( RobotomyRequestForm& a );
		virtual ~RobotomyRequestForm();

		void		execute(Bureaucrat const &executor) const;
};

#endif