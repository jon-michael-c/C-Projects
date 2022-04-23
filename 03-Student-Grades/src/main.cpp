#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

#include "structs.h"
#include "recordUtil.cpp"


int main() {

    recordUtil records;

    vector<entry> entries = records.getEntries();
    
    vector<rate> rates = records.getPassPerCourse();
    vector<rate> rates2 = records.getPassRateSpring();

    vector<student> students = records.getStudents();
    vector<instructor> instructors = records.getInstructors();
    vector<course> courses = records.getCourses();

    /*
    records.addEntry("E0003", 1115, "I12", "T04", "S10", "A+");
    records.addEntry("E018", 3115, "I12", "T69", "S97", "A+");
    records.addEntry("E018", 3130, "I12", "T69", "S97", "A+");
    cout << entries[2917].emplid << endl;
    cout << entries[2917].courseno << endl;
    */


    updateCSV(records.getEntries());

    

    /*
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

    */
    
    if(!1) {

    cout << regex_match("W", regex("(W)(.*)")) << endl;
    }
    for(auto i : rates) {
        cout << i.id << " ";
        cout << i.num << " ";
        cout << i.den << " ";
        cout << i.rate << endl;
    }

    for(auto i : rates2) {
    cout << i.id << endl;
    cout << i.num << endl;
    cout << i.den << endl;
    cout << i.rate << endl;
    
    }
}





