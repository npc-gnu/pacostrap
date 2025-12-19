#include <iostream> 
#include <cstdlib> 
#include <thread> 
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include <command.hpp>
#include "spinner.hpp"
using namespace std;
using json = nlohmann::json;
void diskpackage(){
	json j;
	ifstream file("/usbmnt/packages.json");
	file >> j;
	vector<string> packages = j["packages"];
	cout << "\033[36mPacostrap, now calling pacstrap.\033[0m\n";
	atomic<bool> animating(true);
	thread animThread(animatel, std::ref(animating), 100);
	int cpresult = system("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/");
	int pacresult = command("pacstrap -K /mnt " + packages + " --cachedir=/mnt/var/cache/pacman/pkg");
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
