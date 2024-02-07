/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:30:30 by tchoquet          #+#    #+#             */
/*   Updated: 2024/02/07 19:08:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    RPN rpn;

    try
    {
        std::cout << rpn.calculateRPN(argv[1]) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    

    return 0;
}
