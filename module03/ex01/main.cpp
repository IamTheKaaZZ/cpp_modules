/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 10:43:55 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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

	ScavTrap a1;
	ScavTrap b1("Better Johnny");
	ScavTrap c1 = b1;
	ScavTrap d1("Better Cookie");

	print_result(a1);
	print_result(b1);
	print_result(c1);
	print_result(d1);
	b1.attack("a freaking rock");
	b1.takeDamage(1);
	b1.beRepaired(12);
	b1.attack("another freaking rock");
	d1.attack("Moulinette");
	d1.takeDamage(42);
	print_result(a1);
	print_result(b1);
	print_result(c1);
	print_result(d1);
	a1.guardGate();
	c1.guardGate();
	d1 = c1;
	d1.guardGate();
	a1.guardGate();
	return 0;
}