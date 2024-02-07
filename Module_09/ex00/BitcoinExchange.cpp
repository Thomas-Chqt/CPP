/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:41:48 by tchoquet          #+#    #+#             */
/*   Updated: 2024/02/07 18:16:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>

#include <iostream>
#include <functional>

static inline std::string& rtrim(std::string& s) { return s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1), s; }
static inline std::string& ltrim(std::string& s) { return s.erase(0, s.find_first_not_of(" \t\n\r\f\v")), s; }
static inline std::string&  trim(std::string& s) { return ltrim(rtrim(s)); }

BitcoinExchange::error::error(const std::string& filepath, const std::string& description)
    : std::runtime_error("btc: " + filepath + ": " + description)
{
}

BitcoinExchange::error::error(const std::string& filepath, uint32 line, const std::string& description)
    : std::runtime_error("btc: " + filepath + ":" + std::to_string(line) + ": " + description)
{
}

bool BitcoinExchange::Date::isValid() const
{
    return year > 0 && month > 0 && month <= 12 && day > 0 && day <= 31;
}

BitcoinExchange::Date::operator uint32 ()
{
    return (year * 10000) + (month * 100) + day;
}

BitcoinExchange::Date::operator std::string ()
{
    std::ostringstream ostringstream;
    ostringstream << year << '-' << month << '-' << day;
    return ostringstream.str();
}

BitcoinExchange::BitcoinExchange(const std::string& filepath)
{
    std::ifstream ifstream(filepath);
    if (!ifstream.good())
        throw error(filepath, strerror(errno));

    std::string line;

    if(!(std::getline(ifstream, line, ',')).good() || trim(line) != "date")
        throw error(filepath, 1, "bad first line");
    if(!(std::getline(ifstream, line)).good() || trim(line) != "exchange_rate")
        throw error(filepath, 1, "bad first line");

    for (uint32 lineNbr = 2; ifstream.good(); ++lineNbr)
    {   
        Date date;
        float value;

        if (((ifstream >> date).fail() && !ifstream.eof()) || !date.isValid())
            throw error(filepath, lineNbr, "date error");
        else if (ifstream.eof())
            break;

        if (!(ifstream >> Delimiter<','>()).good())
            throw error(filepath, lineNbr, "wrong or missing delimiter");

        if ((ifstream >> value).fail())
            throw error(filepath, lineNbr, "value error");
            
        m_database[date] = value;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cp) : m_database(cp.m_database)
{
}

void BitcoinExchange::processInputFile(const std::string& filepath)
{
    std::ifstream ifstream(filepath);
    if (!ifstream.good())
        throw error(filepath, strerror(errno));

    std::string line;

    if(!(std::getline(ifstream, line, '|')).good() || trim(line) != "date")
    {
        std::cout << filepath << ":1: bad first line" << std::endl;
        std::getline(ifstream, line);
    }
    else if(!(std::getline(ifstream, line)).good() || trim(line) != "value")
        std::cout << filepath << ":1: bad first line" << std::endl;

    for (uint32 lineNbr = 2; ifstream.good(); ++lineNbr)
    {   
        ifstream.setstate(0);
        Date date;
        float value;

        if (((ifstream >> date).fail() && !ifstream.eof()) || !date.isValid())
        {
            std::cout << filepath << ":" << lineNbr << ": date error" << std::endl;
            std::getline(ifstream, line);
            continue;
        }
        else if (ifstream.eof())
            break;

        if (!(ifstream >> Delimiter<'|'>()).good())
        {
            std::cout << filepath << ":" << lineNbr << ": wrong or missing delimiter" << std::endl;
            std::getline(ifstream, line);
            continue;
        }

        if ((ifstream >> value).fail() || value < 0 || value > 1000)
        {
            std::cout << filepath << ":" << lineNbr << ": value error" << std::endl;
            std::getline(ifstream, line);
            continue;
        }

        std::cout << (std::string)date << " => " << value << " => " << value * (*(--m_database.upper_bound(date))).second << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& rhs)
{
    if (this != &rhs)
        m_database = rhs.m_database;
    return *this;
}

std::istream& operator >> (std::istream& is, BitcoinExchange::Date& dst)
{
    char delimiter;
    
    if (!(is >> dst.year).good())
        return is;

    delimiter = is.get();
    if (!is.good())
        return is;
    if (delimiter != '-')
        return is.setstate(std::ios_base::failbit), is;
    if (is.peek() < '0' || is.peek() > '9')
        return is.setstate(std::ios_base::failbit), is;

    if (!(is >> dst.month).good())
        return is;

    delimiter = is.get();
    if (!is.good())
        return is;
    if (delimiter != '-')
        return is.setstate(std::ios_base::failbit), is;
    if (is.peek() < '0' || is.peek() > '9')
        return is.setstate(std::ios_base::failbit), is;

    is >> dst.day;

    return is;
}
