/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:56:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/08 13:56:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed (std::istream& input_stream, std::ostream& output_stream,
		const std::string& s1, const std::string& s2)
	:	
		input_stream(input_stream),
		output_stream(output_stream),
		s1(s1),
		s2(s2) {}

void Sed::start()
{
	size_t equal_len;
	char c;

	while (input_stream.good())
	{
		equal_len = 0;
		c = input_stream.get();
		while (s1[equal_len] == c && ++equal_len < s1.length())
		{
			c = input_stream.get();
		}
		
		if (equal_len == s1.length())
			output_stream << s2;
		else
		{
			output_stream << std::string(s1, 0, equal_len);

			if (input_stream.good())
				output_stream << c;
		}
	}
}