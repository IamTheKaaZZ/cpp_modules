/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:45:36 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/11 15:56:30 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>
# include <iostream>
# include <iomanip>
# include <ostream>
# include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::exception;

template<typename T>
class Array {

    public:
        Array() : _size(1), _elements(new T()) {
            cout << "Default constructor called" << endl;
        };
        Array(unsigned int n) :
            _size(n),
            _elements(new T[n]) {
                cout << "Parameter constructor called" << endl;
            };
        Array(Array const& src) :
            _size(src._size),
            _elements(new T[src._size]) {
                cout << "Copy constructor called" << endl;
                for(size_t i = 0; i < _size; i++) {
                    _elements[i] = src._elements[i];
                }
        };
        ~Array() {
            cout << "Destructor called" << endl;
            delete [] _elements;
        };

        Array&  operator=(Array const& rhs) {
            if (this != &rhs) {
                delete [] this->_elements;
                this->_size = rhs._size;
                this->_elements = new T[_size];
                for(size_t i = 0; i < _size; i++) {
                    this->_elements[i] = rhs._elements[i];
                }
            }
            return *this;
        };
        T&     operator[](size_t index) const {
            if (index < 0 || index > _size - 1) {
                throw exception();
            }
            else {
                return _elements[index];
            }
        };
        size_t  size() const { return _size; };

    private:
        size_t  _size;
        T*      _elements;
};

template<typename T>
ostream&   operator<<(ostream& o, Array<T> const & a) {
    o << "Size of the array = " << a.size() << endl;
    o << "Elements of the array:" << endl;
    for(size_t i = 0; i < a.size(); i++) {
        o << "i = " << i << " -> " << a[i] << endl;
    }
    return o;
}

#endif