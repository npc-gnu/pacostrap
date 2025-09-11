#include <iostream>
#include <thread>
#include <filesystem>
#include "command.hpp"
#include "spinner.hpp"

namespace pifiles = std::filesystem;
using namespace std;

void tarballprepare(){

    cout << "\033[93;40mDetected non-arch based distro!\033[0m\n";
    cout << "\033[36mArch linux tarball image is getting prepared\033[0m\n";

}
