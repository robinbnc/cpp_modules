/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	for (int i = 0; i < 100; i++)
		m_ideas[i] = "Brain Idea.";
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain( Brain &copy )
{
	*this = copy;
	std::cout << "Copy Brain constructor called" << std::endl;
}

void	Brain::setBrainIdeas( std::string idea)
{
	for (int i = 0; i < 100; i++)
		m_ideas[i] = idea;
}

Brain &Brain::operator=( Brain &a )
{
	if (this == &a)
		return (*this);
	for (int i = 0; i < 100; i++)
		m_ideas[i] = a.m_ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}