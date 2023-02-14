/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:17:28 by rbicanic          #+#    #+#             */
/*   Updated: 2022/04/13 18:37:06 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "header.hpp"
#include <iomanip>

class Contact
{
	private:
		std::string	m_first_name;
		std::string	m_last_name;
		std::string	m_nickname;
		std::string	m_phone_number;
		std::string	m_darkest_secret;

	public:
	Contact();
	~Contact();

	void	update_values(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number, std::string darkest_secret);
	void	print(void);
	void	printAll(void);
	
};

#endif