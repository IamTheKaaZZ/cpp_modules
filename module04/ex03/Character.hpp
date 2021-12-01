/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:17:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/01 17:02:32 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class ICharacter
{
	public:
		
		virtual ~ICharacter();
		virtual	std::string const &		getName() const = 0;
		virtual	void					equip(AMateria* m) = 0;
		virtual	void					unequip(int idx) = 0;
		virtual void					use(int idx, ICharacter& target) = 0;
};
class Character : public ICharacter
{

	public:

		Character();
		Character(std::string const & name);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );
		virtual	std::string const &		getName() const;
		virtual	void					equip(AMateria* m);
		virtual	void					unequip(int idx);
		virtual void					use(int idx, ICharacter& target);

	private:

		std::string const &			_name;
		AMateria*					_inventory[4];

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */