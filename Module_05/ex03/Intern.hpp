/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:34:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/06 13:26:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& cp);
        
        AForm* makeForm(const std::string& name, const std::string& target) const;

        ~Intern();
    private:
    
    public:
        Intern& operator=(const Intern& rhs);
};

#endif // INTERN_HPP