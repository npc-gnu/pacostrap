#include <iostream>
#include <string>
#include <cstdlib>
#include "command.hpp"
#include "stages.hpp"
#include "functions.hpp"
using namespace std;
void a_usbmount(){
	command("mkdir /usbmnt");
	cout << "Enter your USB's path.(Path is /dev/*your-usb*. Example: /dev/sdc).\n";
	cout << "\033[35;40m 			BEGAN TO LSBLK			\033[0m\n";
	command("lsblk");
	cout << "\033[35;40m 			END OF LSBLK			\033[0m\n";
	cin >> a_usbpath;
	cout << "Mounting usb...\n";
	int a_usbmnt_result = command ("mount " + a_usbpath + " /usbmnt");
	if (a_usbmnt_result !=0) {
		cerr << "Failed to mount USB. If you already mounted your USB, you can use (this skipping argumant did not added yet.) skipping argumant." << endl;
		exit(1);
		return ;
	} else {
		cout << "Mounting USB: Succes." << endl;
	}
}
