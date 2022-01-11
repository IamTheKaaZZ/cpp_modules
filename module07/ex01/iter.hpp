/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:56:09 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/11 14:42:39 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template<typename T>
void    iter(T array[], size_t len, void (*funcPointer)(T&)) {
    for(size_t i = 0; i < len; i++) {
        funcPointer(array[i]);
    }
}

#endif