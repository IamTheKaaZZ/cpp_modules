/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:15:44 by bcosters          #+#    #+#             */
/*   Updated: 2022/01/12 18:41:15 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP 
# define MUTANTSTACK_HPP 

# include <iostream>
# include <string>
# include <iterator>
# include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T> {

    public:
        MutantStack();
        MutantStack(MutantStack const & src);
        ~MutantStack();
        MutantStack &  operator=(MutantStack const & rhs);
        struct iterator {
                using iterator_category = std::forward_iterator_tag;
                using difference_type   = std::ptrdiff_t;
                using value_type        = T;
                using pointer           = T*;  // or also value_type*
                using reference         = T&;  // or also value_type&
                iterator(pointer ptr) : _mptr(ptr) {};
            private:
                pointer _mptr;
        };
        
    private:
        
};

template<class T, class Container = std::deque<T> >
std::ostream &      operator<<(std::ostream & o, MutantStack<T> & s);

#endif