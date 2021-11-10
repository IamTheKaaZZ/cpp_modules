/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:59:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/10 12:13:36 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Constructors / Destructors

Account::Account(void) {	//DEFAULT

}

Account::Account(int initial_deposit) {

}

Account::~Account(void) {

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

static int	_nbAccounts = 0;
static int	_totalAmounts = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

void	_displayTimestamp(void) {

}
