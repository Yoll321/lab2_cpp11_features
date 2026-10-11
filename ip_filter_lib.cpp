#include "ip_filter_lib.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);

    while (stop != std::string::npos)
    {
        result.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    result.push_back(str.substr(start));
    return result;
}

uint32_t parse_ip_to_int(const std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>& ip)
{
    uint32_t res = 0;
    res += static_cast<uint32_t>(std::get<0>(ip)) << 24;
    res += static_cast<uint32_t>(std::get<1>(ip)) << 16;
    res += static_cast<uint32_t>(std::get<2>(ip)) << 8;
    res += static_cast<uint32_t>(std::get<3>(ip));
    return res;
}

void print_ip(const std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>& ip)
{
    std::cout << static_cast<unsigned int>(std::get<0>(ip)) << '.';
    std::cout << static_cast<unsigned int>(std::get<1>(ip)) << '.';
    std::cout << static_cast<unsigned int>(std::get<2>(ip)) << '.';
    std::cout << static_cast<unsigned int>(std::get<3>(ip)) << '\n';
}