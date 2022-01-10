/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:42:47 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/10 16:14:31 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
inline void    swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
inline T const& min(T const& a, T const & b) {
    return ((a < b) ? a : b);
}

template<typename T>
inline T const& max(T const& a, T const & b) {
    return ((a > b) ? a : b);
}

#endif