/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:39:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/02 11:42:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>

#define EMPTY_FIRST_NAME 1
#define EMPTY_LAST_NAME 2
#define EMPTY_NICKNAME 3
#define EMPTY_PHONE_NUMBER 4
#define EMPTY_DARKEST_SECRET 5
#define INVALID_PHONE_NUMBER 6
#define REACH_EOF 7

namespace ex01
{
	class Error: public std::exception
	{
	public:
		Error(int code);
		const char* what() const throw();
		const int error_code;
	};
}

#endif // ERROR_HPP