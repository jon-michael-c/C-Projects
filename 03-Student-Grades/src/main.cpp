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

    cout << "Setting Up Records...";
    recordUtil records;
    cout << "Done" << endl;
    cout << endl;
    
    cout << "Add/Update Entry? Y/N";
    cin >> done;
    while(done == "Y" || done == "y") {
        entry newEntry; 
         
        cout << "EMPLID: ";
        cin >> newEntry.emplid;  

        cout << "COURSENO: ";
        cin >> newEntry.courseno;  

        cout << "INSTRUCTORID: ";
        cin >> newEntry.instructorid;  

        cout << "TERMID: ";
        cin >> newEntry.termid;  

        cout << "SECTIONID: ";
        cin >> newEntry.sectionid;  

        cout << "GRADE: ";
        cin >> newEntry.grade;  

        records.addEntry(newEntry);

        cout << "Add/Update Another Entry? Y/N" << endl;
        cin >> done;
    
    }

    records.printPassPerInstructor(); 
    records.printPassPerCourse();
    records.printWithRatePerInstructor();
    records.printWithRatePerCourse();
    records.printPassRateFall();
    records.printPassRateSpring();


    return 0;

}





