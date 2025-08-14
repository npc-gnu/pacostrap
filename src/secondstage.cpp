#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include "stages.hpp" // header dosyası
#include "command.hpp" // my awesome super duper perfect function(joke)
using namespace std;
vector<string> paketler;
string usbpath;
void secondstage(){
	cout << "One of the following is your main disk.\n";
    cout << "Enter your disk's path.(path is /dev/*your-disk* .Example: /dev/sda1).\n";
    string diskpath;
    cin >> diskpath;
    int cmd = command("mount " + diskpath + " /mnt");
    command("mkdir -p /mnt/var/cache/pacman/pkg");
    if(cmd !=0){
        cout << "Mounting disk failed." << endl;
    }else{
        cout << "Pacostrap, now calling pacstrap." << endl;
        int cpresult = command("cp /usbmnt/*.zst /mnt/var/cache/pacman/pkg/") ;
        int forresult = command("for f in /mnt/var/cache/pacman/pkg/*.zst; do pacman -Qp \\\"$f\\\" | awk '{print $1}'; done > pkglist.txt");
        int pacresult = command("pacstrap -K /mnt $(cat pkglist.txt) --cachedir=/mnt/var/cache/pacman/pkg") ;
        if (cpresult !=0){
            cout << "Package copy opeartion failed." << endl;
        }else if(forresult !=0){
            cout << "Taking package names failed." << endl;
        }else if(pacresult !=0){
            cout << "Pacstrap, so pacostrap failed." << endl;
        }else{
            cout << "CONGRATS! YOUR OFFLINE INSTALLATION COMPLETED!" << endl;
        }
    }
}
