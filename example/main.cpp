#include <sail/version.hpp>

#include <iostream>

int main(int argc, char* argv[]) {

    std::cout << sail::version::get_version() << std::endl;

}