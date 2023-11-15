/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:11:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/11 12:34:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
public:
    virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate()
{
    int nbr = std::rand() % 3;

    switch (nbr)
    {
    case 0:
        std::cout << "Create A" << std::endl;
        return new A;
    case 1:
        std::cout << "Create B" << std::endl;
        return new B;
    case 2:
        std::cout << "Create C" << std::endl;
        return new C;
    default:
        return NULL;
    }
}

void identify(Base* p)
{
    if (A* a = dynamic_cast<A*>(p))
        std::cout << "pointer p is A" << std::endl;
    if (B* b = dynamic_cast<B*>(p))
        std::cout << "pointer p is B" << std::endl;
    if (C* c = dynamic_cast<C*>(p))
        std::cout << "pointer p is C" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "reference p is A" << std::endl;
    }
    catch(...){}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "reference p is B" << std::endl;
    }
    catch(...){}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "reference p is C" << std::endl;
    }
    catch(...){}
}

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 20; i++)
    {
        Base *obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
        std::cout << std::endl;
    }

    return 0;
}
