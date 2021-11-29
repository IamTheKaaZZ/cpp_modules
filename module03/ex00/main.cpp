/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 12:16:39 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

void	print_result(ClapTrap const & ct) {
	std::cout << ct << std::endl;
}

int	main() {
	ClapTrap a;
	ClapTrap b("Johnny");
	ClapTrap c = b;
	ClapTrap d("Cookie");

	print_result(a);
	print_result(b);
	print_result(c);
	print_result(d);
	b.attack("a freaking rock");
	b.takeDamage(5);
	b.beRepaired(12);
	b.attack("another freaking rock");
	d.attack("Moulinette");
	d.takeDamage(42);
	print_result(a);
	print_result(b);
	print_result(c);
	print_result(d);
	return 0;
}