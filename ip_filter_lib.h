#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <tuple>

#define BYTES_IN_IP 4

std::vector<std::string> split(const std::string& str, char d);
uint32_t parse_ip_to_int(const std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>& ip);
void print_ip(const std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>& ip);