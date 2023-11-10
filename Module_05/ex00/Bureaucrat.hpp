/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:52:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/03 09:51:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
    class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw();
    };


    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& cp);
        Bureaucrat(const std::string& name, int grade);

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        ~Bureaucrat();
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat& operator=(const Bureaucrat& rhs);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
