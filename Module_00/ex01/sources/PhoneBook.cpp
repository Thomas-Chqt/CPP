/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:06:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/02 12:32:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PhoneBook.hpp"

void getline(std::istream& is, int& nbr)
{
	std::string line;
	
	std::getline(is, line);
	if (is.good() == false)
		throw ex01::Error(REACH_EOF);
	std::istringstream stream(line);
	stream >> nbr;
	if (stream.fail() || stream.peek() != EOF)
		throw std::invalid_argument("");
}

PhoneBook::PhoneBook() : contact_count(0), next_set(0), contacts() {}

void PhoneBook::add_contact()
{
	int error_count = 0;
	Contact new_contact;
	
start:
	try
	{
		if (new_contact.get_first_name().empty())
		{
			ex01::String string;

			std::cout << "First name: ";
			std::getline(std::cin, string);
			if (std::cin.good() == false)
				throw 1;
			new_contact.set_first_name(string);
			error_count = 0;
		}

		if (new_contact.get_last_name().empty())
		{
			ex01::String string;

			std::cout << "Last name: ";
			std::getline(std::cin, string);
			if (std::cin.good() == false)
				throw 1;
			new_contact.set_last_name(string);
			error_count = 0;
		}

		if (new_contact.get_nickname().empty())
		{
			ex01::String string;

			std::cout << "Nickname: ";
			std::getline(std::cin, string);
			if (std::cin.good() == false)
				throw 1;
			new_contact.set_nickname(string);
			error_count = 0;
		}

		if (new_contact.get_phone_number().empty())
		{
			ex01::String string;

			std::cout << "Phone number: ";
			std::getline(std::cin, string);
			if (std::cin.good() == false)
				throw 1;
			new_contact.set_phone_number(string);
			error_count = 0;
		}

		if (new_contact.get_darkest_secret().empty())
		{
			ex01::String string;

			std::cout << "Darkest secret: ";
			std::getline(std::cin, string);
			if (std::cin.good() == false)
				throw 1;
			new_contact.set_darkest_secret(string);
			error_count = 0;
		}

		contacts[next_set++] = new_contact;
		if (next_set == 8)
			next_set = 0;
		if (contact_count < 8)
			contact_count++;
		return;
	}
	catch (std::exception& error)
	{
		std::cout << "Error: " << error.what() << std::endl;
		if (++error_count < 3)
			goto start;
	}
	catch(...)
	{
		std::cin.clear();
		clearerr(stdin);
		std::cout << std::endl;
	}
	std::cout << "Abort" << std::endl;
}

void PhoneBook::search() const
{
	int error_count = 0;
	ex01::String line;
	int	selected_index;

	if (this->contact_count == 0)
	{
		std::cout << "No contact" << std::endl;
		return;
	}
	
	print_list();
input:
	try
	{
		std::cout << "Index: ";
		getline(std::cin, selected_index);
		if (selected_index < 0 || selected_index >= this->contact_count)
			throw std::invalid_argument("");
	}
	catch (ex01::Error)
	{
		std::cout << std::endl;
		std::cout << "Abort" << std::endl;
		std::cin.clear();
		clearerr(stdin);
		return;
	}
	catch (std::invalid_argument)
	{
		std::cout << "Bad index" << std::endl;
		if (++error_count == 3)
		{
			std::cout << "Abort" << std::endl;
			return;
		}
		goto input;
	}
	print_one(selected_index);
}

void PhoneBook::print_list() const
{
	std::cout << std::string(43, '-') << std::endl;
	
	for (int i = 0; i < contact_count; i++)
	{
		std::cout
			<< std::string(9, ' ')
			<<  i
			<< '|'
			<<  contacts[i].get_first_name().fited_in(10)
			<< '|'
			<<  contacts[i].get_last_name().fited_in(10)
			<< '|'
			<<  contacts[i].get_nickname().fited_in(10)
			<<  std::endl
			<<  std::string(43, '-')
			<<  std::endl;
	}
}

void PhoneBook::print_one(int i) const
{
	std::cout << "First name: " << contacts[i].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[i].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[i].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[i].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[i].get_darkest_secret() << std::endl;
}
