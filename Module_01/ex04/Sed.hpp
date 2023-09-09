/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:56:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/08 13:18:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>

class Sed
{
public:
	Sed (std::istream& input_stream, std::ostream& output_stream,
		const std::string& s1, const std::string& s2);
	void start();

private:
	std::istream& input_stream;
	std::ostream& output_stream;

	std::string s1;
	std::string s2;
};

#endif // SED_HPP