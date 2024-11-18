/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:24:42 by tchoquet          #+#    #+#             */
/*   Updated: 2024/05/01 18:55:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJMI_HPP
# define FJMI_HPP

#include <vector>
#include <list>

typedef unsigned int uint32;

template<typename Iterator>
Iterator operator + (const Iterator& it, const uint32& n)
{
    Iterator ret = it;
    for (uint32 i = 0; i < n; i++)
        ++ret;
    return ret;
}

template<typename Iterator>
Iterator& operator += (Iterator& it, const uint32& n)
{
    for (uint32 i = 0; i < n; i++)
        ++it;
    return it;
}

template<typename Iterator>
Iterator operator - (const Iterator& it, const uint32& n)
{
    Iterator ret = it;
    for (uint32 i = 0; i < n; i++)
        --ret;
    return ret;
}

template<typename Iterator>
Iterator& operator -= (Iterator& it, const uint32& n)
{
    for (uint32 i = 0; i < n; i++)
        --it;
    return it;
}

template<typename Iterator>
void swap_iterator_range(Iterator headA, Iterator headB, uint32 rangeLen)
{
    Iterator currA = headA;
    Iterator currB = headB;
    for (uint32 i = 0; i < rangeLen; ++currA, ++currB, i++)
        std::iter_swap(currA, currB);
}

template<typename Container>
void binaryInsert(Container& container, const typename Container::iterator begin, const typename Container::iterator end, uint32 elementSize, const typename Container::iterator element)
{
    typename Container::size_type size = std::distance(begin, end) / elementSize;
    if (size == 1)
    {
        if (*element <= *begin)
            container.insert(begin, element, element + elementSize);
        else
            container.insert(end, element, element + elementSize);
        return;
    }
    
    if (*element < *(begin + (size / 2) * elementSize))
        return binaryInsert(container, begin, end - (size / 2) * elementSize, elementSize, element);

    return binaryInsert(container, begin + (size / 2) * elementSize, end, elementSize, element);    
}

template<typename Iterator>
Iterator nextInstertEnd(const Iterator& it, uint32 elementSize);

template<>
inline std::vector<uint32>::iterator nextInstertEnd<std::vector<uint32>::iterator>(const std::vector<uint32>::iterator& it, uint32 elementSize)
{
    return it + elementSize * 2;
}

template<>
inline std::list<uint32>::iterator nextInstertEnd<std::list<uint32>::iterator>(const std::list<uint32>::iterator& it, uint32 elementSize)
{
    return it + elementSize;
}

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

    container.insert(container.begin(), pending.begin(), pending.begin() + elementSize);

    Iterator instertEnd = container.begin() + elementSize * 2;
    for (Iterator it = pending.begin() + elementSize; it != pending.end(); it += elementSize)
    {
        binaryInsert(container, container.begin(), instertEnd, elementSize, it);
        instertEnd = nextInstertEnd(instertEnd, elementSize);
    }
}

#endif // FJMI_HPP