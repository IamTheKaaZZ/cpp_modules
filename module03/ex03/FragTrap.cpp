/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 17:19:11 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	this->ClapTrap::_name = "FragTrap";
	this->ClapTrap::_hitpoints = 100;
	this->ClapTrap::_maxHP = 100;
	this->ClapTrap::_energyPoints = 100;
	this->ClapTrap::_maxEP = 100;
	this->ClapTrap::_attackDamage = 30;
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->ClapTrap::_hitpoints = 100;
	this->ClapTrap::_maxHP = 100;
	this->ClapTrap::_energyPoints = 100;
	this->ClapTrap::_maxEP = 100;
	this->ClapTrap::_attackDamage = 30;
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
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->ClapTrap::_hitpoints = rhs.ClapTrap::_hitpoints;
		this->ClapTrap::_maxHP = rhs.ClapTrap::_hitpoints;
		this->ClapTrap::_energyPoints = rhs.ClapTrap::_energyPoints;
		this->ClapTrap::_maxEP = rhs.ClapTrap::_energyPoints;
		this->ClapTrap::_attackDamage = rhs.ClapTrap::_attackDamage;
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

void		FragTrap::highFivesGuys(void) const {
	std::cout << "<" << this->getName() << ">: Goob job my minion! Time for a high five!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */