/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:36:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/16 11:48:38 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	Horde = new Zombie[N];
	std::stringstream	ss;
	for (int i = 0; i < N; i++) {
		ss << name << i;
		Horde[i].setName(ss.str());
		ss.str(std::string());
	}
	return Horde;
}