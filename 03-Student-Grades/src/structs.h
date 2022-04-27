#include <string>
using namespace std;

#ifndef STRUCT_HEADER
#define STRUCT_HEADER

struct entry {
    string emplid;
    int courseno;
    string instructorid;
    string termid;
    string sectionid;
    string grade;

    bool isEqual(entry i) {
        if(this->emplid == i.emplid && this->courseno == i.courseno && this->sectionid == i.sectionid) {
            return true;
        } else {
            return false;
        }
    }
};

struct student {
    string id;
    int course;
    string grade;
};

struct instructor {
    string id;
    int course;
    string term;

    bool isEqual(instructor i) {
        if(this->id == i.id) {
            return true;
        } else {
            return false;
        }
    };
};

struct term {
    string id;
    string name;

    bool isEqual(term i) {
        if(this->id == i.id) {
            return true;
        } else {
            return false;
        }
    };
};

struct course {
    string id;
    string instructor;
    int courseno;
    string sectionid;
    string termid;

    bool isEqual(course i) {
        if(this->courseno == i.courseno) {
            return true;
        } else {
            return false;
        }
    }
};

struct rate {
    string id;
    int num;
    int den;
    double rate;
};
#endif
