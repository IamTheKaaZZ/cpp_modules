/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:15:44 by bcosters          #+#    #+#             */
/*   Updated: 2022/04/25 12:05:26 by bcosters         ###   ########.fr       */
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
        typedef typename std::stack<T>::container_type::iterator stackIt;
		typedef typename std::reverse_iterator<stackIt> iterator;
        iterator    begin() { return std::reverse_iterator<stackIt>(this->c.end()); };
        iterator    end() { return std::reverse_iterator<stackIt>(this->c.begin()); };
    private:
};

template<class T>
std::ostream &      operator<<(std::ostream & o, MutantStack<T> & s) {
    o << "Size of this monstrosity is " << s.size() << endl;
    if (!s.empty())
        o << "The top element is " << s.top() << endl;
    return o;
}

#endif