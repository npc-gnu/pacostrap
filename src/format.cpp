#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit
#include "functions.hpp" // functions file
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
string usbpath;
void format() {
    cout << "\033[93;40mFor offline installation, you will need another USB(except archiso USB.)\033[0m\n";
    cout << "\033[37;41mTHIS OPERATION WILL FORMAT AND ERASE ALL YOUR DATA IN USB! ARE YOU SURE?(y(es) or n(o))\033[0m\n";
    char formatoption;
    cin >> formatoption;
    switch (formatoption) {
        case 'N':
        case 'n':{
            cerr << "\033[36mHave a nice day. You can use --skip=format or -S=F argument to skip this formatting.\033[0m" << endl;
            exit(1);
            return ;
        } break ;
        case 'y' :
        case 'Y' : {
            cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc).\n";
            cout << "One of the following is your USB stick.\n";
            command ("lsblk") ;
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
            cerr << "If you want to skip this stage, use --pass / -P argumant." << endl;
            exit(1);
        }
    }
    cin.ignore();
    return ;
}
