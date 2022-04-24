#include <iostream>
#include <string>

using namespace std;

#include "structs.h"
#include "recordUtil.h"

#ifndef UTIL_HEADER
#define UTIL_HEADER



void printPPI(recordUtil records) {
    cout << "Processing Data...";
    vector<rate> ratePPI = records.getPassPerInstructor();
    cout << "Done";
    cout << "------------ Pass Rate Per Instructor -----------------------" << endl;
    for(auto i : ratePPI) {
        cout << " Instructor: " << i.id;
        cout << " Passed: " << i.num;
        cout << " Total: " << i.den;
        cout << " Pass Rate: " << i.rate << "%" << endl;
    }
    cout << "---------------------------------------------------------" << endl;

}

void printPPC(recordUtil records) {
    cout << "Processing Data...";
    vector<rate> rate = records.getPassPerCourse();
    cout << "Done";
    cout << "------------ Pass Rate Per Course -----------------------" << endl;
    for(auto i : rate) {
        cout << " Course: " << i.id;
        cout << " Passed: " << i.num;
        cout << " Total: " << i.den;
        cout << " Pass Rate: " << i.rate << "%" << endl;
    }
    cout << "---------------------------------------------------------" << endl;

}

void printWRI(recordUtil records) {
    cout << "Processing Data...";
    vector<rate> rate = records.getWRatePerInstructor();
    cout << "Done";
    cout << "------------ Withdraw Rate Per Instructor -----------------------" << endl;
    for(auto i : rate) {
        cout << " Instructor: " << i.id;
        cout << " Passed: " << i.num;
        cout << " Total: " << i.den;
        cout << " Pass Rate: " << i.rate << "%" << endl;
    }
    cout << "---------------------------------------------------------" << endl;

}

void printWRC(recordUtil records) {
    cout << "Processing Data...";
    vector<rate> rate = records.getWRatePerCourse();
    cout << "Done";
    cout << "------------ Withdraw Rate Per Course -----------------------" << endl;
    for(auto i : rate) {
        cout << " Course: " << i.id;
        cout << " Passed: " << i.num;
        cout << " Total: " << i.den;
        cout << " Pass Rate: " << i.rate << "%" << endl;
    }
    cout << "---------------------------------------------------------" << endl;

}

#endif

