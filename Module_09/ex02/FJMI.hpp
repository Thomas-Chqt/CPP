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
    while (l <= h)
    {
        ContainerSize m = (l + h) / 2;
        if (*(containerBegin + m) < *inserted)
            l = m + 1;
        else if (*(containerBegin + m) > *inserted)
            h = m - 1;
        else
        {
            insert(container, (containerBegin + m).head, inserted);
            return;
        }
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
        if (*begin(container, len) > *--end(container, len))
            iter_swap(begin(container, len), --end(container, len));
        return;
    }

    Container straggler;
    if (size % 2 != 0)
    {
        insert(straggler, straggler.end(), --end(container, len));
        erase(container, end(container, len) - 1);
    }

    for (Iterator it = begin(container, len); it != end(container, len); it += 2)
    {
        if (*it < *(it + 1))
            iter_swap(it, it + 1);
    }

    mergeInsertSort(container, len * 2);

    Container main;
    Container pending;

    for (Iterator it = begin(container, len); it != end(container, len);)
    {
        insert(main, main.end(), it++);
        insert(pending, pending.end(), it++);
    }

    uint32 insertRange = 0;
    uint32 insertedRange = 1;

    insert(main, main.begin(), begin(pending, len));
    erase(pending, begin(pending, len));

    for (uint32 i = 4; pending.empty() == false; i++)
    {
        uint32 jacobDiff = jacob(i) - jacob(i - 1);
        insertRange += insertedRange + jacobDiff;
        insertedRange = jacobDiff;

        if (insertRange > (main.size() / len))
            insertRange = (main.size() / len);

        Iterator inserted;
        if (jacobDiff >= (pending.size() / len))
            inserted = end(pending, len) - 1;
        else
            inserted = begin(pending, len) + (insertedRange - 1);

        while (true)
        {
            Iterator insertEnd = begin(main, len) + (insertRange - 1);
            binaryInsert(main, insertEnd, inserted);
            inserted = erase(pending, inserted);
            if (inserted.head == pending.begin())
                break;
            --inserted;
        }
    }
    if (straggler.empty() == false)
        binaryInsert(main, --end(main, len), begin(straggler, len));

    container = main;
}

#endif // FJMI_HPP
