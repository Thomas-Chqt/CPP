/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:20:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/08 16:15:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "Sed.hpp"

#ifdef MEMCHECK

__attribute__((destructor))
static void destructor(void)
{
    std::cout << std::endl;
    system("leaks -q sed_debug");
}

#endif

int main(int argc, char const *argv[])
{
	if (argc < 4)
	{
		std::cout << "sed: missing argument" << std::endl;
		return 1;
	}

	std::ifstream input_file;
	input_file.exceptions(std::ifstream::failbit);
	try
	{
		input_file.open(argv[1]);
	}
	catch(...)
	{
		std::cout << "sed: " << argv[1] << ": " << strerror(errno) << std::endl;
		return errno;
	}
	
	std::string output_filename = std::string(argv[1]) + ".replace";
	std::ofstream output_file(output_filename.c_str());
	
	Sed sed(input_file, output_file, argv[2], argv[3]);
	sed.start();
	
	return 0;
}