#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <vector>

#include "../ip_filter_lib.h"

BOOST_AUTO_TEST_CASE(sort_test)
{
    std::vector<std::vector<std::string>> ip_pool = {
        {"1", "2", "3", "4"},
        {"46", "70", "29", "76"},
        {"10", "0", "0", "1"}
    };

    std::sort(ip_pool.begin(), ip_pool.end(),
        [](const auto& a, const auto& b) {
            return parse_ip_to_int(a) > parse_ip_to_int(b);
        });

    BOOST_TEST(parse_ip_to_int(ip_pool[0]) == parse_ip_to_int(std::vector<std::string>{"46", "70", "29", "76"}));
}