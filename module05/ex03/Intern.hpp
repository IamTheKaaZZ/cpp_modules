/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:33:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/14 16:27:30 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"


class Intern
{

	typedef Form*(Intern::*FP)(std::string const &);

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		struct s_make {
			std::string name;
			FP			fp;
			s_make() {};
			s_make(std::string const & name, FP fp) : name(name) {
				this->fp = fp;
			};
		};

		Intern &		operator=( Intern const & rhs );
		Form*			makeForm(std::string const & name, std::string const & target);

	private:

		s_make			_makeTable[3];
		Form*			_makeSC(std::string const & target);
		Form*			_makeRR(std::string const & target);
		Form*			_makePP(std::string const & target);

};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */