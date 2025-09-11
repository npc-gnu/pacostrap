#include <iostream>
#include <thread>
#include <filesystem>
#include <cstdlib>
#include "command.hpp"
#include "spinner.hpp"

namespace pifiles = std::filesystem;
using namespace std;

void tarballprepare() {

	cout << "\033[93;40mDetected non-arch based distro!\033[0m\n";
	cout << "\033[36mArch linux tarball image is getting prepared\033[0m\n";

	atomic<bool> animThread = true;
	thread animThread(animatel, std::ref(animating), 100);
	
	string arch_rootfs_path = "/home/*/pacostrap/Arch_GNU+Linux-Tarball/root.x86_64"
		if (!pifiles::exists(arch_rootfs_path)) {
			
			animating = false;
			animThread.join();
			
			cerr << "\033[93;40mNo local rootfs found! And, why the hell did you deleted a directory called Arch_GNU+Linux-Tarball? Please open a issue on github about this. I really want to learn this.\033[0m" << endl;
			cerr << "\033[36mInstalling image from internet.\033[0m" << endl;
			
			string git_path = "/usr/bin/git";
			
			if (!pifiles::exists(git_path)) {
				
				cerr << "\033[ No! git does not find either. We need git to install from network.\033[0m" << endl; // FIXME write red ansi color code here
				cerr << "\033[ Advice: You can download from GUI and manually setup rootfs environment. Then, you can install pacostrap and run.\033[0m" << endl; // FIXME here too
				
				exit(1);
				return;
			
			} else {
				animating = true;
				thread animThreadscnd(animatel, std::ref(animating), 100);
				int changing_directory command("cd /home/*/");
				if (changing_directory !=0) {
					cerr << "Failed to enter home directory." << endl; // FIXME Add color.
					exit (1);
					return;
				} else { 
					command("mkdir idiot_user_did_not_cloned_pacostrap_right");
					command("cd idiot_user_did_not_cloned_pacostrap_right");
					int git_clone = command("git clone https://github.com/npc-gnu/pacostrap.git");
					if (git_clone !=0) {
						cerr << "Failed to clone pacostrap, RIGHTLY!" << endl; // FIXME Here too
						 } else { 
							 command("cd pacostrap");
							 // FIXME Enter bootstrap ortam etc.
						 }
				}
			}
		} else {
			// FIXME Enter bootstrap too.
			}
}
