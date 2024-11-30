/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:24:42 by tchoquet          #+#    #+#             */
/*   Updated: 2024/11/30 18:12:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJMI_HPP
# define FJMI_HPP

#include <iterator>
#include <algorithm>

#include "IteratorGroup.hpp"

typedef unsigned int uint32;

inline uint32 jacob(uint32 n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return jacob(n - 1) + 2 * jacob(n - 2);
}

template<typename Container>
void binaryInsert(Container& container, IteratorGroup<typename Container::iterator> insertEnd, IteratorGroup<typename Container::iterator> inserted)
{
    typedef typename Container::difference_type ContainerSize;
    assert(insertEnd.len == inserted.len);

    IteratorGroup<typename Container::iterator> containerBegin = begin(container, inserted.len);

    ContainerSize l = 0;
    ContainerSize h = std::distance(containerBegin, insertEnd);
    while (l < h)
    {
        ContainerSize m = (l + h) / 2;
        if (*(containerBegin + m) < *inserted)
            l = m + 1;
        if (*(containerBegin + m) > *inserted)
            h = m - 1;
        else
            insert(container, (containerBegin + m).head, inserted);
    }
    insert(container, (containerBegin + l).head, inserted);
}

template<typename Container>
void mergeInsertSort(Container& container, uint32 len = 1)
{
    typedef IteratorGroup<typename Container::iterator> Iterator;

    size_t size = container.size() / len;

    if (size <= 1)
        return;
    if (size == 2)
    {
        if (*begin(container, len) > *end(container, len))
            iter_swap(begin(container, len), end(container, len));
        return;
    }

    Container straggler;
    if (size % 2 != 0)
    {
        insert(straggler, straggler.end(), end(container, len) - 1);
        erase(container, end(container, len) - 1);
    }

    // for (Iterator it = begin(container, len); it != end(container, len); it += 2)
    // {
    //     if (*it < *(it + 1))
    //         iter_swap(it, it + 1);
    // }

    // mergeInsertSort(container, len * 2);

    Container main;
    Container pending;

    for (Iterator it = begin(container, len); it != end(container, len);)
    {
        insert(main, main.end(), it++);
        insert(pending, pending.end(), it++);
    }
    pending.insert(pending.end(), straggler.begin(), straggler.end());

    insert(main, main.begin(), begin(pending, len));
    erase(pending, begin(pending, len));
    for (uint32 i = 4; ; i++)
    {
        uint32 jacobDiff = jacob(i) - jacob(i - 1);
        if (jacobDiff >= pending.size())
            break;
        Iterator insert = begin(pending, len) + jacobDiff - 1;
        while (true)
        {
            Iterator insertEnd = begin(main, len) + jacob(i) - 1;
            binaryInsert(main, insertEnd, insert);
            insert = erase(pending, insert);
            if (insert.head == pending.begin())
                break;
            --insert;
        }
    }
    // while (pending.empty() == false)
    // {
    //     binaryInsert(main, makeIteratorGroup(main.end(), itLen), makeIteratorGroup(pending.begin(), itLen));
    //     erase(pending, makeIteratorGroup(pending.begin(), itLen));
    // }

    container = main;
}

#endif // FJMI_HPP
