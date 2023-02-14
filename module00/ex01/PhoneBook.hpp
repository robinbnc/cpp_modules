/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:17:50 by rbicanic          #+#    #+#             */
/*   Updated: 2022/04/13 23:40:21 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// #include "Contact.hpp"
#include "header.hpp"

class PhoneBook
{
	private:
		int		m_nb_contact;
		Contact m_contact_list[8];

	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact(Contact new_contact);
		void	print_contacts(void);
		void	printAll_contact(int index);
		int		contact_nbr(void);
};

#endif