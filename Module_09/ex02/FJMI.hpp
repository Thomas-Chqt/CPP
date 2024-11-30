/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:24:42 by tchoquet          #+#    #+#             */
/*   Updated: 2024/11/29 18:42:06 by tchoquet         ###   ########.fr       */
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
void mergeInsertSort(Container& container, IteratorGroup<typename Container::iterator> begin, IteratorGroup<typename Container::iterator> end)
{
    typedef IteratorGroup<typename Container::iterator> Iterator;

    typename Container::difference_type size = std::distance(begin, end);

    if (size <= 1)
        return;
    if (size == 2)
    {
        if (*begin > *end)
            std::iter_swap(begin, end);
        return;
    }

    if (size % 2 != 0)
        --end;

    for (Iterator it = begin; it != end; std::advance(it, 2))
    {
        if (*it < *(it + 1))
            std::iter_swap(begin, it + 1);
    }

    mergeInsertSort(container, makeIteratorGroup(begin, 2), makeIteratorGroup(begin, 2));
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
