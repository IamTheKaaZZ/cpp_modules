/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:46:45 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/22 16:10:32 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fpVal(0 * (1 << _numFracBits))
{
	// std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed( const Fixed & src ) : _fpVal(src._fpVal)
{
	// std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(int const integer) : _fpVal(integer << _numFracBits)
{
	// std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(float const fl) : _fpVal(roundf(fl * (1 << _numFracBits)))
{
	// std::cout << "Float constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	// std::cout << "Destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Assignment operater called." << std::endl;
	if ( this != &rhs )
	{
		this->_fpVal = rhs.getRawBits();
	}
	return *this;
}

bool				Fixed::operator>( Fixed const & rhs ) {
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	else
		return false;
}

bool				Fixed::operator<( Fixed const & rhs ) {
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	else
		return false;
}

bool				Fixed::operator>=( Fixed const & rhs ) {
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	else
		return false;
}

bool				Fixed::operator<=( Fixed const & rhs ) {
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	else
		return false;
}

bool				Fixed::operator==( Fixed const & rhs ) {
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	else
		return false;
}

bool				Fixed::operator!=( Fixed const & rhs ) {
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	else
		return false;
}

Fixed				Fixed::operator+( Fixed const & rhs ) {
	Fixed	result;
	long	left = (long)this->getRawBits();
	long	right = (long)rhs.getRawBits();
	if (left + right > INT32_MAX) {
		std::cout << "Integer overflow during addition." << std::endl;
		return Fixed(-1);
	}
	if (left + right < INT32_MIN) {
		std::cout << "Integer underflow during addition." << std::endl;
		return Fixed(1);
	}
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed				Fixed::operator-( Fixed const & rhs ) {
	Fixed	result;
	long	left = (long)this->getRawBits();
	long	right = (long)rhs.getRawBits();
	if (left - right > INT32_MAX) {
		std::cout << "Integer overflow during subtraction." << std::endl;
		return Fixed(-1);
	}
	if (left - right < INT32_MIN) {
		std::cout << "Integer underflow during subtraction." << std::endl;
		return Fixed(1);
	}
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed				Fixed::operator*( Fixed const & rhs ) {
	Fixed	result;
	long	left = (long)this->getRawBits();
	long	right = (long)rhs.getRawBits();
	if (left * right > INT32_MAX) {
		std::cout << "Integer overflow during multiplication." << std::endl;
		return Fixed(-1);
	}
	if (left * right < INT32_MIN) {
		std::cout << "Integer underflow during multiplication." << std::endl;
		return Fixed(1);
	}
	result.setRawBits(this->getRawBits() * rhs.getRawBits());
	return result;
}

Fixed				Fixed::operator/( Fixed const & rhs ) {
	Fixed	result;
	if (rhs.getRawBits() == 0 || (this->getRawBits() == INT32_MIN && rhs.getRawBits() == -1)) {
		std::cout << "Integer overflow during division." << std::endl;
		return Fixed(-1);
	}
	result.setRawBits(this->getRawBits() / rhs.getRawBits());
	return result;
}

Fixed&				Fixed::operator++(void) {
	this->_fpVal++;
	return *this;
}

Fixed				Fixed::operator++(int) {
	Fixed	temp = *this;
	++*this;
	return temp;
}

Fixed&				Fixed::operator--(void) {
	this->_fpVal--;
	return *this;
}

Fixed				Fixed::operator--(int) {
	Fixed	temp = *this;
	--*this;
	return temp;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int		Fixed::getRawBits() const {
	// std::cout << "getRawBits called." << std::endl;
	return this->_fpVal;
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits called." << std::endl;
	this->_fpVal = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_fpVal / (1 << _numFracBits);
}

int		Fixed::toInt(void) const {
	return (int)(_fpVal / (1 << _numFracBits));
}

Fixed&		Fixed::min(Fixed & a, Fixed & b) {
	if (a < b)
		return a;
	else if (a == b)
		return a;
	else
		return b;
}

Fixed const &		Fixed::min(Fixed const & a, Fixed const & b) {
	Fixed	tempa = a;
	Fixed	tempb = b;
	if (tempa < tempb)
		return a;
	else if (tempa == tempb)
		return a;
	else
		return b;
}

Fixed&		Fixed::max(Fixed & a, Fixed & b) {
	if (a > b)
		return a;
	else if (a == b)
		return a;
	else
		return b;
}

Fixed const &		Fixed::max(Fixed const & a, Fixed const & b) {
	Fixed	tempa = a;
	Fixed	tempb = b;
	if (tempa > tempb)
		return a;
	else if (tempa == tempb)
		return a;
	else
		return b;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */