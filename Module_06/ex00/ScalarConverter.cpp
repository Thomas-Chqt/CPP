/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:38:59 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/13 16:09:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <sstream>

ScalarConverter::Type ScalarConverter::input_type = invalid_type;

int ScalarConverter::input_precision = 0;

char   ScalarConverter::input_val_char   = 0;
int    ScalarConverter::input_val_int    = 0;
float  ScalarConverter::input_val_float  = 0;
double ScalarConverter::input_val_double = 0;

void ScalarConverter::convert(const std::string &s)
{
    try
    {
        if (convert_int(s) == true)  return;
        if (convert_char(s) == true)  return;
        if (convert_float(s) == true)  return;
        if (convert_double(s) == true)  return;
        if (convert_pseudo(s) == true)  return;
        throw NULL;
    }
    catch(...)
    {
        throw std::invalid_argument("Invalid argument");
    }
}

std::string ScalarConverter::as_char()
{
    std::ostringstream stream;

    switch (ScalarConverter::input_type)
    {
    case char_type:
        stream << "'" << ScalarConverter::input_val_char << "'";
        break;
    case int_type:
        if (ScalarConverter::input_val_int < ' ' || ScalarConverter::input_val_int > '~')
            stream << "Non displayable";
        else
            stream << "'" << static_cast<char>(ScalarConverter::input_val_int) << "'";
        break;
    case float_type:
        if (ScalarConverter::input_val_float < ' ' || ScalarConverter::input_val_float > '~')
            stream << "Non displayable";
        else if (ScalarConverter::input_val_float != ScalarConverter::input_val_float)
            stream << "Impossible";
        else
            stream << "'" << static_cast<char>(ScalarConverter::input_val_float) << "'";
        break;
    case double_type:
        if (ScalarConverter::input_val_double < ' ' || ScalarConverter::input_val_double > '~')
            stream << "Non displayable";
        else if (ScalarConverter::input_val_double != ScalarConverter::input_val_double)
            stream << "Impossible";
        else
            stream << "'" << static_cast<char>(ScalarConverter::input_val_double) << "'";
        break;
    default:
        stream << "Impossible";
    }
    return stream.str();
}

std::string ScalarConverter::as_int()
{
    std::ostringstream stream;

    switch (ScalarConverter::input_type)
    {
    case char_type:
        stream << static_cast<int>(ScalarConverter::input_val_char);
        break;
    case int_type:
        stream << ScalarConverter::input_val_int;
        break;
    case float_type:
        if (ScalarConverter::input_val_float < INT_MIN)
            stream << "Underflow";
        else if (ScalarConverter::input_val_float > INT_MAX)
            stream << "Overflow";
        else if (ScalarConverter::input_val_float != ScalarConverter::input_val_float)
            stream << "Impossible";
        else
            stream << static_cast<int>(ScalarConverter::input_val_float);
        break;
    case double_type:
        if (ScalarConverter::input_val_double < INT_MIN)
            stream << "Underflow";
        else if (ScalarConverter::input_val_double > INT_MAX)
            stream << "Overflow";
        else if (ScalarConverter::input_val_double != ScalarConverter::input_val_double)
            stream << "Impossible";
        else
            stream << static_cast<int>(ScalarConverter::input_val_double);
        break;
    default:
        stream << "Impossible";
    }
    return stream.str();
}

std::string ScalarConverter::as_float()
{
    std::ostringstream stream;

    stream.precision(ScalarConverter::input_precision == 0 ? 1 : ScalarConverter::input_precision);
    switch (ScalarConverter::input_type)
    {
    case char_type:
        stream << std::fixed << static_cast<float>(ScalarConverter::input_val_char) << 'f';
        break;
    case int_type:
        stream << std::fixed << static_cast<float>(ScalarConverter::input_val_int) << 'f';
        break;
    case float_type:
        stream << std::fixed << ScalarConverter::input_val_float << 'f';
        break;
    case double_type:
        stream << std::fixed << static_cast<float>(ScalarConverter::input_val_double) << 'f';
        break;
    default:
        stream << "Impossible";
    }
    return stream.str();
}

std::string ScalarConverter::as_double()
{
    std::ostringstream stream;

    stream.precision(ScalarConverter::input_precision == 0 ? 1 : ScalarConverter::input_precision);
    switch (ScalarConverter::input_type)
    {
    case char_type:
        stream << std::fixed << static_cast<double>(ScalarConverter::input_val_char);
        break;
    case int_type:
        stream << std::fixed << static_cast<double>(ScalarConverter::input_val_int);
        break;
    case float_type:
        stream << std::fixed << static_cast<double>(ScalarConverter::input_val_float);
        break;
    case double_type:
        stream << std::fixed << ScalarConverter::input_val_double;
        break;
    default:
        stream << "Impossible";
    }
    return stream.str();
}

bool ScalarConverter::convert_char(const std::string &s)
{
    std::istringstream stream(s);

    stream >> ScalarConverter::input_val_char;
    if (stream.fail() || stream.peek() != EOF)
        return false;
    ScalarConverter::input_type = char_type;
    return true;
}

bool ScalarConverter::convert_int(const std::string &s)
{
    std::istringstream stream(s);

    stream >> ScalarConverter::input_val_int;
    if (stream.fail() || stream.eof() == false)
        return false;
    ScalarConverter::input_type = int_type;
    return true;
}

bool ScalarConverter::convert_float(const std::string &s)
{
    if (s.length() < 4 || s.find('.') == std::string::npos || s[s.length() - 1] != 'f' || s[s.length() - 2] == '.')
        return false;
    std::istringstream stream(s.substr(0, s.length() - 1));

    stream >> ScalarConverter::input_val_float;
    if (stream.fail() || stream.eof() == false)
        return false;
    ScalarConverter::input_precision = (s.length() - 2) - s.find('.');
    ScalarConverter::input_type = float_type;
    return true;
}

bool ScalarConverter::convert_double(const std::string &s)
{
    if (s.length() < 3 || s.find('.') == std::string::npos || s[s.length() - 1] == '.')
        return false;
    std::istringstream stream(s);

    stream >> ScalarConverter::input_val_double;
    if (stream.fail() || stream.eof() == false)
        return false;
    ScalarConverter::input_precision = (s.length() - 1) - s.find('.');
    ScalarConverter::input_type = double_type;
    return true;
}

bool ScalarConverter::convert_pseudo(const std::string &s)
{
    if ((s[0] >= '0' && s[0] <= '9') || (s[1] >= '0' && s[1] <= '9'))
        return false;
    std::istringstream stream(s);
    stream >> ScalarConverter::input_val_double;
    if (stream.fail() || stream.eof() == false)
    {
        if (s[s.length() - 1] != 'f' && s[s.length() - 1] != 'F')
            return false;
        std::istringstream stream2(s.substr(0, s.length() - 1));
        stream2 >> ScalarConverter::input_val_float;
        if (stream2.fail() || stream2.eof() == false)
            return false;
        ScalarConverter::input_type = float_type;
        return true;
    }
    ScalarConverter::input_type = double_type;
    return true;
}
