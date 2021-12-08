/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:44:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 15:59:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("nothing", 145), _target("nothing")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	Form("ShrubberyCreation", 145),
	_target(target)
{
	std::cout << "Parameter ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	Form(src),
	_target(src._target)
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
		Bureaucrat::GradeTooLowException();
	}
	else {
		std::ofstream ofs(this->_target + "_shrubbery");
		srand((unsigned)time(NULL) * getpid());
		size_t	treeHeight = (rand() % 64) + 1;
		size_t	spaces = treeHeight - 2;
		for (int i = 0; i < (treeHeight - 2); i++) {
        for (int j = spaces; j > 0; j--)
        {
            ofs << BLANK;
        }
        for (int foliage = 0; foliage <= i * 2; foliage++)
        {
            ofs << LEAF;
        }
        spaces--;
        ofs << std::endl;
		size_t trunkLine = 1;
		while (trunkLine <= 2)  // for each line in the trunk
		{
			spaces = 1;

			while (spaces <= (treeHeight - 2))   //draw the spaces on the left
			{
				ofs << BLANK;
				spaces += 1;
			}

			ofs << WOOD;       //draw the trunk
			ofs << std::endl;  //go to next line
			trunkLine += 1;
		}
		ofs.close();
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */