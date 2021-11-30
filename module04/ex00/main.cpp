/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:07:27 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 13:05:06 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iomanip>

void	print_result(Animal const & p) {
	std::cout << p << std::endl;
}

void	print_result(WrongAnimal const & p) {
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
	WrongAnimal*	e = new WrongAnimal();
	WrongAnimal*	f = new WrongCat();
	WrongCat*		g = new WrongCat();
	print_result(*e);
	e->makeSound();
	print_result(*f);
	f->makeSound();
	print_result(*g);
	g->makeSound();

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	return 0;
}