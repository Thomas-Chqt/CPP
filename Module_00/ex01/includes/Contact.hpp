/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:36:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/01 10:42:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

#include "String.hpp"
#include "Error.hpp"

class Contact
{
public:
    void set_first_name(ex01::String s);
	ex01::String get_first_name() const;

    void set_last_name(ex01::String s);
	ex01::String get_last_name() const;

    void set_nickname(ex01::String s);
	ex01::String get_nickname() const;

    void set_phone_number(ex01::String s);
	ex01::String get_phone_number() const;

    void set_darkest_secret(ex01::String s);
	ex01::String get_darkest_secret() const;

private:
    ex01::String first_name;
    ex01::String last_name;
    ex01::String nickname;
    ex01::String phone_number;
    ex01::String darkest_secret;
};

#endif // CONTACT_HPP
