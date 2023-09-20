/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:53:15 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/18 12:24:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>

#include "Brain.hpp"

Brain::Brain() : ideas_count(0), new_idea_pos(0)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& cp) : ideas_count(cp.ideas_count), new_idea_pos(cp.new_idea_pos)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < ideas_count; i++)
		ideas[i] = cp.ideas[i];
}

void Brain::new_idea(std::string content)
{
	if (new_idea_pos == 100)
		new_idea_pos = 0;
	ideas[new_idea_pos++] = content;
	if (ideas_count < 100)
		ideas_count++;
}

void Brain::print_ideas()
{
	if (ideas_count == 0)
		return (void)(std::cout << "No idea in this brain" << std::endl);
	
	for (int i = 0; i < ideas_count; i++)
		std::cout << "Idea " << i + 1 << ": " << ideas[i] << std::endl;		
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& cp)
{
	if (this == &cp)
		std::cout << "Brain assignement operator called but nothing done" << std::endl;
	else
	{
		std::cout << "Brain assignement operator called" << std::endl;
		ideas_count = cp.ideas_count;
		new_idea_pos = cp.new_idea_pos;
		for (int i = 0; i < ideas_count; i++)
			ideas[i] = cp.ideas[i];
	}
	return *this;
}
