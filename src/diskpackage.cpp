#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> // exit function
#include <thread> // for animation
#include <atomic> // for animation
#include <chrono> // for animation
#include "functions.hpp" // functions header file
#include "stages.hpp" // header dosyası
#include "command.hpp" // my awesome super duper perfect function(joke)
using namespace std;
atomic<bool> animatingstick(true);
void animationstick(const string& message) {
    const char symbols[] = {'|', '/', '-', '\\'};
    int i = 0;
    while (animatingstick) {
        cout << "\r" << message << " " << symbols[i % 4] << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
        i++;
    }
    cout << "\r " << " \n";
    }
void diskpackage() {
    animatingstick = true;
    thread animThreadstick(animationstick, "\033[36mPacostrap, now calling pacstrap.\033[0m");
    int cpresult = command("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/") ;
    int forresult = command("for f in /mnt/var/cache/pacman/pkg/*.zst; do pacman -Qp \"$f\" | awk '{print $1}'; done > pkglist.txt");
    int pacresult = command("pacstrap -K /mnt $(cat pkglist.txt) --cachedir=/mnt/var/cache/pacman/pkg") ;
    if (cpresult !=0) {
        animatingstick = false;
    	animThreadstick.join();
        cout << "\033[31;40mPackage copy operation failed.\033[0m" << endl;
        exit(1);
    } else if (forresult !=0) {
    	animatingstick = false;
    	animThreadstick.join();
        cout << "\033[31;40mTaking package names failed.\033[0m" << endl;
        exit(1);
    } else if (pacresult !=0) {
    	animatingstick = false;
    	animThreadstick.join();
        cout << "\033[31;40mPacstrap, so pacostrap failed.\033[0m" << endl;
        exit(1);
    } else {
    	animatingstick = false;
    	animThreadstick.join();
        cout << "\033[32mCongrats! Your offline Arch GNU+Linux ended.\033[0m" << endl;
    }
    return ;
}

