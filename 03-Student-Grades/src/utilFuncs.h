#include <iostream>
#include <string>
#include <chrono>
#include <iomanip> // put_time
#include <vector>
#include <regex>

using namespace std;

#include "structs.h"

#ifndef UTIL_HEADER
#define UTIL_HEADER


void printHeader(string head) {
    cout << "______________ " << head << " ______________" << endl;
}
void printLineBorder() {
    cout << "______________" << endl;
}

bool isFall(string termid) {
            vector<string> fallTerms = {"T04", "T08", "T12", "T16", "T20", "T23"};
            for(auto i : fallTerms) {
                if(termid == i) {
                    return true;
                }
            }

            return false;
}

bool isSpring(string termid) {
    vector<string> springTerms = {"T02", "T06", "T10", "T14", "T18", "T21"};
    for(auto i : springTerms) {
        if(termid == i) {
            return true;
        }
    }

    return false;
}       

bool isFailed(string grade) {
    if(regex_match(grade, regex("(F)(.*)"))) {
        return true;
    } else {
        return false;
    }
}


bool isWithrW(string grade) {
    if(regex_match(grade, regex("(W)(.*)"))) {
        return true;
    } else {
        return false;
    }
}

string getTime() {
    auto now = std::chrono::system_clock::now();
    auto UTC = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream datetime;
    datetime << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

    return datetime.str();
    
}

#endif


