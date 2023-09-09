/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:01:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/04 17:35:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;


	std::cout << "Adress of str:       " << &str << std::endl;
	std::cout << "Adress in stringPTR: " << stringPTR << std::endl;
	std::cout << "Adress in stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "Value of str:                  " << str << std::endl;
	std::cout << "Value of pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of pointed by stringREF: " << stringREF << std::endl;

	return 0;
}