#include <iostream> //base cout, cin etc.
#include <string>
#include <vector> // adding multiple value the varible
#include <cstdlib> //for system and other things
#include "stages.hpp" // header file
using namespace std;

vector<string> paketler;
string usbpath;

void secondstage(){
    system("lsblk");
    cout << "Enter your disk's path.(path is /dev/*your-disk* .Example: /dev/sda1)." << endl;
    string diskpath;
    cin >> diskpath;
    string cmd = "mount " + diskpath + " /mnt" ;
    system("mkdir -p /mnt/var/cache/pacman/pkg");
    int result = system(cmd.c_str());
    if(result !=0){
        cout << "Mounting disk failed." << endl;
    }
    else{
        cout << "Pacostrap, now calling pacstrap." << endl;
        int cpresult = system("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/") ;
        int forresult = system("for f in /mnt/var/cache/pacman/pkg/*.zst; do pacman -Qp \\\"$f\\\" | awk '{print $1}'; done > pkglist.txt");
        int pacresult = system("pacstrap -K /mnt $(cat pkglist.txt) --cachedir=/mnt/var/cache/pacman/pkg") ;
        if (cpresult !=0){
            cout << "Package copy opeartion failed." << endl;
        }
        else if(forresult !=0){
            cout << "Taking package names failed." << endl;
        }
        else if(pacresult !=0){
            cout << "Pacstrap failed." << endl;
        }
        else{
            cout << "CONGRATS! YOUR OFFLINE INSTALLATION COMPLETED!" << endl;
        }
    }
}

