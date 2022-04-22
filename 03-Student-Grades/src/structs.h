#include <string>
using namespace std;

#ifndef STRUCT_HEADER
#define STRUCT_HEADER

struct entry {
    string emplid;
    string courseno;
    string instructorid;
    string termid;
    string sectionid;
    string grade;
};

struct student {
    string id;
    string course;
    string grade;
};

struct instructor {
    string id;
    int course;
    string term;
};

struct term {
    string id;
    string name;
};

struct course {
    string id;
    string courseno;
    string sectionid;
    string termid;
};
#endif
