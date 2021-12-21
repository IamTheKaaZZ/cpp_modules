/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:11:49 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 12:11:51 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
**	ANIMAL
*/

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Parameter Animal constructor called." << std::endl;
}

Animal::Animal( const Animal & src )
{
	this->_type = src._type;
	std::cout << "Copy Animal constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Animal::makeSound(void) const {
	std::cout << "E... Ed.... Edward....." << std::endl;
}

std::string		Animal::getType(void) const {
	return this->_type;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/*
**	DOG
*/

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog( const Dog & src )
{
	this->_type = src._type;
	std::cout << "Copy Dog constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Dog::makeSound(void) const {
	std::cout << "Woof. I have a knife." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/*
**	CAT
*/

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat( const Cat & src )
{
	this->_type = src._type;
	std::cout << "Copy Cat constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Cat::makeSound(void) const {
	std::cout << "Meow. Feed me human." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */