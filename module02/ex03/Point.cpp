/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:21:09 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/23 17:46:18 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0)
{
}

Point::Point( const Point & src ) : _x(src._x), _y(src._y)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point const &				Point::operator=( Point const & rhs ) const
{
	return rhs; //YOU CANNOT CHANGE CONST VALUES LOL
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "x = " << i.getX() << ", y = " << i.getY();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed const &		Point::getX(void) const {
	return this->_x;
}

Fixed const &		Point::getY(void) const {
	return this->_y;
}
/* ************************************************************************** */