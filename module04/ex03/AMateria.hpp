/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:16:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/07 16:26:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "Character.hpp"

class ICharacter;
class AMateria
{

	protected:

		std::string const		type;

	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );
		std::string const &		getType(void) const;
		virtual AMateria*		clone(void) const = 0;
		virtual void			use(ICharacter& target);

	private:

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

class	Ice : public AMateria
{
	public:

		Ice();
		Ice( Ice const & src );
		~Ice();

		Ice &		operator=( Ice const & rhs );
		std::string const &		getType(void) const;
		virtual AMateria*		clone(void) const;
		virtual void			use(ICharacter& target);

	private:

};

class	Cure : public AMateria
{
	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		Cure &		operator=( Cure const & rhs );
		std::string const &		getType(void) const;
		virtual AMateria*		clone(void) const;
		virtual void			use(ICharacter& target);

	private:

};

class	Fire : public AMateria
{
	public:

		Fire();
		Fire( Fire const & src );
		~Fire();

		Fire &		operator=( Fire const & rhs );
		std::string const &		getType(void) const;
		virtual AMateria*		clone(void) const;
		virtual void			use(ICharacter& target);

	private:

};

#endif /* ******************************************************** AMATERIA_H */