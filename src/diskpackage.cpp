#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> // exit function
#include <thread> // for animation
#include "spinner.hpp" // spinner animation
#include "functions.hpp" // functions header file
#include "stages.hpp" // header dosyası
#include "command.hpp" // my awesome super duper perfect function(joke)
using namespace std;
void diskpackage() {
    cout << "\033[36mPacostrap, now calling pacstrap.\033[0m\n";
    atomic<bool> animating(true);
    thread animThread(animatel, std::ref(animating), 100);
    int cpresult = command("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/") ;
    int forresult = command("for f in /mnt/var/cache/pacman/pkg/*.zst; do pacman -Qp \"$f\" | awk '{print $1}'; done > pkglist.txt");
    int pacresult = command("pacstrap -K /mnt $(cat pkglist.txt) --cachedir=/mnt/var/cache/pacman/pkg") ;
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
        cout << "\033[32mCongrats! Your offline Arch GNU+Linux ended.\033[0m" << endl;
    } return ;
}

