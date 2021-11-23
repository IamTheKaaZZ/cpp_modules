/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/23 17:52:47 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iomanip>

void	print_result(Point const & p) {
	std::cout << p << std::endl;
}

int	main() {
	Point p1(0, 5);
	Point p2(1.5, 2.5);
	Point p3(2.5, 2);
	std::cout << "Triangle:" << std::endl;
	print_result(p1);
	print_result(p2);
	print_result(p3);
	std::cout << "Tests:" << std::endl;
	Point pt1(-10, -10);
	print_result(pt1);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt1) << std::endl;
	Point pt2(0.5, 1);
	print_result(pt2);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt2) << std::endl;
	std::cout << "Vertice tests:" << std::endl;
	std::cout << std::boolalpha << bsp(p1, p2, p3, p1) << std::endl;
	std::cout << std::boolalpha << bsp(p1, p2, p3, p2) << std::endl;
	std::cout << std::boolalpha << bsp(p1, p2, p3, p3) << std::endl;
	return 0;
}