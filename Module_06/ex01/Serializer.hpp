/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 11:52:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

class Serializer
{
public:
    struct Data
    {
        std::string name;
        int age;
    };

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
#endif // SERIALIZER_HPP