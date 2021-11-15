/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/15 15:14:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	*john = newZombie("Johnny");
	Zombie	*leslie = newZombie("Leslie");
	john->announce();
	leslie->announce();
	randomChump("Carl");
	randomChump("Karen");
	delete john;
	delete leslie;
	return 0;
}