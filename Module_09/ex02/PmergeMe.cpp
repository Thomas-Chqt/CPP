/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:32:44 by tchoquet          #+#    #+#             */
/*   Updated: 2024/04/29 20:10:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <exception>
#include <ctime>

#include "FJMI.hpp"

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

    for (; vecIt != m_vector.end() && lstIt != m_list.end(); ++vecIt, ++lstIt)
    {
        if (vecIt == m_vector.end() || lstIt == m_list.end() || *vecIt != *lstIt)
            throw std::runtime_error("Intenal container's datas are not identical");
        os << *vecIt << " ";
    }
}

void PmergeMe::sort(float& vectorTime, float& listTime)
{
    clock_t start;
    
    start = clock();
    mergeInsertSort(m_vector);
    vectorTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    mergeInsertSort(m_list);
    listTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000000;
}

unsigned long PmergeMe::size() const
{
    if (m_vector.size() != m_list.size())
        throw std::runtime_error("Intenal container's datas are not identical");
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