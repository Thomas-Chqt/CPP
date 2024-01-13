/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:35:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/18 11:12:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }

private:
    int _n;
};

std::ostream& operator<<(std::ostream & o, Awesome const & rhs)
{
  o << rhs.get();
  return o;
}

template<typename T>
void print(T& x)
{
  std::cout << x << std::endl;
  return;
}

int main()
{
    std::cout << "\033[0;32m" << "Review exemple" << "\033[0m" << std::endl;
    {
        int tab[] = { 0, 1, 2, 3, 4 };
        Awesome tab2[5];

        iter(tab, 5, print<const int>);
        iter(tab2, 5, print<Awesome>);
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "int" << "\033[0m" << std::endl;
    {
        int array[3] = {1, 2, 3};

        iter(array, 3, &print<int>);
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "string" << "\033[0m" << std::endl;
    {
        std::string array[3] = {"a", "b", "c"};

        iter(array, 3, &print<std::string>);
    }
    std::cout << std::endl;


    std::cout << "\033[0;32m" << "float" << "\033[0m" << std::endl;
    {
        float array[3] = {1.1f, 2.2f, 3.3f};

        iter(array, 3, &print<float>);
    }
    
    return 0;
}
