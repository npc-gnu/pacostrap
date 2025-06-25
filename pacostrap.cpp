#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;


int main(){ //int mainin 1. süslü parantezi
	if(getuid() == 0){
	cout << "Welcome to pacostrap beta! Which stage are you on?" << endl;
	cout << "1: Before installation, 2: In archiso." << endl;
	int stage;
	cin >> stage;
	switch(stage){ //adımın(stage) 1. süslü parantezi
		case 1:{ // stage/case 1 in 1. süslü parantezi
				       cout << "For offline installation, you will need another USB(except archiso USB.)" <<  endl;
				       cout << "THIS OPERATION WILL FORMAT AND ERASE ALL YOUR DATA IN USB! ARE YOU SURE?(y(es) or n(o))" << endl;
				       char formatoption;
				       cin >> formatoption;
				       switch(formatoption){ // stage/case/if/formatoptionun 1. süslü paranteezi
					       case 'y':
					       case 'Y':{  // stage/case/if/formatoption/case yes'in 1. süslü parantezi
								cout << "Enter your USB's path.(path is /dev/*your-usb* .Example: /dev/sdc)." << endl;
								cout << "You can learn *your-usb* with lsblk command." << endl;
								string usbpath;
								cin >> usbpath;
								cout << "Formatting USB..." << endl;
								string cmd = "mkfs.ext4 " + usbpath ;
								int result = system(cmd.c_str());
								if (result !=0){ //usb formatın/if ilk süslü parantezi
										 cout <<  "Failed to format USB." << endl;
										 return 1;
								} // usb formatın/if ikinci süslü parantezi
								 else{ //usb formatın/else ilk süslü parantezi
									 cout << "USB format: succes!" << endl;
									 cout << "Mounting USB..." << endl;
									 string mcmd = "mount " + usbpath + " /mnt" ;
									 int mresult = system(mcmd.c_str());
									 if (result !=0){
										 cout << "Failed to mount USB." << endl;
										 return 1;
									 }
									 else{
										 cout << "Mount: Succes!" << endl;
										 cout << "Enter the packages that you want to install." << endl;
										 // sen burayı hallet pacman -Sw falan vardı
									 }
								 }
							}
							break;
					       case 'n':
					       case 'N':{
								cout << "Have a nice day." << endl;
								return 1;
							}
							break;
						   default:{
							   cout << "This option doesn't exists!" << endl;
							   return 1;
						}
						break;
				       }
				   }
	}
	}
	else{
		cout << "You have to be root." << endl;
	}
}
