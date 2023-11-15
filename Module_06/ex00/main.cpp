/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:14:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 17:36:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2) return std::cerr << "Invalid argument" << std::endl, 1;

    try
    {
        ScalarConverter::convert(argv[1]);
        std::cout << "char: " << ScalarConverter::as_char() << std::endl;
        std::cout << "int: " << ScalarConverter::as_int() << std::endl;
        std::cout << "float: " << ScalarConverter::as_float() << std::endl;
        std::cout << "double: " << ScalarConverter::as_double() << std::endl;
    }
    catch(const std::exception& e)
    {
        return std::cerr << e.what() << std::endl, 1;
    }
    return 0;
}
