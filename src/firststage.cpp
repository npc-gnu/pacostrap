#include <iostream> //cout, cin etc.
#include <string>
#include <vector> // adding multiple value the varible
#include <cstdlib> //for system and etc
#include "stages.hpp" // header file
using namespace std;
void setcolor(int textcolor)
{
    cout << "\033[" << 
    textcolor << "m";
}
void cleacolor(){
    cout << "\033[0m";
}
void firststage() {
    
    setcolor(31);
    cout << "WARNING YOU NEED \033[0m \033[32m USB \033[0m HAVE \033[33m Difrent PARTITION \033[0m IN FAT32 OR XFAT YOU \033[31m CAN'T \033[0m USE MAIN PARTITION BECOUSE YOU \033[31m CAN'T MOUNT IT IN ARCH ISO \033[0m" << endl;
    cleacolor();
    cout << "Enter your USB \033[32m your-usb-partition \033[0m (WITH OUT '/dev/')." << endl;
    cout << "if  You need to learn \033[32m *your-usb-partition* \033[0m with \033[32m lsblk \033[0m command." << endl;
    setcolor(32);
    cout << ">> ";
    cleacolor();
    string usb;
    cin >> usb;



    cout << "\033[32m geting usb_UUID\033[0m" << endl;
        string get_usb_uuid_cmd = "blkid -d -o value -s UUID /dev/" + usb;
    FILE *pipe = popen(get_usb_uuid_cmd.c_str(),"r");
    if (!pipe){
        cout << "Failed to run popen" << endl;
    }

    char buffer[128];
    std:string usbuuid;
    while (fgets(buffer,sizeof(buffer),pipe) != nullptr)
    {
        if (fgets(buffer,sizeof(buffer),pipe) != nullptr){
            usbuuid += buffer;
        }
    }
    int id = pclose(pipe);



        cout << "\033[32m creating a connection point ... \033[0m" << endl;
        int create_connect_point_id=system("mkdir /mnt/pacofstrap");
        if (create_connect_point_id !=0){ //ERROR CHECK
            cout << "\033[31m Failed to create a connection point \033[0m" << endl;
            return;
        }
        else{
            cout << "\033[32m Mounting USB... \033[0m" << endl;
            string mcmd = "mount UUID='" + usbuuid + "' /mnt/pacofstrap" ;
            string umcmd = "umount UUID='" +usbuuid + "' /mnt/pacofstrap" ;
            cout << mcmd.c_str() << endl;
            int mresult = system(mcmd.c_str());
            if (mresult !=0){ //ERROR CHECK
                cout << "\033[31m Failed to mount USB. \033[0m" << endl;
                system("rm -rf /mnt/pacofstrap");
                return ;
            }
            else {
                cout << "\033[32m creating packages folder... \033[0m" << endl;
                system("mkdir /mnt/pacofstrap/ofpkgs");
                cout << "copying main files.." << endl;
                int copy_main_files_id = system("cp pacofstrap /mnt/pacofstrap/");
                if (copy_main_files_id !=0){ //ERROR CHECK
                cout << "\033[31m Failed to copy main files. \033[0m" << endl;
                return ;
                }
                vector<string> pkgs;
                string input;
                cout << "Enter packages you want to install order by order. Enter 'break' to end installing packages." << endl;

    while (true) {
            cout << "\033[32m >> ";
            getline(cin, input);
            if (input == "break")
                break;
            if (input.empty() || input.find_first_not_of(" \t") == string::npos) {
                cout << "Space is no a package!" << endl;
                continue;
            }
                pkgs.push_back(input);
            }
            if (pkgs.empty()) {
                cout << "No packages given." << endl;
                return ;
            }
            string pacman_command = "pacman -Sw --cachedir /mnt/pacofstrap/ofpkgs --noconfirm";
            for (const auto& pkg : pkgs) {
                pacman_command += " " + pkg;
            }
            int pacman_command_return_id = system(pacman_command.c_str());

            if (pacman_command_return_id != 0) { //ERROR CHECK
                    cout << "\033[31m Failed to install packages. \033[0m" << endl;
                    system(umcmd.c_str());
                    system("rm -rf /mnt/pacofstrap");
                    return ;
                    
                }
                else{
                cout << "\033[32m 1st stage: Succesfully ended! \033[0m" << endl;
                system(umcmd.c_str());
                system("rm -rf /mnt/pacofstrap");
                return ;
                
            }

            }
        }
}
