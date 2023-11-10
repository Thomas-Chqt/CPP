/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:33:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/05 21:36:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grad too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grad too low";
}

Bureaucrat::Bureaucrat() : name("No name"), grade(150)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Bureaucrat default constructor called" << "\033[0m" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat& cp) : name(cp.name), grade(cp.grade)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Bureaucrat copy constructor called" << "\033[0m" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Bureaucrat constructor called" << "\033[0m" << std::endl;
#endif

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    this->grade = grade;
}

const std::string &Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    std::cout << "incrementing grade" << std::endl;

    if (this->grade > 1)
        grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    std::cout << "decrementing grade" << std::endl;

    if (this->grade < 150)
        grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Bureaucrat destructor called" << "\033[0m" << std::endl;
#endif
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
#ifdef DEBUG
    std::cout << "\033[0;33m" << "Bureaucrat copy assignement operator called" << "\033[0m" << std::endl;
#endif

    this->grade = rhs.grade;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    
    return os;
}
