#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>
#include "../ip_filter_lib.h"

BOOST_AUTO_TEST_CASE(split_test)
{
    auto parts = split("1.2.3.4", '.');

    BOOST_TEST(parts.size() == 4);
    BOOST_TEST(parts[0] == "1");
    BOOST_TEST(parts[1] == "2");
    BOOST_TEST(parts[2] == "3");
    BOOST_TEST(parts[3] == "4");
}