/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:17:57 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 11:57:19 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade) : _name(name)
{
	std::cout << "Parameter Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade)
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

Bureaucrat &				Bureaucrat::operator++(void) {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return *this;
}

Bureaucrat					Bureaucrat::operator++(int) {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	Bureaucrat temp = *this;
	++*this;
	return temp;
}

Bureaucrat &				Bureaucrat::operator--(void) {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return *this;
}

Bureaucrat					Bureaucrat::operator--(int) {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	Bureaucrat temp = *this;
	--*this;
	return temp;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << "Name = " << i.getName() << ", grade = " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &			Bureaucrat::getName() const {
	return this->_name;
}

int const &			Bureaucrat::getGrade() const {
	return this->_grade;
}

/* ************************************************************************** */