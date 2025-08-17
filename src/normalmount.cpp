#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <cstdlib> // for exit()
#include "functions.hpp" // functions header file
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
void normalmount() {
    cout << "\033[36mMounting USB...\033[0m\n";
    int mresult = command("mount " + usbpath + " /mnt");
    if (mresult !=0) {
        cerr << "\033[31;40mMounting USB: Failed.\033[0m" << endl;
        exit(1);
        return ;
    } else {
    cout << "\033[32mMounting UBS: Succes.\033[0m" << endl;
    }
    return ;
}
