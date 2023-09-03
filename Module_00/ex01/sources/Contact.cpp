/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:59:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/01 01:12:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(ex01::String s)
{
	if (s.empty() == true)
		throw ex01::Error(EMPTY_FIRST_NAME);
	this->first_name = s;
}

ex01::String Contact::get_first_name() const
{
	return first_name;
}


void Contact::set_last_name(ex01::String s)
{
	if (s.empty() == true)
		throw ex01::Error(EMPTY_LAST_NAME);
	this->last_name = s;
}

ex01::String Contact::get_last_name() const
{
	return last_name;
}


void Contact::set_nickname(ex01::String s)
{
	if (s.empty() == true)
		throw ex01::Error(EMPTY_NICKNAME);
	this->nickname = s;
}

ex01::String Contact::get_nickname() const
{
	return nickname;
}


void Contact::set_phone_number(ex01::String s)
{
	if (s.empty() == true)
		throw ex01::Error(EMPTY_PHONE_NUMBER);
	this->phone_number = s;
}

ex01::String Contact::get_phone_number() const
{
	return phone_number;
}


void Contact::set_darkest_secret(ex01::String s)
{
	if (s.empty() == true)
		throw ex01::Error(EMPTY_DARKEST_SECRET);
	this->darkest_secret = s;
}

ex01::String Contact::get_darkest_secret() const
{
	return darkest_secret;
}