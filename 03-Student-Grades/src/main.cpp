#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

#include "recordUtil.h"
#include "utilFuncs.h"

int main() {
    
    string done = "Y";
    double num1=0, num2=0;
    int mode;   

    cout << "Setting Up Records...";
    recordUtil records;
    cout << "Done" << endl;

    while(done == "Y" || done == "y") {
        cout << "Enter Operation" << endl;
        cout << "0 - Pass Rate Per Instructor" << endl;
        cout << "1 - Pass Rate Per Course" << endl;
        cout << "2 - Withdraw Rate Per Instructor" << endl;
        cout << "3 - Withdraw Rate Per Course" << endl;
        cout << "4 - Fall VS Spring Pass Rate By Course" << endl;
        cout << "5 - Add/Update Entry" << endl;
        cin >> mode;

        switch(mode) {
            case 0:
                printPPI(records);
                break;
            case 1:
                printPPC(records);
                break;
            case 2:
                printWRI(records);
                break;
            case 3:
                printWRC(records);
            default:
                cout << "Enter a correct number" << endl;
                break;


        }

        cout << "Continue? Y/N" << endl;
        cin >> done;
        

        
    
    }


    return 0;

}





