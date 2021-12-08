/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:17:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/08 11:47:24 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{

	public:

		Bureaucrat(std::string const & name, int const & grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat &		operator++(void); //prefix
		Bureaucrat			operator++(int); //postfix
		Bureaucrat &		operator--(void); //prefix
		Bureaucrat			operator--(int); //postfix
		class GradeTooHighException : public std::exception {
			public:
				virtual	const char*	what() const throw() {
					return ("Bureaucrat grade is TOO DAMN HIGH!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual	const char*	what() const throw() {
					return ("Bureaucrat grade is TOO DAMN LOW!");
				}
		};
		std::string const &		getName() const;
		int const &				getGrade() const;

	private:

		Bureaucrat();
		std::string const		_name;
		int						_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */