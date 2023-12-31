/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:30:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:14:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

//========= STATIC VARIABLES =========//

int	Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

//========= CONSTRUCTOR =========//

Account::Account( int initial_deposit ) : _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

//========= DESTRUCTOR =========//

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed" << std::endl;
	this->_nbAccounts--;
	Account::_totalAmount -= this->checkAmount();
}

//========= GETTER FUNCTION =========//

int	Account::getNbAccounts( void ) { return Account::_nbAccounts; }

int Account::getTotalAmount( void ) { return Account::_totalAmount; }

int Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }

int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

//========= MEMBER FUNCTION =========//

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		currentTime = time(0);
	std::tm*	localTime = std::localtime(&currentTime);

	std::cout << "[" << localTime->tm_year + 1900;
	std::cout << localTime->tm_mon + 1;
	std::cout << localTime->tm_mday << "_";
	std::cout << localTime->tm_hour;
	std::cout << localTime->tm_min;
	std::cout << localTime->tm_sec << "] ";
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "withdrawal:";
	if (withdrawal < 0 || withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
		std::cout << withdrawal << ";";
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}


void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ":";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
