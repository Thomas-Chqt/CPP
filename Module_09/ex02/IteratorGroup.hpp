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
#include <type_traits>

typedef unsigned int uint32;

template<typename Iterator>
struct IteratorGroup
{
    static_assert(
        std::is_base_of<std::bidirectional_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value,
        "Iterator must be at least bidirectional"
    );

    typedef typename std::iterator_traits<Iterator>::difference_type difference_type ;
    typedef typename std::iterator_traits<Iterator>::value_type value_type ;
    typedef typename std::iterator_traits<Iterator>::pointer pointer ;
    typedef typename std::iterator_traits<Iterator>::reference reference ;
    typedef std::bidirectional_iterator_tag iterator_category;

    Iterator head;
    uint32 len;

    IteratorGroup(Iterator h, uint32 l) : head(h), len(l) {}

    inline reference operator  * () { return head.operator*(); }
    inline pointer operator -> () { return head.operator->(); }

    inline IteratorGroup& operator ++ () { return std::advance(head,  len), *this; }
    inline IteratorGroup& operator -- () { return std::advance(head, -len), *this; }

    inline IteratorGroup  operator ++ (int) { IteratorGroup tmp = *this; operator++(); return tmp; }
    inline IteratorGroup  operator -- (int) { IteratorGroup tmp = *this; operator--(); return tmp; }

    inline bool operator == (const IteratorGroup& rhs) const { return head == rhs.head; }
    inline bool operator != (const IteratorGroup& rhs) const { return head != rhs.head; }
};

template<typename Iterator>
IteratorGroup<Iterator> operator + (const IteratorGroup<Iterator>& it, uint32 n)
{
    IteratorGroup<Iterator> ret = it;
    std::advance(ret, n);
    return ret;
}

template<typename Iterator>
IteratorGroup<Iterator> operator - (const IteratorGroup<Iterator>& it, uint32 n)
{
    IteratorGroup<Iterator> ret = it;
    std::advance(ret, -n);
    return ret;
}

template<typename Iterator1, typename Iterator2>
inline void iter_swap(IteratorGroup<Iterator1> lhs, IteratorGroup<Iterator2> rhs)
{
    std::swap_ranges(lhs.head, lhs.head + lhs.len, rhs.head);
}

template<typename Iterator>
inline IteratorGroup<Iterator> makeIteratorGroup(Iterator it, std::size_t len = 1)
{
    return IteratorGroup<Iterator>(it, len);
}

template<typename Iterator>
IteratorGroup<Iterator> makeIteratorGroup(IteratorGroup<Iterator> it, std::size_t len = 1)
{
    return IteratorGroup<Iterator>(it.head, it.len * it.len);
}

#endif // ITERATORGROUP_HPP
