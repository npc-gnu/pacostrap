#include <iostream>
#include <string>
#include <unistd.h>
#include "stages.hpp"
#include "functions.hpp"
using namespace std;
int main(int argc, char* argv[]) {
	if (getuid() == 0) {
		string skip_arg = "none";
		string shorter_skip_arg = "none";
		for (int i = 1; i < argc; ++i) {
			string arg = argv[i];
			if (arg.find("--pass=") == 0) {
				skip_arg = arg.substr(7) ;
		} else if (arg.find("-P=") == 0) {
			shorter_skip_arg = arg.substr(3);
		}
		} if (skip_arg.empty() && shorter_skip_arg.empty()) {
							a_secondstage();
							return 0;
		} else if (skip_arg == "diskmount" || shorter_skip_arg == "M" || shorter_skip_arg == "m") {
			diskpackage();
			return 0;
		} else {
			cerr << "Wrong skip argumant!" << endl;
		}
	} else {
	cerr << "\033[31;40mYou have to be root.\033[0m" << endl;
	return 1;
}
}
