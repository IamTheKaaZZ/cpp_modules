/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/07 16:54:38 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iomanip>

void	print_result(Animal const & p) {
	std::cout << p << std::endl;
}

int	main() {
	// Animal*	a = new Animal();
	// Animal*	b = new Animal("Chimera");
	Animal*	c = new Dog();
	Animal*	d = new Cat();
	print_result(*c);
	c->makeSound();
	print_result(*d);
	d->makeSound();
	std::cout << "Cat->printIdeas();" << std::endl;
	d->printIdeas();
	
	Animal*	animals[20];
	for (int i = 0; i < 20; i++) {
		std::cout << "Animal " << i << std::endl;
		if (i < 10) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}

	delete c;
	delete d;
	for (int i = 0; i < 20; i++) {
		delete animals[i];
	}
	Dog basic;
	Dog tmp = basic;
	return 0;
}