/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:30:16 by bcosters          #+#    #+#             */
/*   Updated: 2021/12/20 16:05:54 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cmath>

class Base
{

	public:

		Base();
		Base( Base const & src );
		virtual ~Base();

		Base &		operator=( Base const & rhs );

	private:

};

class A : public Base {
	public:
		A() { std::cout << "A" << std::endl; };
		A(A const & src) {*this = src;};
		~A() {};
};

class B : public Base {
	public:
		B() { std::cout << "B" << std::endl; };
		B(B const & src) {*this = src;};
		~B() {};
};

class C : public Base {
	public:
		C() { std::cout << "C" << std::endl; };
		C(C const & src) {*this = src;};
		~C() {};
};

Base*		generate(void);
void		identify(Base* p);
void		identify(Base& p);

#endif /* ************************************************************ BASE_H */