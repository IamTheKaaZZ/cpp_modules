/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:48:26 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/12 11:34:39 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <string>
# include <sstream>

class NotFoundException : public std::exception {
    public:
        NotFoundException(int notFound) {
            _ss << "The number " << notFound << " cannot be found";
            _ss >> _msg;
        }
        virtual	const char*	what() const throw() {
            return _msg.c_str();
        }
    private:
        std::stringstream   _ss;
        std::string         _msg;
};

template<typename T>
typename T::const_iterator    easyfind(const T& c, const int toFind) {
    typename T::const_iterator  fIt = std::find(c.begin(), c.end(), toFind);
    if (fIt != c.end())
        return fIt;
    else throw NotFoundException(toFind);
}

#endif