/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 16:57:30 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Float::Float() : AType(), _converted(0), _precision(1)
{
}

Float::Float(std::string const & input) : AType(input)
{
	_precision = 0;
	if (this->getStr().find("inf") != std::string::npos) {
		if (this->getStr()[0] == '+')
			this->_converted = fl::infinity();
		else
			this->_converted = -fl::infinity();
	}
	else if (this->getStr() == "nanf") {
		this->_converted = fl::quiet_NaN();
	}
	else {
		std::stringstream ss;
		ss << input;
		ss >> this->_converted;
		std::string::size_type i = -1;
		while (input[++i] != '.');
		while (input[++i] != 'f')
			_precision++;
	}
}

Float::Float(Char const & c)
{
	this->_converted = static_cast<float>(c.getConverted());
}

Float::Float(Integer const & i)
{
	this->_converted = static_cast<float>(i.getConverted());
}

Float::Float(Double const & d)
{
	if (d.getConverted() == dl::quiet_NaN()) {
		this->_converted = fl::quiet_NaN();
	}
	else if (d.getConverted() == dl::infinity()) {
		this->_converted = fl::infinity();
	}
	else if (d.getConverted() == -dl::infinity()) {
		this->_converted = -fl::infinity();
	}
	else
		this->_converted = static_cast<float>(d.getConverted());
}

Float::Float( const Float & src ) : AType(src),
	_converted(src._converted),
	_precision(src._precision)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Float::~Float()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Float &				Float::operator=( Float const & rhs )
{
	if ( this != &rhs )
	{
		this->_converted = rhs.getConverted();
		this->_precision = rhs.getPrecision();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Float const & i )
{
	o << i.toChar();
	o << i.toInt();
	if (i.getConverted() == fl::infinity())
		o << "float: +inff";
	else if (i.getConverted() == -fl::infinity())
		o << "float: -inff";
	else if (i.getConverted() == fl::quiet_NaN())
		o << "float: nanf";
	else
		o << "float: " << std::setprecision(i.getPrecision()) << i.getConverted() << 'f';
	o << std::endl;
	o << i.toDouble();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Char const &						Float::toChar() const {
	return Char(*this);
}

Integer const &					Float::toInt() const {
	return Integer(*this);
}

Float const &					Float::toFloat() const {
	return *this;
}

Double const &					Float::toDouble() const {
	return Double(*this);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */