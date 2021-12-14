/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:33:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/14 16:29:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
	_makeTable[0] = s_make("shrubbery creation", &Intern::_makeSC);
	_makeTable[1] = s_make("robotomy request", &Intern::_makeRR);
	_makeTable[2] = s_make("presidential pardon", &Intern::_makePP);
}

Intern::Intern( const Intern & src )
{
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "I'm just an intern man, i make forms";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form*					Intern::makeForm(std::string const & name, std::string const & target) {
	Form* fp = NULL;
	for (int i = 0; i < 3; i++) {
		if (_makeTable[i].name == name) fp = (this->*_makeTable[i].fp)(target);
	}
	if (!fp)
		std::cerr << "Bro I only know how to make three forms." << std::endl;
	return fp;
}

Form*					Intern::_makeSC(std::string const & target) {
	return new ShrubberyCreationForm(target);
}

Form*					Intern::_makeRR(std::string const & target) {
	return new RobotomyRequestForm(target);
}

Form*					Intern::_makePP(std::string const & target) {
	return new PresidentialPardonForm(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */