/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:41:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/31 21:52:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

ex01::Error::Error(int code) : error_code(code) {}


const char* ex01::Error::what() const throw()
{
	switch (error_code)
	{
	case EMPTY_FIRST_NAME:
		return "Empty first name";
	case EMPTY_LAST_NAME:
		return "Empty last name";
	case EMPTY_NICKNAME:
		return "Empty nickname";
	case EMPTY_PHONE_NUMBER:
		return "Empty phone number";
	case EMPTY_DARKEST_SECRET:
		return "Empty darkest secret";
	case INVALID_PHONE_NUMBER:
		return "Invalid phone number";
	default:
		return "";
	}
}