/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:32:01 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/21 12:30:27 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{

	public:

		Animal();
		Animal(std::string type);
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );
		virtual void		makeSound(void) const = 0;
		virtual void		printIdeas(void) const;
		std::string			getType(void) const;

	protected:

		std::string	_type;

	private:

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

class Dog : public Animal
{
	public:

		Dog();
		Dog( Dog const & src );
		virtual ~Dog();

		Dog &		operator=( Dog const & rhs );
		virtual void		makeSound(void) const;
		virtual void		printIdeas(void) const;
	
	private:

		Brain*	_brain;

};

class Cat : public Animal
{
	public:

		Cat();
		Cat( Cat const & src );
		virtual ~Cat();

		Cat &		operator=( Cat const & rhs );
		virtual void		makeSound(void) const;
		virtual void		printIdeas(void) const;

	private:

		Brain*	_brain;

};

#endif /* ********************************************************** ANIMAL_H */