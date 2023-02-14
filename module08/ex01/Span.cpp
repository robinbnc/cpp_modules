/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:56:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/14 18:44:02 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int max_size ): m_max_size(max_size) {}

Span::Span( const Span &copy )
{
	if (this != &copy)
		*this = copy;
}

void	Span::addNumber(int number)
{
	if (m_int_vector.size() >= m_max_size)
		throw Span::MaxSizeExeption();
	m_int_vector.push_back(number);
}

int		Span::longestSpan( void )
{
	if (m_int_vector.size() < 2)
		throw Span::IntervalExeption();

	int	vector_max_value = *std::max_element(m_int_vector.begin(), m_int_vector.end());
	int	vector_min_value = *std::min_element(m_int_vector.begin(), m_int_vector.end());

	return (vector_max_value - vector_min_value);
}

int		Span::shortestSpan( void )
{
	if (m_int_vector.size() < 2)
		throw Span::IntervalExeption();

	std::vector<int>	tmp_vector(m_int_vector);
	int					shortest_span;

	sort(tmp_vector.begin(), tmp_vector.end());
	shortest_span = tmp_vector[1] - tmp_vector[0];
	for (size_t i = 1; i < tmp_vector.size() - 1; i++)
		if (tmp_vector[i + 1] - tmp_vector[i] < shortest_span)
			shortest_span = tmp_vector[i + 1] - tmp_vector[i];
	return (shortest_span);
}

Span 	&Span::operator=( const Span &a )
{
	if (this == &a)
		return (*this);
	m_max_size = a.m_max_size;
	m_int_vector = a.m_int_vector;
	return (*this);
}
std::vector<int>	Span::getIntVector( void ) const
{
	return (m_int_vector);
}

std::ostream 	&operator<<( std::ostream &flux, const Span &span )
{
	for (size_t i = 0; i < span.getIntVector().size(); i++)
		flux << span.getIntVector()[i] << (i != span.getIntVector().size() - 1 ? ", " : "");
	return (flux);
}

Span::~Span() {}

const char *Span::MaxSizeExeption::what() const throw()
{
	return ("Error: Adding a number to the span is impossibe, you reached the max size.\n");
}

const char *Span::IntervalExeption::what() const throw()
{
	return ("Error: finding interval is impossible, not enough elements.\n");
} 

//3, 6, 9, 11, 17