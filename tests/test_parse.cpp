#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>
#include "../ip_filter_lib.h"

BOOST_AUTO_TEST_CASE(parse_test)
{
    std::vector<std::string> ip = {"1", "2", "3", "4"};
    BOOST_TEST(parse_ip_to_int(ip) == 16909060u);
}