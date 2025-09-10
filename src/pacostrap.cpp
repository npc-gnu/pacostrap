#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>
#include "stages.hpp"
#include "functions.hpp"
namespace pifiles = std::filesystem;
using namespace std;
int main(int argc, char* argv[]) {
	if (getuid() == 0) {
		string pacman_path = "/usr/bin/pacman";
		if (pifiles::exists(pacman_path)) {
		string stage_arg;
		string shorter_stage_arg;
		string skip_arg;
		string shorter_skip_arg;
		for (int i = 1; i < argc; ++i) {
			string arg = argv[i];
			if (arg.find("--stage=") == 0) {
				stage_arg = arg.substr(8) ;
			} else if (arg.find("--pass=") == 0) {
				skip_arg = arg.substr(7) ;
		} else if (arg.find("-S=") == 0) {
			shorter_stage_arg = arg.substr(3);
		} else if (arg.find("-P=") == 0) {
			shorter_skip_arg = arg.substr(3);
		}
		} if(stage_arg.empty() && shorter_stage_arg.empty()) {
							cerr << "\033[31;40mYou need to specify stage!. Example: ./pacostrap --stage=1 or ./pacostrap -S=1  .\033[0m" << endl;
							return 1 ;
						} else if (stage_arg == "1" || shorter_stage_arg == "1") {
							if (skip_arg.empty() && shorter_skip_arg.empty() || skip_arg == "none" || shorter_skip_arg == "N" || shorter_skip_arg == "n") { 
							firststage();
							return 0;
							} else if (skip_arg == "format" || shorter_skip_arg == "f" || shorter_skip_arg == "F") {
								skippingformat() ;
								package() ;
								return 0 ;
							} else if (skip_arg == "mount" || shorter_skip_arg == "m" || shorter_skip_arg == "M") {
								package() ;
								return 0 ;
							} else {
								cerr << "\033[31;40mWrong skip argumant! You can use --pass=format or --pass=mount\033[0m" << endl;
								return 1 ;
							}
						}else if(stage_arg == "2" || shorter_stage_arg == "2"){
							if (skip_arg.empty() && shorter_skip_arg.empty() && skip_arg == "none" || shorter_skip_arg == "none" || shorter_skip_arg == "n" || shorter_skip_arg == "N") {
							secondstage() ;
							return 0 ;
							} else if (skip_arg == "mount" || shorter_skip_arg == "M" || shorter_skip_arg == "m" ) {
								diskpackage() ;
								return 0 ;
							} else {
								cerr << "\033[31;40mWrong argumant!\033[0m" << endl ;
								return 1 ;
							}
						} else {
							cerr << "\033[31;40mWrong argument!\033[0m" << endl;
							return 1;
						}
		} else {
		cerr << "\033[31;40mpacostrap do not supports non-arch based distros(yet)\033[0m" << endl;
		}
	} else {
	cerr << "\033[31;40mYou have to be root.\033[0m" << endl;
	return 1;
}
}
