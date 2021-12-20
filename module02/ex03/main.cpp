/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 14:47:06 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iomanip>

void	print_result(Point const & p) {
	std::cout << p << std::endl;
}

int	main() {
	Point p1(0, 0);
	Point p2(0, 5);
	Point p3(5, 5);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	std::cout << "Triangle:" << std::endl;
	print_result(p1);
	print_result(p2);
	print_result(p3);
	std::cout << "Tests:" << std::endl;
	Point pt1(-10, -10);
	print_result(pt1);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt1) << std::endl;
	Point pt3(10, 10);
	print_result(pt3);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt3) << std::endl;
	Point pt4(5, -5);
	print_result(pt4);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt4) << std::endl;
	Point pt2(1, 2);
	print_result(pt2);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt2) << std::endl;
	Point pt5(3, 4);
	print_result(pt5);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt5) << std::endl;
	Point pt6(0, 4);
	print_result(pt6);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt6) << std::endl;
	std::cout << "Vertice tests:" << std::endl;
	std::cout << std::boolalpha << bsp(p1, p2, p3, p1) << std::endl;
	std::cout << std::boolalpha << bsp(p1, p2, p3, p2) << std::endl;
	std::cout << std::boolalpha << bsp(p1, p2, p3, p3) << std::endl;
	std::cout << "Negative triangle" << std::endl;
	Point p4(0, 0);
	Point p5(0, -5);
	Point p6(-5, -5);
	std::cout << "Triangle:" << std::endl;
	print_result(p4);
	print_result(p5);
	print_result(p6);
	Point pt7(5, -5);
	print_result(pt7);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt7) << std::endl;
	Point pt8(-1, -2);
	print_result(pt8);
	std::cout << std::boolalpha << bsp(p1, p2, p3, pt8) << std::endl;
	return 0;
}