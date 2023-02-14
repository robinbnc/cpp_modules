/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:27:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/23 15:10:21 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>
#include "Data.hpp"


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>( ptr )); 
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>( raw )); 
}

int	main( void )
{
	Data		data_test [5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++)
	{
		std::cout << &data_test[i] << std::endl;
		uintptr_t	ptr = serialize(&data_test[i]);
		std::cout << reinterpret_cast<void*>(ptr) << std::endl;
		Data		*data_ptr = deserialize(ptr);
		std::cout << data_ptr << std::endl;
		std::string	is_same_address = (reinterpret_cast<void*>(ptr) == &data_test[i] && data_ptr == &data_test[i])
									? "The addresses are the same"
									: "The addresses are different";
		std::cout << is_same_address << std::endl;
		std::cout << "\n" << std::endl;
	}
	return (0);
}