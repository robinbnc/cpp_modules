/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:19:29 by rbicanic          #+#    #+#             */
/*   Updated: 2022/04/14 00:01:02 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
// #include "Contact.hpp"

PhoneBook::PhoneBook()
{
	m_nb_contact = 0;
}

void	PhoneBook::add_contact(Contact new_contact)
{
	static int	contact_index = 0;

	if (contact_index == 8)
		contact_index = 0;
	m_contact_list[contact_index] = new_contact;
	contact_index++;
	if (m_nb_contact < 8)
		m_nb_contact++;
}

void	PhoneBook::print_contacts(void)
{
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < m_nb_contact; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		m_contact_list[i].print();
	}
}

void	PhoneBook::printAll_contact(int index)
{
	m_contact_list[index].printAll();
}

int	PhoneBook::contact_nbr(void)
{
	return (m_nb_contact);
}

PhoneBook::~PhoneBook()
{
}