/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:49:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/01 10:56:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void add_contact();
	void search() const;

private:
	void print_list() const;
	void print_one(int i) const;
	int contact_count;
	int next_set;
	Contact contacts[8]; 
};


#endif // PHONEBOOK_CPP