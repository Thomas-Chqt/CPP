/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 11:59:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main()
{
    Serializer::Data data = {"Jimmy", 42};

    std::cout << "&data : " << &data << std::endl;
    std::cout << "data.name : " << data.name << std::endl;
    std::cout << "data.age : " << data.age << std::endl;

    uintptr_t uintptr = Serializer::serialize(&data);

    std::cout << "uintptr : " << uintptr << std::endl;

    Serializer::Data* new_data = Serializer::deserialize(uintptr);

    std::cout << "new_data : " << new_data << std::endl;
    std::cout << "new_data->name : " << new_data->name << std::endl;
    std::cout << "new_data->age : " << new_data->age << std::endl;

    return 0;
}
