#include <iostream>
#include <string>
#include <unistd.h>
#include "archisofuncs.hpp"
using namespace std;
int main(int argc, char* argv[]) {
	if (getuid() == 0) {
		string skip_arg;
		string shorter_skip_arg;
		for (int i = 1; i < argc; ++i) {
			string arg = argv[i];
			if (arg.find("--pass=") == 0) {
				skip_arg = arg.substr(7) ;
			} else if (arg.find("-P=") == 0) {
				shorter_skip_arg = arg.substr(3);
			}
		} if (skip_arg.empty() && shorter_skip_arg.empty() || skip_arg == "none" || shorter_skip_arg == "none") {
			a_usbmount();
			a_diskmount();
			a_diskpackage();
			return 0;
		} else if (skip_arg == "usbmount" || shorter_skip_arg == "U-M" || shorter_skip_arg == "u-m") {
			a_diskmount();
			a_diskpackage();
			return 0;
		} else if (skip_arg == "diskmount" || shorter_skip_arg == "D-M" || shorter_skip_arg == "d-m") {
			a_usbmount();
			a_diskpackage();
			return 0;
		} else if (skip_arg == "diskmount,usbmount" || skip_arg == "usbmount,diskmount" || shorter_skip_arg == "D,U-M" || shorter_skip_arg == "U,D-M"){
			a_diskpackage();
		} else {
			cerr << "\033[31;40mWrong skip argumant!\033[0m" << endl;
			return 1;
		}
	} else {
		cerr << "\033[31;40mYou have to be root.\n And ummm... why the fuck did you added an user to ArchISO? What is wrong with you?!\033[0m" << endl;
		return 1;
	}
}
