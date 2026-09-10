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

uint32_t parse_ip_to_int(const std::vector<std::string>& ip)
{
    uint32_t res = 0;
    res += static_cast<uint32_t>(std::stoi(ip.at(0))) << 24;
    res += static_cast<uint32_t>(std::stoi(ip.at(1))) << 16;
    res += static_cast<uint32_t>(std::stoi(ip.at(2))) << 8;
    res += static_cast<uint32_t>(std::stoi(ip.at(3)));
    return res;
}

void print_ip(const std::vector<std::string>& ip)
{
    std::cout << ip.at(0);
    for (size_t i = 1; i < ip.size(); ++i)
        std::cout << '.' << ip.at(i);
    std::cout << '\n';
}