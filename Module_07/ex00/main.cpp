/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:42:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 20:11:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"

int main()
{
    std::cout << "\033[0;32m" << "Subject exemple" << "\033[0m" << std::endl;
    {
        int a = 2;
        int b = 3;
        
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\033[0;32m" << "int" << "\033[0m" << std::endl;
    {
        int a = 1;
        int b = 2;

        std::cout << "a : " << a << " | b : " << b << std::endl;
        std::cout << "swap..." << std::endl;
        swap(a, b);
        std::cout << "a : " << a << " | b : " << b << std::endl;
        std::cout << "min : " << min(a, b) << " | max : " << max(a,b) << std::endl;
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "char" << "\033[0m" << std::endl;
    {
        char a = 'A';
        char b = 'F';

        std::cout << "a : " << a << " | b : " << b << std::endl;
        std::cout << "swap..." << std::endl;
        swap(a, b);
        std::cout << "a : " << a << " | b : " << b << std::endl;
        std::cout << "min : " << min(a, b) << " | max : " << max(a,b) << std::endl;
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "long" << "\033[0m" << std::endl;
    {
        long a = 123132452456;
        long b = 98578965767;

        std::cout << "a : " << a << " | b : " << b << std::endl;
        std::cout << "swap..." << std::endl;
        swap(a, b);
        std::cout << "a : " << a << " | b : " << b << std::endl;
        std::cout << "min : " << min(a, b) << " | max : " << max(a,b) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
