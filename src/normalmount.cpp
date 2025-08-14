#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit()
#include "functions.hpp" // functions header file
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
void normalmount() {
    cout << "Mounting USB...\n";
    int mresult = command("mount " + usbpath + " /mnt");
    if (mresult !=0) {
        cerr << "Failed to mount USB." << endl;
        exit(1);
        return ;
    } else {
    cout << "Mount: Succes." << endl;
    }
    return ;
}
