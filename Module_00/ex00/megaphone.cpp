/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:15:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/02 15:11:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifdef MEMCHECK

__attribute__((destructor))
static void	destructor(void)
{
	std::cout << std::endl;
	system("leaks -q megaphone_debug");
}

#endif // MEMCHECK

std::string capitalized(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

int main(int argc, const char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			std::cout << capitalized(str);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
