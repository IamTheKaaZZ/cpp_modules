/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:49:59 by bcosters          #+#    #+#             */
/*   Updated: 2021/11/30 13:02:37 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );
		void				makeSound(void) const;
		std::string			getType(void) const;

	protected:

		std::string	_type;


	private:

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

class WrongCat : public WrongAnimal
{
	public:

		WrongCat();
		WrongCat( WrongCat const & src );
		~WrongCat();

		WrongCat &		operator=( WrongCat const & rhs );
		void			makeSound(void) const;

};

#endif /* ***************************************************** WRONGANIMAL_H */