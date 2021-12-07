/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:16:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/07 15:55:15 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//AMATERIA

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : type("typeless")
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "Parameter AMateria constructor called" << std::endl;
}

AMateria::AMateria( const AMateria & src ) : type(src.type)
{
	std::cout << "Copy AMateria constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					AMateria::use(ICharacter& target) {
	std::string	output = "* uses TYPE on NAME *";
	size_t		found = output.find("NAME");
	if (found != std::string::npos) {
		output.erase(found, std::string("NAME").length());
		output.insert(found, target.getName());
	}
	found = output.find("TYPE");
	if (found != std::string::npos) {
		output.erase(found, std::string("TYPE").length());
		output.insert(found, this->getType());
	}
	std::cout << output << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		AMateria::getType(void) const {
	return this->type;
}

//ICE

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	std::cout << "Copy Ice constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*				Ice::clone(void) const {
	return new Ice();
}

void					Ice::use(ICharacter& target) {
	std::string	output = "* shoots an ice bolt at NAME *";
	size_t		found = output.find("NAME");
	if (found != std::string::npos) {
		output.erase(found, std::string("NAME").length());
		output.insert(found, target.getName());
	}
	std::cout << output << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		Ice::getType(void) const {
	return this->type;
}

//CURE

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
	std::cout << "Copy Cure constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*				Cure::clone(void) const {
	return new Cure();
}

void					Cure::use(ICharacter& target) {
	std::string	output = "* heals NAME’s wounds *";
	size_t		found = output.find("NAME");
	if (found != std::string::npos) {
		output.erase(found, std::string("NAME").length());
		output.insert(found, target.getName());
	}
	std::cout << output << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		Cure::getType(void) const {
	return this->type;
}

/* ************************************************************************** */