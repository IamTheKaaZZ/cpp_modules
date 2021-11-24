/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:50:22 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/24 12:31:21 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	sign(Point const p1, Point const p2, Point const p3) { //Cross-product to determine sign
	Fixed	p1x = p1.getX();
	Fixed	p2x = p2.getX();
	Fixed	p3x = p3.getX();
	Fixed	p1y = p1.getY();
	Fixed	p2y = p2.getY();
	Fixed	p3y = p3.getY();
	return ((p1x - p3x) * (p2y - p3y)) - ((p2x - p3x) * (p1y - p3y));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, a, c);
	// std::cout << "d1: " << d1 << " d2: " << d2 << " d3: " << d3 << std::endl;
	bool	zero = (d1 == 0) || (d2 == 0) || (d3 == 0); //point is on an edge if 0
	bool	neg = (d1 * d2 * d3 < 0);					//product is negative if outside of triangle

	if (zero || neg)
		return false;
	else
		return true;
}