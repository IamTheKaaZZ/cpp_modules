/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 13:43:20 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Double::Double() : AType(), _converted(0), _precision(1)
{
}

Double::Double(std::string const & input) : AType(input)
{
	std::cout << "Double constructor" << std::endl;
	_precision = 0;
	if (this->getStr().find("inf") != std::string::npos) {
		if (this->getStr()[0] == '+')
			this->_converted = dl::infinity();
		else
			this->_converted = -dl::infinity();
	}
	else if (this->getStr() == "nan") {
		this->_converted = dl::quiet_NaN();
	}
	else {
		std::stringstream ss;
		ss << input;
		ss >> this->_converted;
		std::string::size_type i = -1;
		while (input[++i] != '.');
		while (input[++i])
			_precision++;
	}
}

Double::Double(Char const & c) : AType(c), _precision(1)
{
	std::cout << "Double from Char constructor" << std::endl;
	this->_converted = static_cast<double>(c.getConverted());
}

Double::Double(Integer const & i) : AType(i), _precision(1)
{
	std::cout << "Double from Int constructor" << std::endl;
	this->_converted = static_cast<double>(i.getConverted());
}

Double::Double(Float const & f) : AType(f), _precision(f.getPrecision())
{
	std::cout << "Double from Float constructor" << std::endl;
	if (f.getConverted() == fl::quiet_NaN()) {
		this->_converted = dl::quiet_NaN();
	}
	else if (f.getConverted() == fl::infinity()) {
		this->_converted = dl::infinity();
	}
	else if (f.getConverted() == -fl::infinity()) {
		this->_converted = -dl::infinity();
	}
	else
		this->_converted = static_cast<double>(f.getConverted());
}

Double::Double( const Double & src ) : AType(src),
	_converted(src._converted),
	_precision(src._precision)
{
	std::cout << "Double copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Double::~Double()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Double &				Double::operator=( Double const & rhs )
{
	if ( this != &rhs )
	{
		this->_converted = rhs.getConverted();
		this->_precision = rhs.getPrecision();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Double const & i )
{
	if (i.getConverted() == dl::infinity())
		o << "double: +inf";
	else if (i.getConverted() == -dl::infinity())
		o << "double: -inf";
	else if (i.getConverted() == dl::quiet_NaN())
		o << "double: nanf";
	else
		o << "double: " << std::fixed << std::setprecision(i.getPrecision()) << i.getConverted();
	o << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AType*					Double::toChar() const {
	return new Char(*this);
}

AType*					Double::toInt() const {
	return new Integer(*this);
}

AType*					Double::toFloat() const {
	return new Float(*this);
}

AType*					Double::toDouble() const {
	return new Double(*this);
}

void				Double::convertPrint() const {
	AType*	C = this->toChar();
	AType*	I = this->toInt();
	AType*	F = this->toFloat();
	std::cout << *static_cast<Char*>(C);
	std::cout << *static_cast<Integer*>(I);
	std::cout << *static_cast<Float*>(F);
	std::cout << *this;
	delete C;
	delete I;
	delete F;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */