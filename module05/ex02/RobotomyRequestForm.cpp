/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:45:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 17:26:37 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Nothing", 72),
	_target("Nobody"),
	_execGrade(45)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	Form("RobotomyRequest", 72),
	_target(target),
	_execGrade(45)
{
	std::cout << "Parameter RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	Form(src),
	_target(src._target),
	_execGrade(45)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	return i.outputformat(o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::ostream &			RobotomyRequestForm::outputformat(std::ostream & o) const {
	Form::outputformat(o);
	o << "Target is " << this->getTarget() << " and needs a grade of " << this->_execGrade << " to be executed.";
	return o;
}

void					RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->_execGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->isFormSigned()) {
		bool coinflip = (rand() % 2) != 0;
		std::cout << "BzzzzzzzRRRRZzzzzzzrrzzzzzzRRZRZrzrzzrzrzrrrzBBrrr" << std::endl;
		if (coinflip)
			std::cout << this->getTarget() << " has been successfully robotimized." << std::endl;
		else
			std::cout << this->getTarget() << " has NOT been successfully robotimized." << std::endl;
	}
	else {
		std::cout << "Form has NOT been signed and cannot be executed" << std::endl;
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */