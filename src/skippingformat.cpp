#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit()
#include "functions.hpp"
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
void skippingformat(){
    cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc).\n";
    cout << "One of the following is your USB stick.\n";
    string skipusbpath;
    cin >> skipusbpath;
    cout << "Mounting USB...\n";
    int mresult = command("mount " + skipusbpath + " /mnt");
    if (mresult !=0){
        cerr << "Failed to mount USB." << endl;
        exit(1);
        return ;
    } else {
        cout << "Mount: Succes." << endl;
    }
    return ;
}
