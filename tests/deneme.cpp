#include <iostream> //cout, cin etc.
#include <string>
#include <vector> // adding multiple value the varible
#include <cstdlib> //for system and etc
using namespace std;


int main(){
    FILE *pipe = popen("blkid -o value -s UUID /dev/sdb3","r");
    if (!pipe){
        cout << "Failed to run popen" << endl;
    }

    char buffer[128];
    std:string usbuuid;
    while (fgets(buffer,sizeof(buffer),pipe) != nullptr)
    {
        usbuuid += buffer;
    }


    int id = pclose(pipe);
    cout << " " << endl;
    cout << usbuuid << endl;

}