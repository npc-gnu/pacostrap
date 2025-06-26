#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "stages.hpp"
using namespace std;

void firststage() {
    cout << "For offline installation, you will need another USB(except archiso USB.)" <<  endl;
    cout << "THIS OPERATION WILL FORMAT AND ERASE ALL YOUR DATA IN USB! ARE YOU SURE?(y(es) or n(o))" << endl;
    char formatoption;
    cin >> formatoption;

    switch(formatoption){
        case 'y':
        case 'Y':{
            cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc)." << endl;
            cout << "You can learn *your-usb* with lsblk command." << endl;
            string usbpath;
            cin >> usbpath;

            cout << "Formatting USB..." << endl;
            string cmd = "mkfs.ext4 " + usbpath ;
            int result = system(cmd.c_str());
            if (result !=0){
                cout <<  "Failed to format USB." << endl;
                return ;
            } else{
                cout << "USB format: success!" << endl;
                cout << "Mounting USB..." << endl;
                string mcmd = "mount " + usbpath + " /mnt" ;
                system("mkdir -p /mnt");  // mount edilecek dizin varsa sorun olmaz
                int mresult = system(mcmd.c_str());
                if (mresult !=0){
                    cout << "Failed to mount USB." << endl;
                    return ;
                } else {
                    cout << "Mount: Success!" << endl;
                    vector<string> paketler;
                    string input;

                    cout << "Enter packages you want to install order by order. Enter 'break' to end installing packages." << endl;

                    while (true) {
                        cout << ">> ";
                        getline(cin, input);
                        if (input == "break")
                            break;

                        if (input.empty() || input.find_first_not_of(" \t") == string::npos) {
                            cout << "Space is not a package!" << endl;
                            continue;
                        }

                        paketler.push_back(input);
                    }

                    if (paketler.empty()) {
                        cout << "No packages given." << endl;
                        return ;
                    }

                    // Paket isimlerini tek string'e birleştir
                    string komut = "sudo pacman -Sw --cachedir /mnt --noconfirm";
                    for (const auto& pkg : paketler) {
                        komut += " " + pkg;
                    }
                    int sonuc = system(komut.c_str());

                    if (sonuc != 0) {
                        cout << "Paket indirme başarısız." << endl;
                        return ;
                    }

                    cout << "Paketler başarıyla indirildi!" << endl;
                    return ;
                }


            }
        }

    break;
    case 'n':
    case 'N':{
        cout << "Have a nice day." << endl;
        return ;
    }
    }
}
