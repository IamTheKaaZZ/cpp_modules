/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:50:22 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/23 17:22:54 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	sign(Point const p1, Point const p2, Point const p3) {
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())) - ((p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, a, c);
	bool	neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	bool	pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

	if (neg && pos)
		return false;
	else
		return true;
}