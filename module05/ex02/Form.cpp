/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:53:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 15:20:58 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name(""), _isSigned(false), _gradeRequired(150)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string const & name, int const & required) : _name(name),
	_isSigned(false),
	_gradeRequired(required)
{
	std::cout << "Parameter Form constructor called" << std::endl;
	if (_gradeRequired < 1)
		throw Form::GradeTooHighException();
	else if (_gradeRequired > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form & src ) : _name(src._name),
	_isSigned(src._isSigned),
	_gradeRequired(src._gradeRequired)
{
	std::cout << "Copy Form constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	return i.outputformat(o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::ostream &			Form::outputformat(std::ostream & o) const {
	o << "Form = " << this->getName() << ", needs a grade of " << this->getGradeRequired() << " to be signed.";
	o << " The form is ";
	if (this->isFormSigned())
		o << "signed";
	else
		o << "not signed";
	return o;
}

bool					Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= this->_gradeRequired) {
		this->_isSigned = true;
		return true;
	}
	else {
		throw Form::GradeTooLowException();
		return false;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */