
#include <boost/phoenix/bind.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/fusion.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/range/adaptor/filtered.hpp>

#include <map>
#include <iostream>

namespace phx = boost::phoenix;

int main()
{
    std::map<std::string, std::string> map{{"key1", "data1"}, {"key2", "data2"}, {"key3", "data3"}, {"key4", "data4"}};

    auto key = phx::bind([](const auto &value) { return value.first; },
                         phx::placeholders::arg1);
    auto filtered = map | boost::adaptors::filtered(
                              key == std::string("key1") ||
                              key == std::string("key2"));
                              
    for (const auto &[key, value] : filtered)
    {
        std::cout << key << " " << value << std::endl;
    }
}
