/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:48:26 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/11 18:31:15 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFoundException : public std::exception {
    public:
        virtual	const char*	what() const throw() {
            return ("The int cannot be found.");
        }
};

template<typename T>
typename T::iterator  easyfind(T& c, int toFind) {
    typename T::iterator  fIt = std::find_first_of(c.begin(), c.end(), toFind, toFind);
    if (fIt != c.end())
        return fIt;
    else throw NotFoundException();
}

#endif