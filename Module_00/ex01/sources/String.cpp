/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:15:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/02 01:21:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

ex01::String::String() {}
ex01::String::String(std::string std_str) : std::string(std_str) {}
ex01::String::String(const char str[]) : std::string(str) {}

ex01::String ex01::String::fited_in(size_t len) const
{
	ex01::String subed_str = this->substr(0, len);

	if (this->length() == len)
		return subed_str;
	if (this->length() < len)
		return std::string(len - this->length(), ' ') + *this;
	subed_str.back() = '.';
	return subed_str;
}

bool ex01::String::empty() const
{
	if (std::string::empty() == true)
		return true;
	return find_first_not_of(" \t\n\v\f\r") == npos;
}
