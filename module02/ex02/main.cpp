/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 14:40:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

void	print_result(Fixed const & fpn) {
	std::cout << fpn << std::endl;
}

int	main() {
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(4242.42f);
	Fixed e(5);
	Fixed const f = (Fixed(5.05f) * Fixed(2));

	print_result(a);
	std::cout << std::boolalpha << (a == Fixed(0)) << std::endl;
	++a;
	std::cout << std::boolalpha << (a == Fixed(0)) << std::endl;
	print_result(a);
	print_result(a++);
	print_result(a);
	a = b + c;
	print_result(a);
	std::cout << std::boolalpha << (a > b) << std::endl;
	std::cout << std::boolalpha << (a < b) << std::endl;
	std::cout << std::boolalpha << (a >= b) << std::endl;
	std::cout << std::boolalpha << (a <= b) << std::endl;
	std::cout << std::boolalpha << (a != b) << std::endl;
	print_result(--a);
	print_result(a--);
	print_result(a);
	print_result(d);
	print_result(d * 2);
	print_result(d * Fixed(2));
	print_result(d / 2);
	print_result(d / Fixed(2));
	print_result(d - a);
	print_result(Fixed::min(a, d));
	print_result(Fixed::max(a, d));
	print_result(e / 2.5f);
	print_result(f);
	return 0;
}