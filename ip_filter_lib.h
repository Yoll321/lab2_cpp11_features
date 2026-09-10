#pragma once

#include <string>
#include <cstdint>
#include <vector>

std::vector<std::string> split(const std::string& str, char d);
uint32_t parse_ip_to_int(const std::vector<std::string>& ip);
void print_ip(const std::vector<std::string>& ip);