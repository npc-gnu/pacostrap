#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit
#include "functions.hpp" // functions file
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
void format() {
    cout << "For offline installation, you will need another USB(except archiso USB.)\n";
    cout << "THIS OPERATION WILL FORMAT AND ERASE ALL YOUR DATA IN USB! ARE YOU SURE?(y(es) or n(o))\n";
    char formatoption;
    cin >> formatoption;
    switch (formatoption) {
        case 'N':
        case 'n':{
            cerr << "Have a nice day. You can use --skip=format argument to skip this formatting." << endl;
            exit(1);
            return ;
        } break ;
        case 'y' :
        case 'Y' : {
            cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc).\n";
            cout << "One of the following is your USB stick.\n";
            command ("lsblk") ;
            string usbpath;
            cin >> usbpath;
            cout << "Formatting USB...\n";
            int result = command("mkfs.ext4 " + usbpath);
            if (result !=0) {
                cerr <<  "Failed to format USB." << endl;
                exit(1);
                return;
            } else {
                cout << "Format: Succes." << endl;
            }
        } break ;
        default:{
            cerr << "Wrong option! Enter y or n !" << endl;
            cerr << "If you want to skip this stage, use --skip argumant." << endl;
            exit(1);
        }
    }
    cin.ignore();
    return ;
}
