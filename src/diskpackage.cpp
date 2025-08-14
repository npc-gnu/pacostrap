#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> // exit function
#include "functions.hpp" // functions header file
#include "stages.hpp" // header dosyası
#include "command.hpp" // my awesome super duper perfect function(joke)
using namespace std;
void diskpackage() {
    cout << "Pacostrap, now calling pacstrap." << endl;
    int cpresult = command("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/") ;
    int forresult = command("for f in /mnt/var/cache/pacman/pkg/*.zst; do pacman -Qp \\\"$f\\\" | awk '{print $1}'; done > pkglist.txt");
    int pacresult = command("pacstrap -K /mnt $(cat pkglist.txt) --cachedir=/mnt/var/cache/pacman/pkg") ;
    if (cpresult !=0) {
        cout << "Package copy opeartion failed." << endl;
    } else if (forresult !=0) {
        cout << "Taking package names failed." << endl;
    } else if (pacresult !=0) {
        cout << "Pacstrap, so pacostrap failed." << endl;
    } else {
        cout << "CONGRATS! YOUR OFFLINE INSTALLATION COMPLETED!" << endl;
    }
}
