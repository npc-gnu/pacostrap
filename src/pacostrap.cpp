#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include "stages.hpp"

using namespace std;
int main(){
	if(getuid() == 0){
		cout << "Welcome to pacostrap beta! Which stage are you on?" << endl;
		cout << "1: Before installation, 2: In archiso." << endl;
		int stage;
		cin >> stage;

		switch(stage){
			case 1:{
				firststage();
				return 0;
			}
			case 2:{
				secondstage();
				return 0;
			}
			default:{
				cout << "This option doesn't exist!" << endl;
			}
		}
	}
else{
	cout << "You have to be root." << endl;
}
}
