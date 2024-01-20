/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:32:10 by tchoquet          #+#    #+#             */
/*   Updated: 2024/01/14 18:36:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

// template<typename value_type>
// class MutantStack
// {
// public:
//     typedef typename std::vector<value_type>                container_type;
//     typedef typename std::stack<value_type, container_type> stack_type;
//     typedef typename stack_type::size_type                  size_type;
    
//     typedef          value_type*                            iterator;
//     typedef          value_type* const                      const_iterator;

//     MutantStack() {}
//     MutantStack(const MutantStack& cp) { (void)cp; }

//     inline bool              empty()                     const { return m_stack.empty();   }
//     inline size_type         size()                      const { return m_stack.size();    }
//     inline value_type&       top()                             { return m_stack.top();     }
//     inline const value_type& top()                       const { return m_stack.top();     }
//     inline void              push(const value_type& val)       { return m_stack.push(val); }
//     inline void              pop()                             { return m_stack.pop();     }

//     inline       iterator begin()       { return       (iterator)(end() - size()); }
//     inline const_iterator begin() const { return (const_iterator)(end() - size()); }

//     inline       iterator end()       { return       (iterator)(&top() + 1); }
//     inline const_iterator end() const { return (const_iterator)(&top() + 1); } 
    
//     ~MutantStack() {}

// private:
//     stack_type m_stack;

// public:
//     MutantStack& operator=(const MutantStack& rhs)
//     {
//         if (&rhs != this)
//             m_stack = rhs.m_stack;
//         return *this;
//     }
// };

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef          T                                   value_type;
    typedef          Container                           container_type;
    typedef typename std::stack<T, Container>::size_type size_type;

    typedef typename container_type::iterator       iterator;
    typedef typename container_type::const_iterator const_iterator;

    MutantStack()                      : std::stack<value_type, container_type>() {}
    MutantStack(const MutantStack& cp) : std::stack<value_type, container_type>(cp) {}

    inline       iterator begin()       { return std::stack<value_type, container_type>::c.begin(); }
    inline const_iterator begin() const { return std::stack<value_type, container_type>::c.begin(); }
    inline       iterator end()         { return std::stack<value_type, container_type>::c.end(); }
    inline const_iterator end()   const { return std::stack<value_type, container_type>::c.end(); } 
    
    ~MutantStack() {}
};

#endif // MUTANTSTACK_HPP