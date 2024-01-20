/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:24:53 by tchoquet          #+#    #+#             */
/*   Updated: 2024/01/13 19:38:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <algorithm>

Span::Span() : m_maxElCount(0), m_sspanZero(false)
{
#ifdef DEBUG
    std::cout << "default constructor called" << std::endl;
#endif
}

Span::Span(unsigned int n) : m_maxElCount(n), m_sspanZero(false)
{
#ifdef DEBUG
    std::cout << "n constructor called" << std::endl;
#endif
}

Span::Span(const Span& cp) : m_maxElCount(cp.m_maxElCount), m_set(cp.m_set), m_sspanZero(cp.m_sspanZero)
{
#ifdef DEBUG
    std::cout << "copy constructor called" << std::endl;
#endif
}

void Span::addNumber(int nbr)
{
    if (m_set.size() >= m_maxElCount)
        throw TooManyElements();
    if (m_set.count(nbr) > 0)
        m_sspanZero = true;
    m_set.insert(nbr);
}

int Span::shortestSpan()
{
    if (m_set.size() < 2)
        throw NotEnoughElements();

    if (m_sspanZero == true)
        return 0;
        
    std::set<int>::iterator current = m_set.begin();
    std::set<int>::iterator next = ++m_set.begin();

    std::set<int>::iterator end = m_set.end();

    int smallest = longestSpan();

    while (next != end)
    {
        smallest = std::min(smallest, *next - *current);
        ++next;
        ++current;
    }
    return smallest;
}

int Span::longestSpan()
{
    if (m_set.size() < 2)
        throw NotEnoughElements();

    return *(--m_set.end()) - *m_set.begin();
}

Span::~Span()
{
#ifdef DEBUG
    std::cout << "destructor called" << std::endl;
#endif
}

Span& Span::operator=(const Span& rhs)
{
#ifdef DEBUG
    std::cout << "copy assignement operator called" << std::endl;
#endif

    if (&rhs != this)
    {
        m_maxElCount = rhs.m_maxElCount;
        m_set = rhs.m_set;
    }
    return *this;
}