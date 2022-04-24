#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

#include "structs.h"

#ifndef IO_HEADER
#define IO_HEADER



vector<entry> readEntries(vector<string> files) {
    vector<entry> vect;

    for(auto file : files) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            entry entry;

            getline(in_stream, id, ',');
            entry.emplid = id;

            getline(in_stream, courseno, ',');
            int icourseno = stoi(courseno);
            entry.courseno = icourseno;

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

        vect.pop_back();


        in_stream.close();
    }
    } 


    return vect;

}
vector<student> readStudents(vector<string> files) {
    vector<student> vect;
    for(auto file : files) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            student student;

            getline(in_stream, id, ',');
            student.id = id;

            getline(in_stream, courseno, ',');
            int icourseno = stoi(courseno);
            student.course = icourseno;

            getline(in_stream, instructorid, ',');

            getline(in_stream, termid, ',');

            getline(in_stream, sectionid, ',');

            getline(in_stream, grade);
            student.grade = grade;

            vect.push_back(student);
            
            
        };


        in_stream.close();
    }


    } 
    return vect;

}


vector<instructor> readInstructors(vector<string> files) {
    vector<instructor> vect;

    for(auto file : files) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);



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

            bool found = false;
            for(auto i : vect) {
                if(i.isEqual(instruct)) {
                    found = true;
                }
            }

            if(!found) {
                vect.push_back(instruct);
            }           
            
        };


        in_stream.close();
    }


    } 
    return vect;

}

vector<term> readTerms(vector<string> files) {
    vector<term> vect;

    for(auto file : files) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            term term;

            getline(in_stream, id, ',');
            term.id = id;


            getline(in_stream, courseno, ',');
            

            getline(in_stream, instructorid, ',');

            getline(in_stream, termid, ',');

            getline(in_stream, sectionid, ',');

            getline(in_stream, grade);

            bool found = false;
            for(auto i : vect) {
                if(i.isEqual(term)) {
                    found = true;
                }
            }

            if(!found) {
                vect.push_back(term);
            }           
            
        };


        in_stream.close();
    }



    }
        return vect;

}

vector<course> readCourses(vector<string> files) {
    vector<course> vect;

    for(auto file : files) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            course course;

            getline(in_stream, id, ',');
            course.id = id;


            getline(in_stream, courseno, ',');
            int icourseno = stoi(courseno);
            course.courseno = icourseno;


            getline(in_stream, instructorid, ',');
            course.instructor = instructorid;

            getline(in_stream, termid, ',');
            course.termid = termid;

            getline(in_stream, sectionid, ',');
            course.sectionid = sectionid;

            getline(in_stream, grade);

            bool found = false;
            for(auto i : vect) {
                if(i.isEqual(course)) {
                    found = true;
                }
            }

            if(!found) {
                vect.push_back(course);
            }           
            
        };


        in_stream.close();
    }
    } 


    return vect;
}


bool updateCSV(vector<entry> entries) {
    
    ofstream out_stream;
    out_stream.open("./03-Student-Grades/src/data/1115.csv");
    out_stream << "emplid,";
    out_stream << "courseno,";
    out_stream << "instructorid,";
    out_stream << "termid,";
    out_stream << "sectionid,";
    out_stream << "grade" << "\n";
    for(auto i : entries) {
        if(i.courseno == 1115) {
            out_stream << i.emplid << ",";
            out_stream << i.courseno << ",";
            out_stream << i.instructorid << ",";
            out_stream << i.termid << ",";
            out_stream << i.sectionid<< ",";
            out_stream << i.grade << "\n";

        }     
    }

    out_stream.close();

    out_stream.open("./03-Student-Grades/src/data/3115.csv");
    out_stream << "emplid,";
    out_stream << "courseno,";
    out_stream << "instructorid,";
    out_stream << "termid,";
    out_stream << "sectionid,";
    out_stream << "grade" << "\n";
    for(auto i : entries) {
        if(i.courseno == 3115) {
            out_stream << i.emplid << ",";
            out_stream << i.courseno << ",";
            out_stream << i.instructorid << ",";
            out_stream << i.termid << ",";
            out_stream << i.sectionid<< ",";
            out_stream << i.grade << "\n";

        }     
    }

    out_stream.close();

    out_stream.open("./03-Student-Grades/src/data/3130.csv");
    out_stream << "emplid,";
    out_stream << "courseno,";
    out_stream << "instructorid,";
    out_stream << "termid,";
    out_stream << "sectionid,";
    out_stream << "grade" << "\n";
    for(auto i : entries) {
        if(i.courseno == 3130) {
            out_stream << i.emplid << ",";
            out_stream << i.courseno << ",";
            out_stream << i.instructorid << ",";
            out_stream << i.termid << ",";
            out_stream << i.sectionid<< ",";
            out_stream << i.grade << "\n";

        }     
    }

            
    out_stream.close();




    return true;
}

#endif
