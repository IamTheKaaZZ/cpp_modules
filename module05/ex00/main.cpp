/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 12:48:58 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test1() {
	std::cout << "TEST1" << std::endl;
	Bureaucrat bob("Bobby", 1);
	Bureaucrat jess("Jessy", 150);
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	--bob;
	++jess;
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	bob++;
	jess--;
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	bob++;
	jess--;
}

void	test2() {
	std::cout << "TEST2" << std::endl;
	Bureaucrat john("Johnny", -1);
}

void	test3() {
	std::cout << "TEST3" << std::endl;
	Bureaucrat lazy("Lazy Louie", 999);
}

void	test4() {
	std::cout << "TEST4" << std::endl;
	throw 42;
}

int	main() {
	try {
		test1();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		//Catch-all
	}
	try {
		test2();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		//Catch-all
	}
	try {
		test3();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		//Catch-all
	}
	try {
		test4();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Threw a random exception" << std::endl;
	}
	return 0;
}