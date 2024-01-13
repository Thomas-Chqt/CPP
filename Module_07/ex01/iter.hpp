/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:37:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/18 11:24:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void iter(void* array, int len, void (*f)(T&))
{
    if (array == NULL || len == 0 || f == NULL)
        return;
    T* cased_array = (T*)array;
    for (int i = 0; i < len; i++)
        f(cased_array[i]);
}

template<typename T>
void iter(void* array, int len, void (*f)(T))
{
    if (array == NULL || len == 0 || f == NULL)
        return;
    T* cased_array = (T*)array;
    for (int i = 0; i < len; i++)
        f(cased_array[i]);
}
