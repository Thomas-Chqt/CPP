/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:24:57 by tchoquet          #+#    #+#             */
/*   Updated: 2024/04/29 13:06:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe&);

    void push_back(unsigned int num);
    void print(std::ostream& os) const;
    void sort(float& vectorTime, float& listTime);
    unsigned long size() const;

    ~PmergeMe();

private:
    std::vector<unsigned int> m_vector;
    std::list<unsigned int> m_list;

public:
    PmergeMe& operator = (const PmergeMe&);
};

std::ostream& operator << (std::ostream& os, const PmergeMe& pmergeMe);

#endif // PMERGEME_HPP
