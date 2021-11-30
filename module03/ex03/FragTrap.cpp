/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 11:37:12 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	setName(" FragTrap");
	setHp();
	setEp();
	setAd();
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setName(name);
	setHp();
	setEp();
	setAd();
	std::cout << "Named FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << "Copy FragTrap constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_maxHP = rhs._hitpoints;
		this->_energyPoints = rhs._energyPoints;
		this->_maxEP = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "FragTrap <" << i.getName() << "> has " << i.getHP() << " HP, " << i.getEP() << " EP and " << i.getAD() << " Attack Damage.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			FragTrap::setName(std::string name) {
	this->_name = name;
}

void			FragTrap::setHp(void) {
	this->_hitpoints = this->_maxHP = 100;
}

void			FragTrap::setEp(void) {
	this->_energyPoints = this->_maxEP = 100;
}

void			FragTrap::setAd(void) {
	this->_attackDamage = 30;
}

void		FragTrap::highFivesGuys(void) const {
	std::cout << "<" << this->getName() << ">: Goob job my minion! Time for a high five!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */