/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:35:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/05 00:08:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>

#include "HumanA.hpp"

class HumanB : public HumanA
{
public:
	HumanB(const std::string& name);
};

#endif // HUMAN_B_HPP