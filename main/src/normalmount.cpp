#include <iostream>
#include <string> 
#include <cstdlib>
#include <thread> 
#include "animatel.hpp"
#include "firststagefuncs.hpp" 
#include "command.hpp" 
using namespace std;
void normalmount() {
	cout << "\033[36mMounting USB\033[0m\n";
	animating = true;
	thread animThread(animatel, '.', 50);
	int mresult = command("mount " + usbpath + " /mnt");
	if (mresult !=0) {
		animating = false;
		animThread.join();
		cerr << "\033[31;40mMounting USB: Failed.\033[0m" << endl;
		exit(1);
	} else {
		animating = false;
		animThread.join();
		cout << "\033[32mMounting USB: Succes.\033[0m" << endl;
	}
}
