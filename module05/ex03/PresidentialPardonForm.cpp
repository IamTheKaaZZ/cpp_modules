/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:46:18 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 17:50:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardon", 25),
	_target("Nobody"),
	_execGrade(5)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	Form("PresidentialPardon", 25),
	_target(target),
	_execGrade(5)
{
	std::cout << "Parameter PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	Form(src),
	_target(src._target),
	_execGrade(5)
{
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	return i.outputformat(o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::ostream &			PresidentialPardonForm::outputformat(std::ostream & o) const {
	Form::outputformat(o);
	o << "Target is " << this->getTarget() << " and needs a grade of " << this->_execGrade << " to be executed.";
	return o;
}


void					PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->_execGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->isFormSigned()) {
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
	else {
		std::cout << "Form has NOT been signed and cannot be executed" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */