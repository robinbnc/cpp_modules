/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:30:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/11 12:44:03 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	print_error_input(std::string char_type)
{
	std::cout << "Erreur: votre reponse doit etre composee de characteres "
		+ char_type << std::endl;
}

std::string	strtrim(std::string *str, char c)
{
	while ((*str)[0] == c)
		str->erase(0, 1);
	while ((*str)[str->length() - 1] == c)
		str->erase(str->length() - 1, 1);
	return (*str);
}

int	check_index_format(std::string index, PhoneBook *repertoire)
{
	for (size_t i = 0; i < index.length(); i++)
	{
		if (!isdigit(index[i]))
			return (1);
	}
	if (repertoire->contact_nbr() <= atoi(index.c_str()))
		return (1);
	return (0);
}

int	is_valid_number(std::string *phone_num)
{

	if (phone_num->length() != 10)
		return (1);
	for (size_t i = 0; i < phone_num->length(); i++)
	{
		if ((*phone_num)[i] == ' ')
			phone_num->erase(i, 1);
		if (!isdigit((*phone_num)[i]))
			return (1);
	}
	return (0);
}

int	check_input(std::string answer, int index)
{
	if (answer.empty())
		return (print_error_input("et ne doit pas etre vide"), 1);
	for (size_t i = 0; i < answer.length(); i++)
	{
		if ((index == 0 || index == 1 || index == 2) && (!isalpha(answer[i]) && answer[i] != ' '))
			return (print_error_input("alphabetiques"), 1);
		else if (index == 3 && is_valid_number(&answer))
			return (print_error_input("numeriques et au nombre de 10"), 1);
	}
	return (0);
}

void	contact_questions(PhoneBook *repertoire)
{
	Contact		new_contact;
	std::string	answers[5];
	std::string	questions[5] = {
		"Quel est ton prénom ?", "Quel est ton nom ?", "Quel est ton surnom ?",
		"Quel est ton numéro de téléphone ?", "Quel est ton plus lourd secret ?"};
	
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << questions[i] << std::endl;
			std::getline(std::cin, answers[i]);
			if(!std::cin)
				exit(0);
			strtrim(&answers[i], ' ');
			if (!check_input(answers[i], i))
				break ;
		}
	}
	new_contact.update_values(answers[0], answers[1], answers[2], answers[3], answers[4]);
	repertoire->add_contact(new_contact);
}

void	search_contact(PhoneBook *repertoire)
{
	std::string	index;

	repertoire->print_contacts();
	if (repertoire->contact_nbr())
	{
		while (1)
		{
			std::cout << "choisir l'index du contact a afficher :\n" << std::endl;
			std::getline(std::cin, index);
			if(!std::cin)
				exit(0);
			if (!check_index_format(index, repertoire))
				break ;
			else
				std::cout << "Entrez un index valide et inferieur a " << repertoire->contact_nbr() << std::endl;
		}
		repertoire->printAll_contact(atoi(index.c_str()));
	}
}

int	main()
{
	PhoneBook	repertoire;
	std::string	commandes;

	while (1)
	{
		std::cout << "Entrer l'une des commandes suivantes {ADD, SEARCH, EXIT}" << std::endl;
		std::getline(std::cin, commandes);
		if(!std::cin)
			exit(0);
		if (commandes == "EXIT")
			return (0);
		else if (commandes == "ADD")
			contact_questions(&repertoire);
		else if (commandes == "SEARCH")
			search_contact(&repertoire);
		else
			std::cout << "Entree invalide, veuilez entrer l'une des commandes suivantes {ADD, SEARCH, EXIT}" << std::endl;
	}
}