/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:20:37 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/11 18:18:22 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "easyfind.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::for_each;

template<class T>
int getIndex(T& cont, typename T::iterator it) {
    typename T::iterator    bIt = cont.begin();
    int index = std::distance(bIt, it);
    return index;
}

void    printInt(int i) {
    cout << ' ' << i;
}

int main() {
    int ints[] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 6};
    vector<int>    v(ints, ints + sizeof(ints) / sizeof(int));
    list<int>      l(ints, ints + sizeof(ints) / sizeof(int));
    vector<int>::iterator  vIt;
    list<int>::iterator    lIt;

    cout << "The vector contains:";
    for_each(v.begin(), v.end(), printInt);
    cout << endl;
    vIt = easyfind(v, 3);
    cout << "Found the first occurance of 3 at index = " << getIndex(v, vIt) << endl;
    cout << "The list contains:";
    for_each(l.begin(), l.end(), printInt);
    cout << endl;
    lIt = easyfind(l, 3);
    cout << "Found the first occurance of 3 at index = " << getIndex(l, lIt) << endl;
}