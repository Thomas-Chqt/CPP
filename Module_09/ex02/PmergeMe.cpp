/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:32:44 by tchoquet          #+#    #+#             */
/*   Updated: 2024/11/29 18:23:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <ctime>
#include <cassert>

#include "FJMI.hpp"
#include "IteratorGroup.hpp"

template<typename Container>
bool is_sorted(const Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        typename Container::const_iterator next = it;
        next++;

        if (next != container.end() && *next < *it)
            return false;
    }
    return true;
}

PmergeMe::PmergeMe()
{
    #ifdef DEBUG
        std::cout << "PmergeMe default constructor called" << std::endl;
    #endif
}

PmergeMe::PmergeMe(const PmergeMe& cp) : m_vector(cp.m_vector), m_list(cp.m_list)
{
    #ifdef DEBUG
        std::cout << "PmergeMe copy constructor called" << std::endl;
    #endif
}

void PmergeMe::push_back(unsigned int num)
{
    m_vector.push_back(num);
    m_list.push_back(num);
}

void PmergeMe::print(std::ostream& os) const
{
    std::vector<unsigned int>::const_iterator vecIt = m_vector.begin();
    std::list<unsigned int>::const_iterator lstIt = m_list.begin();

    assert(m_vector.size() == m_list.size());
    for (; vecIt != m_vector.end(); ++vecIt, ++lstIt)
    {
        assert(*vecIt == *lstIt);
        os << *vecIt << " ";
    }
}

void PmergeMe::sort(float& vectorTime, float& listTime)
{
    clock_t start;
    
    start = clock();
    mergeInsertSort(m_vector, makeIteratorGroup(m_vector.begin(), 1), makeIteratorGroup(m_vector.end(), 1));
    vectorTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000000;
    assert(is_sorted(m_vector));

    start = clock();
    mergeInsertSort(m_list, makeIteratorGroup(m_list.begin(), 1), makeIteratorGroup(m_list.end(), 1));
    listTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000000;
    assert(is_sorted(m_list));
}

unsigned long PmergeMe::size() const
{
    assert(m_vector.size() == m_list.size());
    return m_vector.size();
}

PmergeMe::~PmergeMe()
{
    #ifdef DEBUG
        std::cout << "PmergeMe destructor called" << std::endl;
    #endif
}

PmergeMe& PmergeMe::operator = (const PmergeMe& cp)
{
    #ifdef DEBUG
        std::cout << "PmergeMe assignement operator" << std::endl;
    #endif

    if (&cp != this)
    {
        m_vector = cp.m_vector;
        m_list = cp.m_list;
    }
    return *this;
}

std::ostream& operator << (std::ostream& os, const PmergeMe& pmergeMe)
{
    pmergeMe.print(os);
    return os;
}