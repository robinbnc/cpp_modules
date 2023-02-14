/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:27:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/06 14:36:33 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <exception>
#include "Array.hpp"

int	main( void )
{
	//__ INT ___
	{
		std::cout << "___ (INT) TESTS CONSTRUCTOR + INITIALISATION ___" << std::endl;
		Array<int>	test(10);
		Array<int>	test2 = test;

		for (unsigned int i = 0; i < test.size(); i++)
		{
			try {std::cout << test[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << "\n" <<std::endl;
	}
	{
		std::cout << "___ (INT) TESTS ASSIGNATION + COPY ___" << std::endl;
		Array<int>	test(14);
		Array<int>	test2(10);
		Array<int>	test3(test);


		for (unsigned int i = 0; i < test.size(); i++)
		{
			try {test[i] = 30;}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << std::endl;
		test2 = test;
		for (unsigned int i = 0; i < test2.size(); i++)
		{
			try {std::cout << test2[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << std::endl;
		for (unsigned int i = 0; i < test3.size(); i++)
		{
			try {std::cout << test3[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "___ (INT) EXCEPTION INACCESSBLE INDEX ___" << std::endl;
		Array<int>	test(10);

		try {std::cout << test[9] << std::endl;}
		catch (std::exception & e) {std::cerr << e.what() << std::endl;};
		try {std::cout << test[10];}
		catch (std::exception & e) {std::cerr << e.what() << std::endl;};
		std::cout <<std::endl;
	}
	{
		std::cout << "___ (INT) SIZE METHOD ___" << std::endl;
		Array<int>	test(10);
		Array<int>	test1(14);

		std::cout << "Test size = " << test.size() <<std::endl;
		std::cout << "Test1 size = " << test1.size() <<std::endl;
		
		test = test1;
		std::cout << "Test size = " << test.size() <<std::endl;
		Array<int>	test3(test);
		std::cout << "Test3 size = " << test.size() <<std::endl;
		std::cout << "\n" <<std::endl;
	}

	//__ STRING ___
	{
		std::cout << "___ (STRING) TESTS CONSTRUCTOR + INITIALISATION ___" << std::endl;
		Array<std::string>	test(10);

		for (unsigned int i = 0; i < test.size(); i++)
		{
			test[i] = "test";
			try {std::cout << test[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << "\n" <<std::endl;
	}
	{
		std::cout << "___ (STRING) TESTS ASSIGNATION + COPY ___" << std::endl;
		Array<std::string>	test(14);
		Array<std::string>	test2(10);


		for (unsigned int i = 0; i < test.size(); i++)
		{
			try {test[i] = "30";}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << std::endl;
		test2 = test;
		Array<std::string>	test3(test);
		for (unsigned int i = 0; i < test2.size(); i++)
		{
			try {std::cout << test2[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << std::endl;
		for (unsigned int i = 0; i < test3.size(); i++)
		{
			try {std::cout << test3[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "___ (STRING) EXCEPTION INACCESSBLE INDEX ___" << std::endl;
		Array<std::string>	test(10);

		try {std::cout << test[9] << std::endl;}
		catch (std::exception & e) {std::cerr << e.what() << std::endl;};
		try {std::cout << test[10];}
		catch (std::exception & e) {std::cerr << e.what() << std::endl;};
		std::cout <<std::endl;
	}
	{
		std::cout << "___ (STRING) SIZE METHOD ___" << std::endl;
		Array<std::string>	test(10);
		Array<std::string>	test1(14);

		std::cout << "Test size = " << test.size() <<std::endl;
		std::cout << "Test1 size = " << test1.size() <<std::endl;
		
		test = test1;
		std::cout << "Test size = " << test.size() <<std::endl;
		Array<std::string>	test3(test);
		std::cout << "Test3 size = " << test.size() <<std::endl;
		std::cout << "\n" <<std::endl;
	}

	//__ FLOAT ___
	{
		std::cout << "___ (FLOAT) TESTS CONSTRUCTOR + INITIALISATION ___" << std::endl;
		Array<float>	test(10);

		for (unsigned int i = 0; i < test.size(); i++)
		{
			try {std::cout << test[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << "\n" <<std::endl;
	}
	{
		std::cout << "___ (FLOAT) TESTS ASSIGNATION + COPY ___" << std::endl;
		Array<float>	test(14);
		Array<float>	test2(10);
		Array<float>	test3(test);


		for (unsigned int i = 0; i < test.size(); i++)
		{
			try {test[i] = 30.2;}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << std::endl;
		test2 = test;
		for (unsigned int i = 0; i < test2.size(); i++)
		{
			try {std::cout << test2[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << std::endl;
		for (unsigned int i = 0; i < test3.size(); i++)
		{
			try {std::cout << test3[i] << (i != test.size() - 1 ? " , " : "");}
			catch (std::exception & e) {std::cerr << e.what() << std::endl;};	
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "___ (FLOAT) EXCEPTION INACCESSBLE INDEX ___" << std::endl;
		Array<float>	test(10);

		try {std::cout << test[9] << std::endl;}
		catch (std::exception & e) {std::cerr << e.what() << std::endl;};
		try {std::cout << test[10];}
		catch (std::exception & e) {std::cerr << e.what() << std::endl;};
		std::cout <<std::endl;
	}
	{
		std::cout << "___ (FLOAT) SIZE METHOD ___" << std::endl;
		Array<float>	test(10);
		Array<float>	test1(14);

		std::cout << "Test size = " << test.size() <<std::endl;
		std::cout << "Test1 size = " << test1.size() <<std::endl;
		
		test = test1;
		std::cout << "Test size = " << test.size() <<std::endl;
		Array<float>	test3(test);
		std::cout << "Test3 size = " << test.size() <<std::endl;
	}
	return (0);
}
