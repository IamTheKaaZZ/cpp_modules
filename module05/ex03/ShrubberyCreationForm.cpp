/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:44:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/13 17:51:00 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreation", 145), _target("nothing"), _execGrade(137)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	Form("ShrubberyCreation", 145),
	_target(target),
	_execGrade(137)
{
	std::cout << "Parameter ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	Form(src),
	_target(src._target),
	_execGrade(137)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	return i.outputformat(o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::ostream &			ShrubberyCreationForm::outputformat(std::ostream & o) const {
	Form::outputformat(o);
	o << "Target is " << this->getTarget() << " and needs a grade of " << this->_execGrade << " to be executed.";
	return o;
}

void					ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->_execGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->isFormSigned()) {
		std::ofstream ofs(this->_target + "_shrubbery");
		char const BLANK = ' ';
		char const LEAF = '#';
		char const BAUBLE = '@';
		char const WOOD = '|';
		srand((unsigned)time(NULL) * getpid());
		size_t	treeHeight = (rand() % 64) + 1;
		size_t	spaces = treeHeight - 2;
		for (size_t i = 0; i < (treeHeight - 2); i++) {
        	for (size_t j = spaces; j > 0; j--) {
            	ofs << BLANK;
        	}
        	for (size_t foliage = 0; foliage <= i * 2; foliage++) {
				bool decor = (rand() % 4) != 0;
				if (!decor)
					ofs << BAUBLE;
				else
            		ofs << LEAF;
        	}
        	spaces--;
        	ofs << std::endl;
		}
		size_t trunkLine = 1;
		while (trunkLine <= treeHeight / 4)  // for each line in the trunk
		{
			spaces = 1;

			while (spaces <= (treeHeight - 4))   //draw the spaces on the left
			{
				ofs << BLANK;
				spaces += 1;
			}
			ofs << WOOD;       //draw the trunk
			ofs << WOOD;       //draw the trunk
			ofs << WOOD;       //draw the trunk
			ofs << std::endl;  //go to next line
			trunkLine += 1;
		}
		ofs.close();
    }
	else {
		std::cout << "Form has NOT been signed and cannot be executed" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */