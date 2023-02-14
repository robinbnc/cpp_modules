/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:34:52 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/08 19:59:26 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template<typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void ) {}
		MutantStack( const MutantStack<T, Container> &copy )
		{
			if (this != &copy)
				*this = copy;
		}

		MutantStack<T, Container>	&operator=(const MutantStack<T, Container> &a) {
			std::stack<T, Container>::operator=(a); 
			return (*this);
		}
		~MutantStack( void ) {}
		
		typedef	typename Container::iterator iterator;

		iterator	begin() {return (this->c.begin());}
		iterator	end() {return (this->c.end());}
};

#endif