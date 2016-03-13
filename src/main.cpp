#include <string>

//#include <gsl.h>
#include <yaml-cpp/yaml.h>
#include <zlib.h>

#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/thread.hpp>

int main()
{
    std::string s = "test string";
    //gsl::span<std::string> sp(s);
    YAML::Node n;
    zError(0);
    boost::asio::io_service io_service;
    io_service.run();
    BOOST_LOG_TRIVIAL(info) << "123";
    boost::thread t([] {});
    t.join();
    return 0;
}
