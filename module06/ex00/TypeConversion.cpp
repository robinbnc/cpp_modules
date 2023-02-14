/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:40:44 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/16 12:18:55 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConversion.hpp"

TypeConversion::TypeConversion( std::string arg )
{
	t_funcPtr		m_funcArray[5] = 
	{
		{&TypeConversion::isChar		,	&TypeConversion::conversionFromChar},
		{&TypeConversion::isDouble		,	&TypeConversion::conversionFromDouble},
		{&TypeConversion::isFloat		,	&TypeConversion::conversionFromFloat},
		{&TypeConversion::isInt			,	&TypeConversion::conversionFromInt},
		{&TypeConversion::impossibleConv, 	NULL},
	};

	if (!arg.length())
		throw TypeConversion::ImpossibleConversionException();
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 1)
			TypeConversion::strTrim(arg);
		if ((this->*m_funcArray[i].type_func)(arg) == true)
		{
			try {(this->*m_funcArray[i].conversion_func)(arg);}
			catch (std::exception & e) {throw ;}
			break ;
		}
	}
	this->setPrecision(arg);
}

void	TypeConversion::strTrim( std::string &arg )
{
	while (arg[0] == ' ' && arg[0])
		arg.erase(arg.begin());
	while (arg.length() && arg[arg.length() - 1] == ' ')
		arg.erase(arg.end() - 1);
}

bool	TypeConversion::isIntOverflow( std::string arg )
{
	int 	sign 	= (arg[0] == '-' ? -1 : 1);
	size_t	str_len = arg.length();

	if ((sign < 0 && str_len > 11) || (sign > 0 && str_len > 10))
		return (true);
	else if ((sign < 0 && str_len < 11) || (sign > 0 && str_len < 10))
		return (false);
	if ((sign < 0 && arg.compare("-2147483648") > 0)
		|| (sign > 0 && arg.compare("2147483647") > 0))
		return (true);
	return (false);
}

bool	TypeConversion::isPseudoLiteralDouble( std::string arg )
{
	for (size_t i = 0; i < arg.length(); i++)
		arg[i] = std::toupper(arg[i]);

	bool	is_pseudo_literal = (arg == "-INF" || arg == "+INF" || arg == "INF" || arg == "NAN");
	return (is_pseudo_literal);
}

bool	TypeConversion::isPseudoLiteralFloat( std::string arg )
{
	for (size_t i = 0; i < arg.length(); i++)
		arg[i] = std::toupper(arg[i]);

	bool	is_pseudo_literal = (arg == "-INFF" || arg == "+INFF" || arg == "INFF" || arg == "NANF");
	return (is_pseudo_literal);
}

bool	TypeConversion::isChar( std::string arg)
{
	bool	is_char = (arg.length() == 1 && !std::isdigit(arg[0]));

	return (is_char);
}

bool	TypeConversion::isInt( std::string arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if ((i == 0 && !std::isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			|| (i != 0 && !std::isdigit(arg[i])))
			return (false);
	}
	return (true);
}

bool	TypeConversion::isDouble( std::string arg)
{
	if (this->isPseudoLiteralDouble(arg)
		|| (this->isInt(arg) && TypeConversion::isIntOverflow(arg)))
		return (true);
	if (arg.find_first_of('.') == std::string::npos
		|| arg.find_first_of('.') !=  arg.find_last_of('.'))
		return (false);
	return (true);
}

bool	TypeConversion::isFloat( std::string arg)
{
	if (this->isPseudoLiteralFloat(arg))
		return (true);
	if (arg.find_first_of('.') == std::string::npos
		|| arg[arg.length() - 1] != 'f'
		|| arg.find_first_of(".") !=  arg.find_last_of("."))
			return (false);
	return (true);
}

void	TypeConversion::conversionFromChar( std::string arg )
{
	m_char_val = arg[0];
	m_int_val = static_cast<int>(m_char_val);
	m_float_val = static_cast<float>(m_char_val);
	m_double_val = static_cast<double>(m_char_val);
}

void	TypeConversion::conversionFromInt( std::string arg )
{
	int	char_max = 127;

	m_int_val = std::atoi(arg.c_str());
	if (m_int_val <= char_max && m_int_val >= 0)
		m_char_val = static_cast<char>(m_int_val);
	m_float_val = static_cast<float>(m_int_val);
	m_double_val = static_cast<double>(m_int_val);
}

