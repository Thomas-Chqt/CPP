/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:24:41 by tchoquet          #+#    #+#             */
/*   Updated: 2024/01/13 19:35:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <exception>

class Span
{
struct TooManyElements : std::exception { const char* what() const throw() { return "Too many elements"; } };
struct NotEnoughElements : std::exception { const char* what() const throw() { return "Not enough elements"; } };

public:
    Span();
    Span(unsigned int n);
    Span(const Span& cp);

    void addNumber(int nbr);
    int shortestSpan();
    int longestSpan();

    template <typename InputIterator>
    void addNumber(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            addNumber(*first);
            ++first;
        }
    }
    
    ~Span();

private:
    unsigned int m_maxElCount;
    std::set<int> m_set;
    bool m_sspanZero;
    
public:
    Span& operator=(const Span& rhs);
};