/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorGroup.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:15:08 by tchoquet          #+#    #+#             */
/*   Updated: 2024/11/29 17:15:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORGROUP_HPP
# define ITERATORGROUP_HPP

#include <iterator>

typedef unsigned int uint32;

template<typename Iterator>
Iterator operator + (const Iterator& it, const uint32& n)
{
    Iterator ret = it;
    std::advance(ret, n);
    return ret;
}

template<typename Iterator>
Iterator operator - (const Iterator& it, const uint32& n)
{
    Iterator ret = it;
    std::advance(ret, -n);
    return ret;
}
 
template<typename Iterator>
struct IteratorGroup
{
public:
    typedef typename std::random_access_iterator_tag                 iterator_category;
    typedef typename std::iterator_traits<Iterator>::value_type      value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
    typedef typename std::iterator_traits<Iterator>::pointer         pointer;
    typedef typename std::iterator_traits<Iterator>::reference       reference;
    typedef Iterator                                                 iterator_type;

public:
    Iterator head;
    uint32 len;

    inline reference      operator  * ()    { return *head; }
    inline pointer        operator -> ()    { return &head; }

    inline IteratorGroup& operator ++ ()    { return std::advance(head,  len), *this; }
    inline IteratorGroup& operator -- ()    { return std::advance(head, -len), *this; }

    inline IteratorGroup  operator ++ (int) { IteratorGroup tmp = *this; operator++(); return tmp; }
    inline IteratorGroup  operator -- (int) { IteratorGroup tmp = *this; operator--(); return tmp; }
};

template<typename Iterator1, typename Iterator2>
inline bool operator == (const IteratorGroup<Iterator1>& lhs, const IteratorGroup<Iterator2>& rhs)
{
    return lhs.head == rhs.head;
}

template<typename Iterator1, typename Iterator2>
inline bool operator != (const IteratorGroup<Iterator1>& lhs, const IteratorGroup<Iterator2>& rhs)
{
    return lhs.head != rhs.head;
}

template<typename Iterator1, typename Iterator2>
inline bool operator  < (const IteratorGroup<Iterator1>& lhs, const IteratorGroup<Iterator2>& rhs)
{
    return lhs.head  < rhs.head;
}

template<typename Iterator1, typename Iterator2>
inline bool operator <= (const IteratorGroup<Iterator1>& lhs, const IteratorGroup<Iterator2>& rhs)
{
    return lhs.head <= rhs.head;
}

template<typename Iterator1, typename Iterator2>
inline bool operator  > (const IteratorGroup<Iterator1>& lhs, const IteratorGroup<Iterator2>& rhs)
{
    return lhs.head  > rhs.head;
}

template<typename Iterator1, typename Iterator2>
inline bool operator >= (const IteratorGroup<Iterator1>& lhs, const IteratorGroup<Iterator2>& rhs)
{
    return lhs.head >= rhs.head;
}

template<typename Iterator1, typename Iterator2>
inline void iter_swap(IteratorGroup<Iterator1> lhs, IteratorGroup<Iterator2> rhs)
{ 
    std::swap_ranges(lhs.head, lhs.head + lhs.len, rhs.head);
}

template<typename Iterator>
inline IteratorGroup<Iterator> makeIteratorGroup(Iterator it, std::size_t len)
{
    return (IteratorGroup<Iterator>){ it, len };
}

template<typename Iterator>
IteratorGroup<Iterator> makeIteratorGroup(IteratorGroup<Iterator> it, std::size_t len)
{
    return (IteratorGroup<Iterator>){ it.head, it.len * it.len };
}

#endif // ITERATORGROUP_HPP