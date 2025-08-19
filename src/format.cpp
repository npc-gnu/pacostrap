#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit
#include <thread>  // for animation
#include <animatel.hpp> // for animation(main)
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
            cout << "\033[36;47mEnter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc).\033[0m\n";
            cout << "\033[36;47mOne of the following is your USB stick.\033[0m\n";
            cout << "\033[35;40m       Began To LSBLK      \033[0m\n";
            command ("lsblk") ;
            cout << "\033[35;40m       End Of LSBLK      \033[0m\n";
            cin >> usbpath;
            cout << "\033[36mFormatting USB ";
	    animating = true;
	    thread animThread(animatel, '.', 50);
            int result = command("mkfs.ext4 -F -q " + usbpath + " > /dev/null");
            if (result !=0) {
		animating = false;
		animThread.join();
	        cout << "\n";	
                cerr <<  "\033[31;40mFormatting USB: Failed.\033[0m" << endl;
                exit(1);
                return;
            } else {
		animating = false;
		animThread.join();
		cout << "\n";
                cout << "\033[32mFormatting USB: Succes.\033[0m" << endl;
            }
        } break ;
        default:{
            cerr << "\033[31;40mWrong option! Enter y or n !\033[0m" << endl;
            cerr << "\033[36mIf you want to skip this stage, use --pass / -P argumant.\033[0m" << endl;
            exit(1);
        }
    }
    cin.ignore();
    return ;
}
