#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#include "structs.h"


using namespace std;

vector<entry> readEntries(string file) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);
    vector<entry> vect;



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            entry entry;

            getline(in_stream, id, ',');
            entry.emplid = id;

            getline(in_stream, courseno, ',');
            entry.courseno = courseno;


            getline(in_stream, instructorid, ',');
            entry.instructorid = instructorid;

            getline(in_stream, termid, ',');
            entry.termid = termid;

            getline(in_stream, sectionid, ',');
            entry.sectionid = sectionid;

            getline(in_stream, grade);
            entry.grade = grade;

            vect.push_back(entry);
            
            
        };


        in_stream.close();
    }


    return vect;

}

vector<instructor> readInstructors() {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open("./03-Student-Grades/src/data/1115.csv");
    vector<instructor> vect;



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            instructor instruct;

            getline(in_stream, id, ',');


            getline(in_stream, courseno, ',');
            int icourseno = stoi(courseno);
            instruct.course = icourseno;


            getline(in_stream, instructorid, ',');
            instruct.id = instructorid;

            getline(in_stream, termid, ',');
            instruct.term = termid;

            getline(in_stream, sectionid, ',');

            getline(in_stream, grade);

            vect.push_back(instruct);
            
            
        };


        in_stream.close();
    }


    return vect;

}


