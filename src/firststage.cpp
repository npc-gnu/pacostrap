#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> //system vb. için
#include "stages.hpp" // header dosyası
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
            }
            else{
                cout << "Mounting USB..." << endl;
                string mcmd = "mount " + usbpath + " /mnt" ;
                int mresult = system(mcmd.c_str());
                if (mresult !=0){
                    cout << "Failed to mount USB." << endl;
                    return ;
                }
                else {
                    system("mkdir /mnt/pacostrap");
                    system("cp pacostrap /mnt/pacostrap/");
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

                    string komut = "pacman -Sw --cachedir /mnt --noconfirm";
                    for (const auto& pkg : paketler) {
                        komut += " " + pkg;
                    }
                    int sonuc = system(komut.c_str());

                    if (sonuc != 0) {
                        cout << "Failed to install packages." << endl;
                        return ;
                    }
                    else{
                    cout << "1st stage: Succesfully ended!" << endl;
                    return ;
                }


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
