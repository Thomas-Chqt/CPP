/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:51:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 12:22:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain& cp);

	void new_idea(std::string content);
	void print_ideas();
	
	~Brain();

private:
	std::string ideas[100];
	int ideas_count;
	int new_idea_pos;
	

public:
	Brain& operator=(const Brain& cp);
};

#endif // BRAIN_HPP