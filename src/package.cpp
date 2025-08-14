#include <iostream> //temel cout, cin vb.
#include <string> // harf değişkenleri için
#include <vector> // birden fazla değer atamak için bir değişkene
#include <cstdlib> // exit()
#include "functions.hpp" // functions file
#include "stages.hpp" // header file
#include "command.hpp" // for my own super duper awesome function(joke)
using namespace std;
void package() {
    command("mkdir /mnt/pacostrap");
    command("cp pacostrap /mnt/pacostrap/");
    vector<string> packages;
    string input;
    cout << "Enter packages you want to install order by order. Enter 'break' to end installing packages.\n";
    while (true) {
        cout << ">> ";
        getline(cin, input);
        if (input == "break")
            break;
        if (input.empty() || input.find_first_not_of(" \t") == string::npos) {
            cout << "Space is not a package!" << endl;
            continue;
        }packages.push_back(input);
    }if(packages.empty()){
        cerr << "No packages given." << endl;
        exit(1);
        return ;
    }string komut = "pacman -Sw --cachedir /mnt --noconfirm";
    for(const auto& pkg : packages){
        komut += " " + pkg;
    }int sonuc = command(komut.c_str());
    if (sonuc != 0) {
        cerr << "Failed to install packages." << endl;
        exit(1);
        return ;
    } else {
        cin.ignore();
        cout << "1st stage: Succesfully ended!\n";
    }
    return ;
}
