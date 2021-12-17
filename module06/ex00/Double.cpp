/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/17 16:58:40 by bcosters         ###   ########.fr       */
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

Double::Double(Char const & c)
{
	this->_converted = static_cast<double>(c.getConverted());
}

Double::Double(Integer const & i)
{
	this->_converted = static_cast<double>(i.getConverted());
}

Double::Double(Float const & f)
{
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
		this->_converted = static_cast<float>(f.getConverted());
}

Double::Double( const Double & src ) : AType(src),
	_converted(src._converted),
	_precision(src._precision)
{
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
	o << i.toChar();
	o << i.toInt();
	o << i.toFloat();
	if (i.getConverted() == dl::infinity())
		o << "double: +inf";
	else if (i.getConverted() == -dl::infinity())
		o << "double: -inf";
	else if (i.getConverted() == dl::quiet_NaN())
		o << "double: nanf";
	else
		o << "double: " << std::setprecision(i.getPrecision()) << i.getConverted();
	o << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Char const &					Double::toChar() const {
	return Char(*this);
}

Integer const &					Double::toInt() const {
	return Integer(*this);
}

Float const &					Double::toFloat() const {
	return Float(*this);
}

Double const &					Double::toDouble() const {
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */