/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:42:47 by bcosters          #+#    #+#             */
/*   Updated: 2022/04/22 17:52:36 by bcosters         ###   ########.fr       */
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

// In linux this causes an amniguity when the functions are lowercase
template<typename T>
inline T const& Min(T const& a, T const & b) {
    return ((a < b) ? a : b);
}

template<typename T>
inline T const& Max(T const& a, T const & b) {
    return ((a > b) ? a : b);
}

#endif