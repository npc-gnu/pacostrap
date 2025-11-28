#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> 
#include <thread> 
#include "spinner.hpp" 
#include "firststagefuncs.hpp" 
#include "command.hpp" 
using namespace std;
void package() {
	command("mkdir /mnt/pacostrap");
	command("cp pacostrap /mnt/pacostrap/");
	vector<string> packages;
	string input;
	cout << "\033[36mEnter packages you want to install order by order. Enter 'break' to end installing packages.\033[0m\n";
	while (true) {
		cout << ">> ";
		getline(cin, input);
		if (input == "break")
			break;
	if (input.empty() || input.find_first_not_of(" \t") == string::npos) {
		cout << "\033[93;40mSpace is not a package!\033[0m" << endl;
		continue;
	} packages.push_back(input);
	} if(packages.empty()) {
		cerr << "\033[31;40mNo packages given.\033[0m" << endl;
		exit(1);
	} string komut = "pacman -Sw --cachedir /mnt --noconfirm";
	for (const auto& pkg : packages) {
		komut += " " + pkg;
	} int sonuc = command(komut.c_str());
		atomic<bool> animating(true);
		thread animThread(animatel, std::ref(animating), 100);
	if (sonuc != 0) {
		animating = false;
		animThread.join();
		cerr << "\033[31;40mFailed to install packages.\033[0m" << endl;
		exit(1);
	} else {
		animating = false;
		animThread.join();
		cin.ignore();
		cout << "\033[32m1st stage: Succesfully ended!\033[0m\n";
	}
}
