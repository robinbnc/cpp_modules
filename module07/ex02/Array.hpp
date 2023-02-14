/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:34:52 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/24 16:32:42 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstring>
# include <exception>

template <typename T> 
class Array 
{
	private:
		T				*m_array;
		unsigned int	m_size;

	public:
		//__ CONSTRUCTOR __
		Array( void ): m_size(0)
		{
			m_array = new T[0];	
		}
		
		Array( unsigned int size )
		{
			m_size = size;
			m_array = new T[size];
			std::memset(m_array, 0, m_size * sizeof(T));
		}

		Array( Array &copy )
		{
			if (this != &copy)
			{
				m_array = NULL;
				*this = copy;
			}
		}

		//__ OPERATOR __
		Array &operator=( Array &a )
		{
			if (m_array)
				delete[] m_array;
			m_size = a.m_size;
			m_array = new T[m_size];
			if (this != &a)
			{
				for (unsigned int i = 0; i < a.m_size; i++)
					m_array[i] = a.m_array[i];
			}
			return (*this);
		}
		
		T	&operator[]( unsigned int index)
		{
			if (index >= m_size)
				throw invalidIndexException();
			return (this->m_array[index]);
		}

		//__ DESTRUCTOR __
		~Array()
		{
			delete[] m_array;
		}

		//__ METHODES __
		unsigned int	size( void ) const
		{
			return (m_size);
		}

		//__ EXCEPTIONS __
		class invalidIndexException: public std::exception {
			public:
				const char* what( void ) const throw()
				{
					return ("Error: You try to access an invalid index." );
				}
		};
};



#endif