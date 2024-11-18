/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:41:42 by tchoquet          #+#    #+#             */
/*   Updated: 2024/02/07 17:42:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define DATABASE_FILEPATH "data.csv"

#include <map>
#include <string>
#include <exception>
#include <sstream>

typedef unsigned int uint32;

class BitcoinExchange
{
public:
    struct error : public std::runtime_error
    {
        error(const std::string& filepath, const std::string& description);
        error(const std::string& filepath, uint32 line, const std::string& description);
    };

    struct Date
    {
        uint32 year;
        uint32 month;
        uint32 day;

        bool isValid() const;

        operator uint32 ();
        operator std::string ();
    };

    template<char C> struct Delimiter { char c; };
    
public:
    BitcoinExchange(const std::string& filepath = DATABASE_FILEPATH);
    BitcoinExchange(const BitcoinExchange& cp);

    void processInputFile(const std::string& filepath);
    
    ~BitcoinExchange();

private:
    std::map<uint32, double> m_database;

public:
    BitcoinExchange& operator = (const BitcoinExchange& rhs);
};

std::istream& operator >> (std::istream& is, BitcoinExchange::Date& dst);

template<char C> std::istream& operator >> (std::istream& is, const BitcoinExchange::Delimiter<C>& dst)
{
    (void)dst;
    char c;
    is >> c;
    if (is.good())
    {
        if (c != C)
            is.setstate(std::ios_base::failbit);
    }
    return is;
}

#endif // BITCOINEXCHANGE_HPP