/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 17:28:29 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test1() {
	std::cout << "TEST1" << std::endl;
	Bureaucrat bob("Bobby", 1);
	Bureaucrat jess("Jessy", 150);
	Form* xmas = new ShrubberyCreationForm("Christmas tree");
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	std::cout << *xmas << std::endl;
	jess.signForm(*xmas);
	std::cout << *xmas << std::endl;
	bob.signForm(*xmas);
	std::cout << *xmas << std::endl;
	xmas->execute(bob);
	xmas->execute(jess);
	delete xmas;
}

void	test2() {
	std::cout << "TEST2" << std::endl;
	Bureaucrat bob("Bobby", 1);
	Bureaucrat jess("Jessy", 150);
	Form* robo = new RobotomyRequestForm("Your mom");
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	std::cout << *robo << std::endl;
	jess.signForm(*robo);
	std::cout << *robo << std::endl;
	bob.signForm(*robo);
	std::cout << *robo << std::endl;
	robo->execute(bob);
	robo->execute(jess);
	delete robo;
}

void	test3() {
	std::cout << "TEST3" << std::endl;
	Bureaucrat bob("Bobby", 1);
	Bureaucrat jess("Jessy", 150);
	Form* pres = new PresidentialPardonForm("Your mom");
	std::cout << bob << std::endl;
	std::cout << jess << std::endl;
	std::cout << *pres << std::endl;
	jess.signForm(*pres);
	std::cout << *pres << std::endl;
	bob.signForm(*pres);
	std::cout << *pres << std::endl;
	pres->execute(bob);
	pres->execute(jess);
	delete pres;
}

int	main() {
	try {
		test1();
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		test2();
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		test3();
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}