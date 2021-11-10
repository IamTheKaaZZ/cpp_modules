/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:59:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 13:16:55 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

// Constructors / Destructors

Account::Account(void) {	//DEFAULT

}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts += 1;
}

Account::~Account(void) {
	_nbAccounts -= 1;
}

//Public Class functions

void	Account::makeDeposit(int deposit) {

}

bool	Account::makeWithdrawal(int withdrawal) {

}

int		Account::checkAmount (void) const {

}

void	Account::displayStatus(void) const {

}

// Non-member functions / attributes
//	Public

int		getNbAccounts(void) {

}

int		getTotalAmount(void) {

}

int		getNbDeposits(void) {

}

int		getNbWithdrawals(void) {

}

void	displayAccountsInfos(void) {

}

//	Private

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	_displayTimestamp(void) {
	time_t		raw;
	struct tm 	*timeinfo;
	char		buff[80];

	time(&raw);
	timeinfo = localtime(&raw);
	strftime(buff, 80, "", timeinfo);
}
