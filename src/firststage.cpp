#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include "stages.hpp" // header dosyası
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
void firststage() {
    cout << "For offline installation, you will need another USB(except archiso USB.)\n";
    cout << "THIS OPERATION WILL FORMAT AND ERASE ALL YOUR DATA IN USB! ARE YOU SURE?(y(es) or n(o))\n";
    char formatoption;
    cin >> formatoption;
    switch(formatoption){
        case 'y':
        case 'Y':{
            cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc).\n";
            cout << "One of the following is your USB stick.\n";
	    command("lsblk");
            string usbpath;
            cin >> usbpath;
            cout << "Formatting USB..." << endl;
            int result = command("mkfs.ext4 " + usbpath);
            if (result !=0){
                cout <<  "Failed to format USB." << endl;
                return;
            }else{
		    cin.ignore();
                cout << "Mounting USB...\n";
                string mcmd = "mount " + usbpath + " /mnt" ;
                int mresult = command("mount " + usbpath + " /mnt");
                if (mresult !=0){
                    cerr << "Failed to mount USB." << endl;
                    return ;
                }else{
			cin.ignore();
                    command("mkdir /mnt/pacostrap");
                    command("cp pacostrap /mnt/pacostrap/");
                    vector<string> paketler;
                    string input;
                    cout << "Enter packages you want to install order by order. Enter 'break' to end installing packages.\n";
                    while (true) {
                        cout << ">> ";
                        getline(cin, input);
                        if(input == "break")
                            break;
                        if(input.empty() || input.find_first_not_of(" \t") == string::npos) {
                            cout << "Space is not a package!" << endl;
                            continue;
                        }paketler.push_back(input);
                    }if(paketler.empty()){
                        cerr << "No packages given." << endl;
                        return ;
                    }string komut = "pacman -Sw --cachedir /mnt --noconfirm";
                    for(const auto& pkg : paketler){
                        komut += " " + pkg;
                    }int sonuc = command(komut.c_str());
                    if (sonuc != 0) {
                        cerr << "Failed to install packages." << endl;
                        return ;
                    }else{
			    cin.ignore();
		    cout << "1st stage: Succesfully ended!\n";
                    return ;
                }
            }
        }
        }break;
    case 'n':
    case 'N':{
        cout << "Have a nice day." << endl;
        return ;
    }
}
}
