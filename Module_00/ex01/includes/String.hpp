/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:12:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/02 01:21:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <string>

namespace ex01
{
	class String: public std::string
	{
	public:
		String();
		String(std::string std_str);
		String(const char str[]);
		String fited_in(size_t len) const;
		bool empty() const;
	};
}

#endif // STRING_HPP