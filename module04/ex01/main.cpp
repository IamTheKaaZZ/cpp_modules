/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 12:27:18 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iomanip>

void	print_result(Animal const & p) {
	std::cout << p << std::endl;
}

int	main() {
	Animal*	a = new Animal();
	Animal*	b = new Animal("Chimera");
	Animal*	c = new Dog();
	Animal*	d = new Cat();
	print_result(*a);
	a->makeSound();
	print_result(*b);
	b->makeSound();
	print_result(*c);
	c->makeSound();
	print_result(*d);
	d->makeSound();
	std::cout << "Animal->printIdeas();" << std::endl;
	a->printIdeas();
	std::cout << "Cat->printIdeas();" << std::endl;
	d->printIdeas();
	Cat basic;
	Cat tmp;
	{
		tmp = basic;
	}

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

	delete a;
	delete b;
	delete c;
	delete d;
	for (int i = 0; i < 20; i++) {
		delete animals[i];
	}
	return 0;
}