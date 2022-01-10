/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:00:43 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/10 16:52:09 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(){
    int a = 1;
    int b = 2;
    float   c = 2.5f;
    float   d = 3.33f;
    std::string  s1 = "Hello";
    std::string  s2 = "World";

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    swap(a,b);
    swap(c,d);
    swap(s1,s2);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "min(a,b) = " << Min(a,b) << endl; 
    cout << "min(c,d) = " << Min(c,d) << endl; 
    cout << "min(s1,s2) = " << Min(s1,s2) << endl; 
    cout << "max(a,b) = " << Max(a,b) << endl; 
    cout << "max(c,d) = " << Max(c,d) << endl; 
    cout << "max(s1,s2) = " << Max(s1,s2) << endl; 
}