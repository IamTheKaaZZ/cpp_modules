/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:54:43 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/11 16:19:35 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <exception>
#include <iostream>
#include "Array.hpp"

using std::cout;
using std::endl;

int main() {
    int*    a = new int();
    cout << *a << endl;
    Array<int>  b;
    Array<int>  c(20);
    Array<int>  d(c);
    cout << b;
    cout << c;
    cout << d;
    static int incr = 0;
    for(size_t i = 0; i < c.size(); i++) {
        c[i] += incr++;
    }
    cout << c;
    cout << d;
    d = b;
    b[0] = 5;
    cout << d;
    cout << b;
    try {
        cout << c[-1];
    }
    catch (std::exception & e) {
        cout << e.what() << endl;
    }
    try {
        cout << b[5];
    }
    catch (std::exception & e) {
        cout << e.what() << endl;
    }
    return 0;
}