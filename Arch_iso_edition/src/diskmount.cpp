#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> // exit
#include "stages.hpp" // header dosyası
#include "functions.hpp" // functions header file
#include "command.hpp" // my awesome super duper perfect function(joke)
using namespace std;
void a_diskmount() {
    cout << "\033[36mOne of the following is your main disk.\033[0m\n";
    cout << "\033[36;47mEnter your disk's path.(path is /dev/*your-disk* .Example: /dev/sda1).\033[0m\n";
    cout << "\033[35;40m	Began To LSBLK	\033[0m\n";
    command ("lsblk") ;
    cout << "\033[35;40m	End Of LSBLK	\033[0m\n";
    string diskpath;
    cin >> diskpath;
    int cmd = command("mount " + diskpath + " /mnt");
    command("mkdir -p /mnt/var/cache/pacman/pkg");
    if (cmd !=0) {
        cerr << "\033[31;40mMounting disk: Failed.\033[0m" << endl;
        exit(1);
        return ;
    } else {
        cout << "\033[32mMounting disk: Succes.\033[0m" << endl;
    }
    return ;
}
