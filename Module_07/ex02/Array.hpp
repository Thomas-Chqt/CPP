/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/18 11:26:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

template<typename T>
class Array
{
public:
    Array() : buff(NULL), len(0) {}
    Array(const Array& cp) : buff(new T[cp.len]), len(cp.len)
    {
        for (unsigned int i = 0; i < cp.len; i++)
            this->buff[i] = cp.buff[i];
    }
    
    Array(unsigned int n) : buff(new T[n]), len(n) {}

    inline unsigned int size() const { return len; }

    ~Array()
    {
        delete[] buff;
    }

private:
    T* buff;
    unsigned int len;

public:
    Array& operator=(const Array& rhs)
    {
        if (&rhs != this)
        {
            delete[] buff;
            buff = new T[rhs.size()];
            len = rhs.len;
            for (unsigned int i = 0; i < rhs.len; i++)
                this->buff[i] = rhs.buff[i];
        }    
        return *this;
    }

    T& operator[](unsigned int idx)
    {
        if (idx >= len)
            throw std::out_of_range("Out of range");
        return buff[idx];
    }

    T operator[](unsigned int idx) const
    {
        if (idx >= len)
            throw std::out_of_range("Out of range");
        return buff[idx];
    }
};