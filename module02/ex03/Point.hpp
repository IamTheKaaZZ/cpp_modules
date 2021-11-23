/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:21:09 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/23 17:24:01 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( Point const & src );
		Point( float x, float y );
		~Point();

		//THIS MAKES NO SENSE
		Point const &		operator=( Point const & rhs ) const;
		Fixed const &		getX(void) const;
		Fixed const &		getY(void) const;

	private:

		Fixed const	_x;
		Fixed const	_y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */