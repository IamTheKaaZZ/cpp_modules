/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:32:01 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 13:01:09 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal(std::string type);
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );
		virtual void		makeSound(void) const;
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
		~Dog();

		Dog &		operator=( Dog const & rhs );
		virtual void		makeSound(void) const;

};

class Cat : public Animal
{
	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &		operator=( Cat const & rhs );
		virtual void		makeSound(void) const;

};

#endif /* ********************************************************** ANIMAL_H */