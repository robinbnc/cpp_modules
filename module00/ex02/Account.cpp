/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:39:35 by rbicanic          #+#    #+#             */
/*   Updated: 2022/04/14 18:48:24 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:";
	std::cout << initial_deposit << ";created" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
	std::tm *const pTInfo = std::localtime(&t);

	std::cout << "[" << 1900 + pTInfo->tm_year;
	if (pTInfo->tm_mon + 1 < 10)
		std::cout << "0" << pTInfo->tm_mon + 1;
	else
		std::cout << pTInfo->tm_mon + 1;
	if (pTInfo->tm_mday < 10)
		std::cout << "0" << pTInfo->tm_mday;
	else
		std::cout << pTInfo->tm_mday << "_";
	if (pTInfo->tm_hour < 10)
		std::cout << "0" << pTInfo->tm_hour;
	else
		std::cout << pTInfo->tm_hour;
	if (pTInfo->tm_min < 10)
		std::cout << "0" << pTInfo->tm_min;
	else
		std::cout << pTInfo->tm_min;
	if (pTInfo->tm_sec < 10)
		std::cout << "0" << pTInfo->tm_sec;
	else
		std::cout << pTInfo->tm_sec;
	std::cout << "] ";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) //static
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:";
	std::cout << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:";
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:";
	std::cout << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}


Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