void	TypeConversion::conversionFromFloat( std::string arg )
{
	int is_pseudo_lit = this->isPseudoLiteralFloat(arg);

	m_float_val = std::strtof(arg.c_str(), NULL);
	if (errno == ERANGE)
		throw TypeConversion::OverflowException();
	if (m_float_val <= 127 && m_float_val >= 0 && !is_pseudo_lit)
		m_char_val = static_cast<char>(m_float_val);
	if (m_float_val >= std::numeric_limits<int>::min()
		&& m_float_val <= std::numeric_limits<int>::max() && !is_pseudo_lit)
		m_int_val = static_cast<int>(m_float_val);
	m_double_val = static_cast<double>(m_float_val);
}

void	TypeConversion::conversionFromDouble( std::string arg )
{
	int is_pseudo_lit = this->isPseudoLiteralDouble(arg);

	m_double_val = std::strtod(arg.c_str(), NULL);
	if (errno == ERANGE)
		throw TypeConversion::OverflowException();
	if (m_double_val <= 127&& m_double_val >= 0 && !is_pseudo_lit)
		m_char_val = static_cast<char>(m_double_val);
	if (m_double_val >= std::numeric_limits<int>::min()
		&& m_double_val <= std::numeric_limits<int>::max() && !is_pseudo_lit)
		m_int_val = static_cast<int>(m_double_val);
	m_float_val = static_cast<double>(m_double_val);
}

char TypeConversion::getChar( void ) const
{
	return (m_char_val);
}

int TypeConversion::getInt( void ) const
{
	return (m_int_val);
}

float TypeConversion::getFloat( void ) const
{
	return (m_float_val);
}

double TypeConversion::getDouble( void ) const
{
	return (m_double_val);
}

int TypeConversion::getPrecision( void ) const
{
	return (m_precision);
}

bool TypeConversion::impossibleConv( std::string arg )
{
	(void)arg;
	throw TypeConversion::ImpossibleConversionException();
	return (1);
}

void		TypeConversion::setPrecision( std::string arg )
{
	int	i = 0;

	if (arg.find_first_of('.') == std::string::npos)
	{
		m_precision = 1;
		return ;
	}
	for (size_t j = arg.find_first_of('.'); j < arg.length(); j++)
	{
		if (std::isdigit(arg[j]))
			i++;
	}
	m_precision = i;
}

TypeConversion::~TypeConversion() {}

static void	print_char( std::ostream &flux, const TypeConversion &conversion )
{
	if (conversion.getDouble() > 127
		|| conversion.getDouble() < 0
		|| std::abs(conversion.getDouble()) == std::numeric_limits<double>::infinity()
		|| conversion.getDouble() != conversion.getDouble())
		flux << "char: " << "impossible" << "\n";
	else if (!std::isprint(conversion.getInt()))
		flux << "char: " << "Non displayable" << "\n";
	else
		flux << "char: '" << conversion.getChar() << "'" << "\n";
}

static void	print_int( std::ostream &flux, const TypeConversion &conversion )
{
	if (conversion.getDouble() < static_cast<double>(std::numeric_limits<int>::min())
		|| conversion.getDouble() > static_cast<double>(std::numeric_limits<int>::max())
		|| std::abs(conversion.getDouble()) == std::numeric_limits<double>::infinity()
		|| conversion.getDouble() != conversion.getDouble())
		flux << "int: " << "impossible" << "\n";
	else
		flux << "int: " << conversion.getInt() << "\n";
}

static void	print_float( std::ostream &flux, const TypeConversion &conversion )
{
	bool is_pseudo_lit = (std::abs(conversion.getDouble()) == std::numeric_limits<double>::infinity()
		|| conversion.getDouble() != conversion.getDouble());

	if (!is_pseudo_lit && (conversion.getFloat() == -static_cast<double>(std::numeric_limits<float>::infinity())
		|| conversion.getFloat() == static_cast<double>(std::numeric_limits<float>::infinity())))
	{
		flux << "float: " << "impossible" << "\n";
		return ;
	}
	flux << "float: ";
	if (conversion.getDouble() == std::numeric_limits<double>::infinity())
		flux << "+";
	flux << conversion.getFloat() << "f\n";
}

std::ostream 	&operator<<( std::ostream &flux, const TypeConversion &conversion )
{
	flux << std::setprecision(conversion.getPrecision()) << std::fixed;
	print_char(flux, conversion);
	print_int(flux, conversion);
	print_float(flux, conversion);
	flux << "double: ";
	if (conversion.getDouble() == std::numeric_limits<double>::infinity())
		flux << "+";
	flux << conversion.getDouble();
	return (flux);
}

const char*	TypeConversion::OverflowException::what( void ) const throw()
{
	return ("Error: The conversion will cause an overfow, try to pass a literal in range");
}

const char*	TypeConversion::ImpossibleConversionException::what( void ) const throw()
{
	return ("Error: The conversion is impossible, the input don't match with any of this types {char, int, float, double}");
}
