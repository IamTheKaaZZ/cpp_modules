/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/22 13:22:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main() {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a(int) is " << a.toInt() << std::endl;
	std::cout << "b(int) is " << b.toInt() << std::endl;
	std::cout << "c(int) is " << c.toInt() << std::endl;
	std::cout << "d(int) is " << d.toInt() << std::endl;
	return 0;
}