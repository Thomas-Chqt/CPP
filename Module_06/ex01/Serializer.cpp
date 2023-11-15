/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 11:50:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Serializer::Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Serializer::Data *>(raw);
}
