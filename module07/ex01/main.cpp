/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:13:27 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/11 14:42:19 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <cstddef>
#include <string>

using std::string;
using std::toupper;
using std::cout;
using std::endl;

void    incrementNum(int& val) {
    static int  incr = 1;
    val += incr;
    incr++;
}

void    capitalize(string& str) {
    for(string::size_type i = 0; i < str.size(); i++) {
        str[i] = toupper(str[i]);
    }
}

template<typename T>
void    byteSize(T &val) {
    cout << "Size in bytes = " << sizeof(val) << endl;
}

int main() {
    int     intArray[20] = {0};
    string  strArray[2] = {"hello", "world"};

    for(size_t i = 0; i < 20; i++) {
        cout << "i = " << i << " -> " << intArray[i] << endl;
    }
    for(size_t i = 0; i < 2; i++) {
        cout << "i = " << i << " -> " << strArray[i] << endl;
    }
    iter(intArray, 20, &incrementNum);
    iter(strArray, 2, &capitalize);
    for(size_t i = 0; i < 20; i++) {
        cout << "i = " << i << " -> " << intArray[i] << endl;
    }
    for(size_t i = 0; i < 2; i++) {
        cout << "i = " << i << " -> " << strArray[i] << endl;
    }
    iter(intArray, 20, &byteSize);
    iter(strArray, 2, &byteSize);
    return 0;
}