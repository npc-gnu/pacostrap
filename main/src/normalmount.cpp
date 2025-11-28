#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit()
#include <thread>  // for animation(stopping)
#include "animatel.hpp" // for animation(main)
#include "firststagefuncs.hpp" 
#include "command.hpp" // for my own super duper awesome function(joke)
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
