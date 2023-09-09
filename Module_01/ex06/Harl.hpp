/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:47:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/09 18:08:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
	typedef void(Harl::* print_member)();

public:
	Harl(const std::string& filter);
	void complain(std::string level);
	void print_filter();

private:
	int get_index(const std::string& level);

	void debug();
	void info();
	void warning();
	void error();

	int filter_index;
	print_member func_ptrs[4];
};

#endif // HARL_HPP
