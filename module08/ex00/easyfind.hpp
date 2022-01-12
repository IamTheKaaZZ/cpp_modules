/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:48:26 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/12 14:59:20 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <string>

class NotFoundException : public std::exception {
    public:
        virtual const char*	what() const throw() {
            return ("The number cannot be found");
        }
};

template<typename T>
int getIndex(T& cont, typename T::const_iterator it) {
    typename T::const_iterator    bIt = cont.begin();
    int index = std::distance(bIt, it);
    return index;
}

template<typename T>
typename T::const_iterator    easyfind(const T& c, const int toFind) {
    typename T::const_iterator  fIt = std::find(c.begin(), c.end(), toFind);
    if (fIt != c.end())
        return fIt;
    else throw NotFoundException();
}

#endif