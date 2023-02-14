/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:34:52 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/25 21:33:10 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	private:
		unsigned int		m_max_size;
		std::vector<int>	m_int_vector;

	public:
	Span( unsigned int max_size );
	Span( const Span &copy );
	~Span();
	Span	&operator=( const Span& a );

	void				addNumber( int number );
	int					shortestSpan( void );
	int					longestSpan( void );
	std::vector<int>	getIntVector( void ) const;

	template <typename Iterator>
	void	addRangeNumber(Iterator begin, Iterator end)
	{
		if (m_int_vector.size() + std::distance(begin, end) > m_max_size) //checker comment verifier que l'ajout est possible
			throw Span::MaxSizeExeption();
		m_int_vector.insert(m_int_vector.end(), begin, end);
		for (size_t i = 0; i < m_int_vector.size(); i++)
			std::cout << m_int_vector[i] << std::endl;
	}

	class MaxSizeExeption: public std::exception {
		public:
			const char *what() const throw();
	};

	class IntervalExeption: public std::exception {
		public:
			const char *what() const throw();
	};

};

std::ostream 	&operator<<( std::ostream &flux, const Span &span );

#endif