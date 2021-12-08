/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:44:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 16:06:53 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"
# include <ctime>
# include <unistd.h>

class Form;

class ShrubberyCreationForm : public Form
{

		char const BLANK = ' ';
		char const LEAF = '#';
		char const WOOD = '|';

	public:

		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		virtual void				execute(Bureaucrat const & executor) const;
		std::string const &			getTarget() const { return _target; }
		virtual std::ostream &		outputformat(std::ostream & o) const;

	private:

		ShrubberyCreationForm();
		std::string const		_target;
		int const				_execGrade = 137;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */