/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 11:31:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

void	print_result(DiamondTrap const & p) {
	std::cout << p << std::endl;
}

int	main() {
	DiamondTrap	d(" SUPREME OVERLORD ");
	d.whoAmI();
	print_result(d);
	d.attack("Moulinette");
	d.takeDamage(42);
	d.beRepaired(13);
	d.guardGate();
	d.guardGate();
	print_result(d);
	// DiamondTrap::ScavTrap sc;
	// print_result(sc);
	return 0;
}