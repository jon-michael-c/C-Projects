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
    
    vector<rate> rates = records.getPassPerInstructor();
    vector<rate> rates2 = records.getPassPerCourse();

    vector<student> students = records.getStudents();
    vector<instructor> instructors = records.getInstructors();
    vector<course> courses = records.getCourses();

    for(auto i : students) {
        cout << i.id << endl;
        cout << i.course << endl;
    }
    
    for(auto i : instructors) {
        cout << i.id << endl;
        cout << i.course << endl;
    }

    for(auto i : courses) {
        cout << i.courseno << " ";
        cout << i.sectionid << endl;
    }

    for(auto i : rates) {
        cout << i.id << " ";
        cout << i.num << " ";
        cout << i.den << " ";
        cout << i.rate << endl;
    }

    for(auto i : rates2) {
        cout << i.id << " ";
        cout << i.num << " ";
        cout << i.den << " ";
        cout << i.rate << endl;
    }

}






