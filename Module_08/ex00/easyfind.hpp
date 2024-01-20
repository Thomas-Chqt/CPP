/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:01:30 by tchoquet          #+#    #+#             */
/*   Updated: 2024/01/13 17:25:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>

struct NotFound : std::exception
{
    inline const char* what() const throw() { return "value not found"; }
};


template<typename T>
int& easyfind(T& container, int val)
{
    typename T::iterator it = find(container.begin(), container.end(), val);

    if (it != container.end())
        return *it;
    else
        throw NotFound();
}