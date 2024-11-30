/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:24:42 by tchoquet          #+#    #+#             */
/*   Updated: 2024/11/30 17:20:11 by tchoquet         ###   ########.fr       */
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

#if 0
template<typename Container>
void binaryInsert(Container& container, const typename Container::iterator begin, const typename Container::iterator end, uint32 elementSize, const typename Container::iterator element)
{
    typename Container::size_type size = std::distance(begin, end) / elementSize;
    if (size <= 1)
    {
        if (size == 0 || *element <= *begin)
            container.insert(begin, element, element + elementSize);
        else
            container.insert(end, element, element + elementSize);
        return;
    }

    if (*element < *(begin + (size / 2) * elementSize))
        return binaryInsert(container, begin, end - (size / 2) * elementSize, elementSize, element);

    return binaryInsert(container, begin + (size / 2) * elementSize, end, elementSize, element);
}
#endif

template<typename Container>
void binaryInsert(Container& container, IteratorGroup<typename Container::iterator> insertEnd, IteratorGroup<typename Container::iterator> inserted)
{
    typedef typename Container::difference_type ContainerSize;
    assert(insertEnd.len == inserted.len);

    IteratorGroup<typename Container::iterator> containerBegin(container.begin(), inserted.len);

    ContainerSize l = 0;
    ContainerSize h = std::distance(containerBegin, insertEnd);
    while (l <= h)
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
void mergeInsertSort(Container& container, IteratorGroup<typename Container::iterator> begin, IteratorGroup<typename Container::iterator> end)
{
    typedef IteratorGroup<typename Container::iterator> Iterator;
    typedef typename Container::difference_type ContainerSize;

    assert(begin.len == end.len);
    uint32 itLen = begin.len;

    ContainerSize size = std::distance(begin, end);

    if (size <= 1)
        return;
    if (size == 2)
    {
        if (*begin > *end)
            std::iter_swap(begin, end);
        return;
    }

    Container straggler;
    if (size % 2 != 0)
        --end;

    for (Iterator it = begin; it != end; std::advance(it, 2))
    {
        if (*it < *(it + 1))
            iter_swap(it, it + 1);
    }

    mergeInsertSort(container, makeIteratorGroup(begin, 2), makeIteratorGroup(end, 2));

    Container main;
    Container pending;

    for (Iterator it = begin; it != end;)
    {
        insert(main, main.end(), it++);
        insert(pending, pending.end(), it++);
    }
    if (size % 2 != 0)
        insert(pending, pending.end(), end);

    for (uint32 i = 3; ; i++)
    {
        uint32 dist = jacob(i) - jacob(i - 1);
        if (dist >= pending.size())
            break;
        Iterator insert = makeIteratorGroup(pending.begin(), itLen) + dist;
        while (true)
        {
            Iterator insertEnd = makeIteratorGroup(main.begin(), itLen) + dist;
            binaryInsert(main, insertEnd, insert);
            insert = erase(pending, insert);
            if (insert.head == pending.begin())
                break;
            --insert;
        }
    }
    while (pending.empty() == false)
    {
        binaryInsert(main, makeIteratorGroup(main.end(), itLen), makeIteratorGroup(pending.begin(), itLen));
        erase(pending, makeIteratorGroup(pending.begin(), itLen));
    }

    container = main;
}

#if 0
template<typename Container>
void mergeInsertSort(Container& container, uint32 elementSize = 1)
{
    typedef typename Container::iterator Iterator;

    Container straggler;

    if ((container.size() / elementSize) <= 1 || ((container.size() / elementSize) == 2 && container.front() < *(container.begin() + elementSize)))
        return;

    if ((container.size() / elementSize) == 2)
    {
        swap_iterator_range(container.begin(), container.begin() + elementSize, elementSize);
        return;
    }

    if ((container.size() / elementSize) % 2 != 0)
    {
        straggler = Container(container.end() - elementSize, container.end());
        container.erase(container.end() - elementSize, container.end());
    }

    for (Iterator it = container.begin(); it != container.end(); it += elementSize * 2)
    {
        if (*it < *(it + elementSize))
            swap_iterator_range(it, it + elementSize, elementSize);
    }

    mergeInsertSort(container, elementSize * 2);

    Container pending;

    for (Iterator it = container.begin(); it != container.end();)
    {
        pending.insert(pending.end(), it + elementSize, it + elementSize * 2);
        it = container.erase(it + elementSize, it + elementSize * 2);
    }
    pending.insert(pending.end(), straggler.begin(), straggler.end());

    Iterator insertEnd = container.begin();
    for (uint32 i = 3; ; i++)
    {
        uint32 dist = jacob(i) - jacob(i - 1);
        if (dist >= pending.size())
            break;
        Iterator inserted = pending.begin() + elementSize * dist;
        while (true)
        {
            binaryInsert(container, container.begin(), insertEnd, elementSize, inserted);
            bool shouldBreak = inserted == pending.begin();
            pending.erase(inserted, inserted + elementSize);
            if (shouldBreak)
                break;
            inserted -= elementSize;
            insertEnd += elementSize;
        }
    }
    while (pending.empty() == false)
    {
        binaryInsert(container, container.begin(), insertEnd, elementSize, pending.begin());
        pending.erase(pending.begin(), pending.begin() + elementSize);
        insertEnd += elementSize;
    }
}
#endif

#endif // FJMI_HPP
