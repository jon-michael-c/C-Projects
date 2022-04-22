#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

#include "structs.h"
#include "recordUtil.cpp"

int main() {

    recordUtil records;

    vector<entry> entries = records.getEntries();


    for(int i = 0; i < 150; i++) {

        cout << entries[i].emplid << endl;
    }


    


}






