/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/29 14:43:44 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iomanip>

void	print_result(ClapTrap const & p) {
	std::cout << p << std::endl;
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

	FragTrap a1;
	FragTrap b1("Even better Johnny");
	FragTrap c1 = b1;
	FragTrap d1("Even better Cookie");

	print_result(a1);
	print_result(b1);
	print_result(c1);
	print_result(d1);
	b1.attack("a freaking rock");
	b1.takeDamage(1);
	b1.beRepaired(12);
	for (int i = 0; i < 11; i++) {
		b1.attack("another freaking rock");
	}
	d1.attack("Moulinette");
	d1.takeDamage(42);
	print_result(a1);
	print_result(b1);
	print_result(c1);
	print_result(d1);
	a1.highFivesGuys();
	c1.highFivesGuys();
	d1.highFivesGuys();
	return 0;
}