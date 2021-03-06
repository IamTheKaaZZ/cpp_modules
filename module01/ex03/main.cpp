/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/10 15:25:25 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void) {
	Weapon	kitchen = Weapon("ladle");
	HumanA	bobby = HumanA("bobby", kitchen);
	bobby.attack();
	kitchen.setType("golden spoon of cake smiting!");
	bobby.attack();

	HumanB	Johnny = HumanB("Johnny");
	Johnny.attack();
	kitchen.setType("fork, the other philosophers realise they are in the wrong project.");
	Johnny.setWeapon(kitchen);
	Johnny.attack();
	kitchen.setType("knife, stabby stabby.");
	Johnny.attack();
}