/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:41:42 by tchoquet          #+#    #+#             */
/*   Updated: 2023/11/13 13:08:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& s);
        static std::string as_char();
        static std::string as_int();
        static std::string as_float();
        static std::string as_double();
    
    private:
        enum Type { invalid_type, char_type, int_type, float_type, double_type };

        static bool convert_char  (const std::string &s);
        static bool convert_int   (const std::string &s);
        static bool convert_float (const std::string &s);
        static bool convert_double(const std::string &s);
        static bool convert_pseudo(const std::string &s);

        static Type input_type;

        static int input_precision;

        static char   input_val_char;
        static int    input_val_int;
        static float  input_val_float;
        static double input_val_double;
};

#endif // SCALARCONVERTER_HPP