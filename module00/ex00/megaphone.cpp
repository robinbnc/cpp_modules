/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:13:04 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/14 14:48:28 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	ft_to_upper(std::string *str)
{
	for (size_t i = 0; i < (*str).length(); i++)
		(*str)[i] = std::toupper((*str)[i]);
}

int	main(int argc, char *argv[])
{
	std::string	str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		ft_to_upper(&str);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
