/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:30:26 by tchoquet          #+#    #+#             */
/*   Updated: 2024/02/07 19:00:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>

class RPN
{
public:
    RPN();
    RPN(const RPN& cp);
    
    int calculateRPN(const std::string& str);

    ~RPN();

private:
    std::stack<int> m_stack;

public:
    RPN& operator=(const RPN& rhs);
};