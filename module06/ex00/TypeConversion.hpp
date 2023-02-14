/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:34:31 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/22 19:58:12 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECONVERSION_HPP
# define TYPECONVERSION_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <errno.h>
# include <limits>
# include <exception>
# include <cstdlib>
# include <iomanip>

class TypeConversion
{
	private:
		std::string		m_type_name;
		int				m_precision;
		int				m_int_val;
		float			m_float_val;
		char			m_char_val;
		double			m_double_val;

		static void		strTrim( std::string &arg );
		static bool		isIntOverflow( std::string arg );
		bool			isChar( std::string arg);
		bool			isInt( std::string arg);
		bool			isFloat( std::string arg);
		bool			isDouble( std::string arg);
		bool 			impossibleConv( std::string arg );
		void			conversionFromChar( std::string arg );
		void			conversionFromInt( std::string arg );
		void			conversionFromFloat( std::string arg );
		void			conversionFromDouble( std::string arg );

		typedef bool	(TypeConversion::*funcType)( std::string );
		typedef void	(TypeConversion::*funcConv)( std::string );
		typedef struct s_funcPtr
		{
			funcType	type_func;
			funcConv	conversion_func;
		}				t_funcPtr;

	public:
		TypeConversion( std::string arg );
		TypeConversion( TypeConversion &copy );
		TypeConversion &operator=( TypeConversion &a );
		~TypeConversion();

		char 	getChar( void ) const;
		int 	getInt( void ) const;
		float 	getFloat( void ) const;
		double 	getDouble( void ) const;
		int 	getPrecision( void ) const;
		void	setPrecision( std::string arg );
		bool	isPseudoLiteralDouble( std::string arg );
		bool	isPseudoLiteralFloat( std::string arg );

		class OverflowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class ImpossibleConversionException: public std::exception {
			public:
				const char *what() const throw(); 
		};
};

std::ostream 	&operator<<( std::ostream &flux, const TypeConversion &conversion );

#endif