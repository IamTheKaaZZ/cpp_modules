/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 14:37:08 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test1() {
	std::cout << "TEST1" << std::endl;
	Bureaucrat bob("Bobby", 1);
	Bureaucrat jess("Jessy", 150);
	Form moul("new moulinette proposal", 42);
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	std::cout << moul << std::endl;
	--bob;
	++jess;
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	bob++;
	jess--;
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	jess.signForm(moul);
	std::cout << moul << std::endl;
	bob.signForm(moul);
	std::cout << moul << std::endl;
}

void	test2() {
	std::cout << "TEST2" << std::endl;
	Form norm("new norm", -42);
}

void	test3() {
	std::cout << "TEST3" << std::endl;
	Form lazy("Lazy Louie", 999);
}

int	main() {
	test1();
	try {
		test2();
	}
	catch (Form::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		test3();
	}
	catch (Form::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}