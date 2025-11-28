#include <iostream> 
#include <cstdlib> 
#include <thread> 
#include "spinner.hpp"
using namespace std;
void diskpackage() {
	cout << "\033[36mPacostrap, now calling pacstrap.\033[0m\n";
	atomic<bool> animating(true);
	thread animThread(animatel, std::ref(animating), 100);
	int cpresult = system("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/") ;
	int forresult = system("for f in /mnt/var/cache/pacman/pkg/*.zst; do pacman -Qp \"$f\" | awk '{print $1}'; done > pkglist.txt");
	int pacresult = system("pacstrap -K /mnt $(cat pkglist.txt) --cachedir=/mnt/var/cache/pacman/pkg") ;
	/* In case you wondering, why the fuck are you using system() instead of you "awesome" command()?
	* Because of these are literally scripts, not just some pacman -S so i have to use system (or command() with /bin/sh -c)
	* I will start using json so i can return back to command but until that time, using system() 
	*/
	if (cpresult !=0) {
		animating = false;
		animThread.join();
		cout << "\n";
		cout << "\033[31;40mPackage copy operation failed.\033[0m" << endl;
		exit(1);
	} else if (forresult !=0) {
		animating = false;
		animThread.join();
		cout << "\n";
		cout << "\033[31;40mTaking package names failed.\033[0m" << endl;
		exit(1);
	} else if (pacresult !=0) {
		animating = false;
		animThread.join();
		cout << "\n";
		cout << "\033[31;40mPacstrap, so pacostrap failed.\033[0m" << endl;
		exit(1);
	} else {
		animating = false;
		animThread.join();
		cout << "\n";
		cout << "\033[32mCongrats! Your offline Arch GNU+Linux installation ended.\033[0m" << endl;
	} 
}
