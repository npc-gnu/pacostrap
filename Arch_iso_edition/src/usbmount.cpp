#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>  // for animation(stopping)
#include "archisofuncs.hpp"
#include "command.hpp"
#include "animatel.hpp"
using namespace std;
void a_usbmount(){
	command("mkdir /usbmnt");
	cout << "\033[36;47mEnter your USB's path.(Path is /dev/*your-usb*. Example: /dev/sdc).\033[0m\n";
	cout << "\033[35;40m                   BEGAN TO LSBLK                   \033[0m\n";
	command("lsblk");
	cout << "\033[35;40m                    END OF LSBLK                    \033[0m\n";
	string a_usbpath;
	cin >> a_usbpath;
	cout << "Mounting usb...\n";
	animating = true;
	thread animThread(animatel, '.', 50);
	int a_usbmnt_result = command ("mount " + a_usbpath + " /usbmnt");
	if (a_usbmnt_result !=0) {
		animating = false;
		animThread.join();
		cerr << "\033[31;40mFailed to mount USB.\033[0m" << endl;
		cerr << "\033[36mIf you already mounted your USB, you can use -P=U-M skipping argumant.\033[0m" << endl;
		exit(1);
	} else {
		animating = false;
		animThread.join();
		cout << "\033[32mMounting USB: Succes.\033[0m" << endl;
	}
}
