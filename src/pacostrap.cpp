#include <iostream>
#include <string>
#include <unistd.h>
#include "stages.hpp"
using namespace std;
int main(int argc, char* argv[]){
	if(getuid() == 0){
		string stage_arg;
		for (int i = 1; i < argc; ++i) {
			string arg = argv[i];
			if (arg.find("--stage=") == 0) {
				stage_arg = arg.substr(8);
			}
		}if(stage_arg.empty()){
							cerr << "You need to specify stage!. Example: pacostrap --stage=1 ." << endl;
							return 1;
						}else if(stage_arg == "1"){
							firststage();
							return 0;
						}else if(stage_arg == "2"){
							secondstage();
							return 0;
						}else{
							cerr << "Wrong argument!" << endl;
							return 1;
						}	
	}else{
	cerr << "You have to be root." << endl;
	return 1;
}
}
