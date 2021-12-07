/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/07 16:03:32 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iomanip>

int	main() {
	Character a("Dee's Nuts");
	Character k("Gottem");
	std::cout << a << std::endl;
	AMateria*	b = new Cure();
	AMateria*	c = new Ice();
	AMateria*	d = c;
	a.equip(b);
	a.equip(c);
	a.equip(d);
	std::cout << a << std::endl;
	a.use(3, k);
	a.use(2, k);
	a.unequip(0);
	std::cout << a << std::endl;
	return 0;
}