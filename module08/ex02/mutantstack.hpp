/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:15:44 by bcosters          #+#    #+#             */
/*   Updated: 2022/02/14 12:27:21 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP 
# define MUTANTSTACK_HPP 

# include <deque>
# include <iostream>
# include <string>
# include <iterator>
# include <stack>

using std::clog;
using std::endl;

template<class T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {
            clog << "Default Constructor called" << endl;
        };
        MutantStack(MutantStack const & src) : std::stack<T>(src) {
            clog << "Copy Constructor called" << endl;
        };
        ~MutantStack() {
            clog << "Destructor called" << endl;
        };
        MutantStack &  operator=(MutantStack const & rhs) {
            if (this != &rhs) {
                using std::stack<T>::operator=;
            }
            return *this;
        };
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin() { return this->c.begin(); };
        iterator    end() { return this->c.end(); };
    private:
};

template<class T>
std::ostream &      operator<<(std::ostream & o, MutantStack<T> & s) {
    o << "Size of this monstrosity is " << s.size() << endl;
    if (!s.empty())
        o << "The top element is " << s.top() << endl;
    return o;
}

// template <class ADAPTER>
// typename ADAPTER::container_type & get_container (ADAPTER &a)
// {
//     struct hack : ADAPTER {
//         static typename ADAPTER::container_type & get (ADAPTER &a) {
//             return a.*&hack::c;
//         }
//     };
//     return hack::get(a);
// }

// class iterator : public std::stack<T>::container_type::iterator {
//         typedef std::ptrdiff_t  difference_type;
//         typedef T               value_type;
//         typedef T*              pointer;
//         typedef T&              reference;
//     public:
//         //C++11 FeelsBadMan
//         //https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
//         // using iterator_category = std::forward_iterator_tag;
//         //difference_type
//         //A signed integer type that can be used to identify distance between iterator steps.
//         //Our iterator is basically a wrapper around a pointer and leverages pointer arithmetic
//         //So the default std::ptrdiff_t is a good choice
//         // using difference_type   = std::ptrdiff_t;
//         // using value_type        = T;    //the type the iterator iterates over
//         // using pointer           = T*;   // or also value_type*
//         // using reference         = T&;   // or also value_type&
//         iterator() : _mptr(NULL) {};
//         iterator(pointer ptr) : _mptr(ptr) {};
//         iterator(iterator const & src) : _mptr(src._mptr) {};
//         ~iterator() {};
//         iterator&   operator=(iterator const & rhs) {
//             if (this != &rhs) {
//                 this->_mptr = rhs._mptr;
//             }
//             return *this;
//         }
//         reference   operator*() const { return *_mptr; };
//         pointer     operator->() { return _mptr; };
//         iterator&   operator++() { //Prefix
//             _mptr++;
//             return *this;
//         }
//         iterator    operator++(int) { //Postfix
//             iterator    tmp = *this;
//             ++(*this);
//             return tmp;
//         }
//         iterator&   operator+(typename std::stack<T>::size_type const & s) {
//             typename std::stack<T>::size_type   temp = s;
//             while (temp--) this->operator++();
//             return *this;
//         }
//         //Next ones should both have friend
//         //So they are non-member but CAN access the private pointer
//         //AND can be put inside the nested class
//         //Link: 
//         //https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421729#4421729
//         bool        operator==(iterator const & rhs) const {
//             return (this->_mptr == rhs._mptr);
//         }
//         bool        operator!=(iterator const & rhs) const {
//             return (this->_mptr != rhs._mptr);
//         }
//     private:
//         pointer _mptr;
// };

#endif