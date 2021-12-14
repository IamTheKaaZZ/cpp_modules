/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:53:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/14 16:06:40 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public:

		Form();
		Form(std::string const & name, int const & required);
		Form( Form const & src );
		virtual ~Form();

		Form &		operator=( Form const & rhs );
		class GradeTooHighException : public std::exception {
			public:
				virtual	const char*	what() const throw() {
					return ("Required grade is too high (Out of bounds)!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual	const char*	what() const throw() {
					return ("Bureaucrat grade is too low to sign this form.");
				}
		};
		std::string const &		getName() const { return _name; }
		bool					isFormSigned() const { return _isSigned; }
		int const &				getGradeRequired() const { return _gradeRequired; }
		bool					beSigned(Bureaucrat const & b);
		virtual void			execute(Bureaucrat const & executor) const = 0;
		virtual std::ostream &	outputformat(std::ostream & o) const;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeRequired;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */