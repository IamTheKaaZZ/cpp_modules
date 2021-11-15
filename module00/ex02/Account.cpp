/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:59:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/15 12:21:37 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

// Constructors / Destructors

Account::Account(void) : //DEFAULT 
	_accountIndex(_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0) {
		_displayTimestamp();
		cout << "index:" << this->_accountIndex << ";";
		cout << "amount:" << t::checkAmount() << ";";
		cout << "created" << endl;
		_totalAmount += t::checkAmount();
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0) {
		_displayTimestamp();
		cout << "index:" << this->_accountIndex << ";";
		cout << "amount:" << t::checkAmount() << ";";
		cout << "created" << endl;
		_totalAmount += t::checkAmount();
}

Account::~Account(void) {
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << t::checkAmount() << ";";
	cout << "closed" << endl;
	_nbAccounts -= 1;
	_totalAmount -= t::checkAmount();
}

//Public Class functions

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << t::checkAmount() << ";";
	if (deposit < 0) {
		cout << "deposit:refused" << endl;
		return ;
	}
	cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	cout << "amount:" << t::checkAmount() << ";";
	cout << "nb_deposits:" << ++this->_nbDeposits << endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << t::checkAmount() << ";";
	if (withdrawal > t::checkAmount() || withdrawal < 0) {
		cout << "withdrawal:refused" << endl;
		return false;
	}
	cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	cout << "amount:" << t::checkAmount() << ";";
	cout << "nb_withdrawals:" << ++this->_nbWithdrawals << endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount (void) const {
	return this->_amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << t::checkAmount() << ";";
	cout << "deposits:" << this->_nbDeposits << ";";
	cout << "withdrawals:" << this->_nbWithdrawals << endl;
}

// Non-member functions / attributes
//	Public

int		Account::getNbAccounts(void) {
	return _nbAccounts;
}

int		Account::getTotalAmount(void) {
	return _totalAmount;
}

int		Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts() << ";";
	cout << "total:" << getTotalAmount() << ";";
	cout << "deposits:" << getNbDeposits() << ";";
	cout << "withdrawals:" << getNbWithdrawals() << endl;
}

//	Private

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {
	time_t		raw;
	struct tm 	*timeinfo;
	char		buff[80];

	time(&raw);
	timeinfo = localtime(&raw);
	strftime(buff, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
	cout << buff;
}
