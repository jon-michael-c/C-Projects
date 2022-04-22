#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "structs.h"
#include "csvIO.cpp"

class recordUtil {

    private:
        vector<entry> entries;
        vector<student> students;
        vector<instructor> instructors;
        vector<course> courses;
        vector<term> terms;
    public:
        recordUtil() {
            this->entries = readEntries("./03-Student-Grades/src/data/1115.csv");
        }

        vector<entry> getEntries() {
            return this->entries;
        }





        


};
