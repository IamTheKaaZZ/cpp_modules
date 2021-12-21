/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:22:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 11:21:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap(), _gateKeeperMode(false)
{
	setName(" ScavTrap");
	setHp();
	setEp();
	setAd();
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeperMode(false)
{
	setHp();
	setEp();
	setAd();
	std::cout << "Named ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	this->_gateKeeperMode = src._gateKeeperMode;
	std::cout << "Copy ScavTrap constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
		this->_gateKeeperMode = rhs._gateKeeperMode;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	o << "ScavTrap <" << i.getName() << "> has " << i.getHP() << " HP, " << i.getEP() << " EP and " << i.getAD() << " Attack Damage.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			ScavTrap::setName(std::string name) {
	this->_name = name;
}

void			ScavTrap::setHp(void) {
	this->_hitpoints = this->_maxHP = 100;
}

void			ScavTrap::setEp(void) {
	this->_energyPoints = this->_maxEP = 50;
}

void			ScavTrap::setAd(void) {
	this->_attackDamage = 20;
}

void			ScavTrap::guardGate(void) {
	if (this->_gateKeeperMode) {
		this->_gateKeeperMode = false;
		std::cout << "ScavTrap <" << this->getName() << "> is no longer shouting \"HODOR HODOR!\"" << std::endl;
	}
	else {
		this->_gateKeeperMode = true;
		std::cout << "ScavTrap <" << this->getName() << "> started shouting \"HODOR HODOR!\"" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */