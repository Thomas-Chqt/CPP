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
#include <algorithm>

typedef unsigned int uint32;

template<typename Iterator>
struct IteratorGroup
{
    typedef typename std::iterator_traits<Iterator>::difference_type difference_type ;
    typedef typename std::iterator_traits<Iterator>::value_type value_type ;
    typedef typename std::iterator_traits<Iterator>::pointer pointer ;
    typedef typename std::iterator_traits<Iterator>::reference reference ;
    typedef std::bidirectional_iterator_tag iterator_category;

    Iterator head;
    uint32 len;

    IteratorGroup() {}
    IteratorGroup(Iterator h, uint32 l) : head(h), len(l) {}

    inline reference operator  * () { return head.operator*(); }
    inline pointer operator -> () { return head.operator->(); }

    IteratorGroup& operator += (int n)
    {
        for (uint32 i = 0; i < n * len; i++)
            ++head;
        return *this;
    }

    IteratorGroup& operator -= (int n)
    {
        for (uint32 i = 0; i < n * len; i++)
            --head;
        return *this;
    }

    inline IteratorGroup& operator ++ () { return operator+=(1); }
    inline IteratorGroup& operator -- () { return operator-=(1); }
    
    inline IteratorGroup  operator ++ (int) { IteratorGroup tmp = *this; operator++(); return tmp; }
    inline IteratorGroup  operator -- (int) { IteratorGroup tmp = *this; operator--(); return tmp; }

    inline bool operator == (const IteratorGroup& rhs) const { return head == rhs.head; }
    inline bool operator != (const IteratorGroup& rhs) const { return head != rhs.head; }
};

template<typename Iterator>
IteratorGroup<Iterator> operator + (const IteratorGroup<Iterator>& it, uint32 n)
{
    IteratorGroup<Iterator> ret = it;
    ret += n;
    return ret;
}

template<typename Iterator>
IteratorGroup<Iterator> operator - (const IteratorGroup<Iterator>& it, uint32 n)
{
    IteratorGroup<Iterator> ret = it;
    ret -= n;
    return ret;
}

template<typename Iterator>
inline IteratorGroup<Iterator> makeIteratorGroup(Iterator it, std::size_t len = 1)
{
    return IteratorGroup<Iterator>(it, len);
}

template<typename Iterator>
IteratorGroup<Iterator> makeIteratorGroup(IteratorGroup<Iterator> it, std::size_t len = 1)
{
    return IteratorGroup<Iterator>(it.head, it.len * len);
}

template<typename Iterator>
inline void iter_swap(IteratorGroup<Iterator> lhs, IteratorGroup<Iterator> rhs)
{
    Iterator rangeEnd = lhs.head;
    for (size_t i = 0; i < lhs.len; i++)
        ++rangeEnd;
    std::swap_ranges(lhs.head, rangeEnd, rhs.head);
}

template<typename Container>
IteratorGroup<typename Container::iterator> erase(Container& container, const IteratorGroup<typename Container::iterator>& it)
{
    typename Container::iterator eraseBegin = it.head;
    typename Container::iterator eraseEnd = it.head;
    for (uint32 i = 0; i < it.len; i++)
        ++eraseEnd;

    typename Container::iterator eraseRet = container.erase(eraseBegin, eraseEnd);
    return IteratorGroup<typename Container::iterator>(eraseRet, it.len);
}

template<typename Container, typename Iterator>
void insert(Container& container, typename Container::iterator pos, const IteratorGroup<Iterator>& it)
{
    Iterator insertBegin = it.head;
    Iterator insertEnd = it.head;
    for (uint32 i = 0; i < it.len; i++)
        ++insertEnd;
    container.insert(pos, insertBegin, insertEnd);
}

#endif // ITERATORGROUP_HPP
