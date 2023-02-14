/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:22:04 by rbicanic          #+#    #+#             */
/*   Updated: 2022/04/13 18:36:51 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Contact::Contact()
{
	m_first_name = "";
	m_last_name = "";
	m_nickname = "";
	m_phone_number = "";
	m_darkest_secret = "";
}

void	Contact::update_values(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	m_first_name = first_name;
	m_last_name = last_name;
	m_nickname = nickname;
	m_phone_number = phone_number;
	m_darkest_secret = darkest_secret;
}

void	Contact::print(void)
{
	std::cout << "|"<< std::setw(10);
	if (m_first_name.length() <= 10)
		std::cout << m_first_name << "|" << std::setw(10);
	else
		std::cout << m_first_name.substr(0, 9) + "." << "|" << std::setw(10);
	if (m_last_name.length() <= 10)
		std::cout << m_last_name << "|" << std::setw(10);
	else
		std::cout << m_last_name.substr(0, 9) + "." << "|" << std::setw(10);
	if (m_nickname.length() <= 10)
		std::cout << m_nickname << "|" << std::endl;
	else
		std::cout << m_nickname.substr(0, 9) + "." << "|" << std::endl;
}

void	Contact::printAll(void)
{
	std::cout << "First name: " << m_first_name << std::endl;
	std::cout << "Last name: " << m_last_name << std::endl;
	std::cout << "Nickname: " << m_nickname << std::endl;
	std::cout << "Phone Number: " << m_phone_number << std::endl;
	std::cout << "Darkest secret: " << m_darkest_secret << std::endl;
}


Contact::~Contact()
{
}