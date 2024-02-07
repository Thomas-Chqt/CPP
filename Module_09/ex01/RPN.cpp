/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:30:43 by tchoquet          #+#    #+#             */
/*   Updated: 2024/02/07 19:12:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>

RPN::RPN()
{
}

RPN::RPN(const RPN& cp) : m_stack(cp.m_stack)
{
}

int RPN::calculateRPN(const std::string& str)
{
    for (std::string::const_iterator curr = str.begin(); curr < str.end(); ++curr)
    {
        if (*curr >= '0' && *curr <= '9')
            m_stack.push(*curr - '0');
        else if (*curr == ' ' || *curr == '\t')
            continue;
        else
        {
            int one = 0;
            int two = 0;

            if (!m_stack.empty())
            {
                two = m_stack.top();
                m_stack.pop();
            }
            if (!m_stack.empty())
            {
                one = m_stack.top();
                m_stack.pop();
            }

            switch (*curr)
            {
            case '+':
                m_stack.push(one + two);
                break;
            case '-':
                m_stack.push(one - two);
                break;
            case '/':
                m_stack.push(one / two);
                break;
            case '*':
                m_stack.push(one * two);
                break;
            default:
                throw std::runtime_error("Error");
            }
        }
    }
    
    if (m_stack.size() == 1)
        return m_stack.top();
    
    throw std::runtime_error("Error");
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& rhs)
{
    if (this != &rhs)
        m_stack = rhs.m_stack;
    return *this;
}
