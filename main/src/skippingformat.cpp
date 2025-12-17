#include <iostream>
#include <string> 
#include <cstdlib>
#include "firststagefuncs.hpp"
#include "command.hpp" 
using namespace std;
void skippingformat(){
	cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc).\n";
	cout << "One of the following is your USB stick.\n";
	string skipusbpath;
	cin >> skipusbpath;
	cout << "Mounting USB...\n";
	int mresult = command("mount " + skipusbpath + " /mnt");
	if (mresult !=0){
		cerr << "Failed to mount USB." << endl;
		exit(1);
	} else {
		cout << "Mount: Succes." << endl;
	}
}
