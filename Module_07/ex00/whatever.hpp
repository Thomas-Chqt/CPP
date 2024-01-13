/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:58:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 20:01:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) 
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T& a, T& b) 
{
    return a < b ? a : b;
}

template<typename T>
T max(T& a, T& b) 
{
    return a > b ? a : b;
}

#endif // WHATEVER_HPP