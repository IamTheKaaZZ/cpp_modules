/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 14:45:43 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	this->setName("FragTrap");
	this->setHP(100);
	this->setEP(100);
	this->setAD(30);
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->setName(name);
	this->setHP(100);
	this->setEP(100);
	this->setAD(30);
	std::cout << "Named FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	this->setName(src.getName());
	this->setHP(src.getHP());
	this->setEP(src.getEP());
	this->setAD(src.getAD());
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
		this->setName(rhs.getName());
		this->setHP(rhs.getHP());
		this->setEP(rhs.getEP());
		this->setAD(rhs.getAD());
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