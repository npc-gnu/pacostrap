#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> // exit
#include "stages.hpp" // header dosyası
#include "functions.hpp"
#include "command.hpp" // my awesome super duper perfect function(joke)
using namespace std;
void diskmount() {
    cout << "One of the following is your main disk.\n";
    cout << "Enter your disk's path.(path is /dev/*your-disk* .Example: /dev/sda1).\n";
    command("lsblk");
    string diskpath;
    cin >> diskpath;
    int cmd = command("mount " + diskpath + " /mnt");
    command("mkdir -p /mnt/var/cache/pacman/pkg");
    if (cmd !=0) {
        cerr << "Mounting disk failed." << endl;
        exit(1);
        return ;
    } else {
        cout << "Mounting disk: Succes." << endl;
    }
    return ;
}
