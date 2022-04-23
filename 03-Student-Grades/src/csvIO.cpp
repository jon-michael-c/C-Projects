#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <set>

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


        in_stream.close();
    }


    return vect;

}

vector<student> readStudents(string file) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);
    vector<student> vect;



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


    return vect;

}


vector<instructor> readInstructors(string file) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);
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


    return vect;

}

vector<term> readTerms(string file) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);
    vector<term> vect;



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


    return vect;

}

vector<course> readCourses(string file) {
    string id, courseno, instructorid, termid, sectionid, grade; 
    ifstream in_stream;
    in_stream.open(file);
    vector<course> vect;



    if(in_stream.is_open()) {
        string line;
        getline(in_stream, line);

        while(!in_stream.eof()) {
            course course;

            getline(in_stream, id, ',');


            getline(in_stream, courseno, ',');
            int icourseno = stoi(courseno);
            course.id = icourseno;


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


    return vect;
}
