/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:18:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 17:21:46 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitpoints(10), _maxHP(10), _energyPoints(10), _maxEP(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _maxHP(10), _energyPoints(10), _maxEP(10), _attackDamage(0)
{
	std::cout << "Named ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) : _name(src._name), _hitpoints(src._hitpoints), _maxHP(src._maxHP), _energyPoints(src._energyPoints), _maxEP(src._maxEP), _attackDamage(src._attackDamage)
{
	std::cout << "Copy ClapTrap constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "<" << i.getName() << "> has " << i.getHP() << " HP, " << i.getEP() << " EP and " << i.getAD() << " Attack Damage.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			ClapTrap::attack(std::string const & target) {
	if (this->_energyPoints == 0) {
		std::cout << "<" << getName() << "> is out of Energy points and has to recharge!" << std::endl;
		return;
	}
	else
		std::cout << "<" << getName() << "> has " << getEP() << " Energy Points remaining!" << std::endl;
	std::cout << "<" << getName() << "> attacks " << target << ", causing " << getAD() << " points of damage!" << std::endl;
	std::cout << "<" << getName() << "> spent 10 Energy Points doing so!" << std::endl;
	(10 >= this->_energyPoints) ? this->_energyPoints = 0 : this->_energyPoints -= 10;
}

void			ClapTrap::takeDamage(unsigned int amount) {
	(amount >= this->_hitpoints) ? this->_hitpoints = 0 : this->_hitpoints -= amount;
	if (this->_hitpoints != 0)
		std::cout << "<" << getName() << "> took " << amount << " points of damage!" << std::endl;
	else
		std::cout << "<" << getName() << "> took " << amount << " points of damage and was destroyed!" << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount) {
	if (amount + this->_hitpoints > this->_maxHP)
		std::cout << "<" << getName() << "> was repaired for " << this->_maxHP - this->_hitpoints << " hitpoints!" << std::endl;
	else
		std::cout << "<" << getName() << "> was repaired for " << amount << " hitpoints!" << std::endl;
	(amount + this->_hitpoints > this->_maxHP) ? this->_hitpoints = this->_maxHP : this->_hitpoints += amount;
	this->_energyPoints = this->_maxEP;
	std::cout <<  "<" << getName() << "> got its Energy points restored to full!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int		ClapTrap::getHP(void) const {
	return this->_hitpoints;
}

unsigned int		ClapTrap::getEP(void) const {
	return this->_energyPoints;
}

unsigned int		ClapTrap::getAD(void) const {
	return this->_attackDamage;
}

/* ************************************************************************** */