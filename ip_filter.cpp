#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "ip_filter_lib.h"

/*
    add tuples
*/

int main(int argc, char const *argv[])
{
    try
    {
        std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            std::vector<std::string> ip_str = split(v.at(0), '.');
            if (ip_str.size() != BYTES_IN_IP) {
                std::cerr << "Incorrect ip: ";
                for (size_t i = 0; i < ip_str.size() - 2; i++)
                    std::cerr << ip_str[i] << '.';
                std::cerr << ip_str[ip_str.size() - 1] << '\n';
                exit(1);
            }
            std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> new_ip = 
                std::make_tuple(
                    static_cast<uint8_t>(stoi(ip_str[0])),
                    static_cast<uint8_t>(stoi(ip_str[1])),
                    static_cast<uint8_t>(stoi(ip_str[2])),
                    static_cast<uint8_t>(stoi(ip_str[3]))
                );
            ip_pool.push_back(std::move(new_ip));
        }

        // TODO reverse lexicographical sort
        std::sort(ip_pool.begin(), ip_pool.end(), 
            [](const auto &ip1, const auto &ip2) {
                return parse_ip_to_int(ip1) > parse_ip_to_int(ip2);
            });

        for (auto& ip : ip_pool) 
        {
            print_ip(ip);
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // ip = filter(1)
        for (auto &ip : ip_pool)
            if (std::get<0>(ip) == 1)
                print_ip(ip);


        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // ip = filter(46, 70)
        for (auto &ip : ip_pool)
            if (std::get<0>(ip) == 46 && std::get<1>(ip) == 70)
                print_ip(ip);

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // ip = filter_any(46)
        for (auto &ip : ip_pool) {
            if (std::get<0>(ip) == 46 ||
                std::get<1>(ip) == 46 ||
                std::get<2>(ip) == 46 ||
                std::get<3>(ip) == 46)
                print_ip(ip);
        }

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
