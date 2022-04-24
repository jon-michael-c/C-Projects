#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <regex>

#include "structs.h"
#include "csvIO.h"

#ifndef RECORD_HEADER
#define RECORD_HEADER



class recordUtil {

    private:
        vector<entry> entries;
        vector<student> students;
        vector<instructor> instructors;
        vector<course> courses;
        vector<term> terms;
    public:
        recordUtil() {
            vector<string> files = {"./03-Student-Grades/src/data/1115.csv", "./03-Student-Grades/src/data/3115.csv", "./03-Student-Grades/src/data/3130.csv"};

            this->entries = readEntries(files);
            this->students = readStudents(files);
            this->instructors = readInstructors(files);
            this->courses = readCourses(files);
        }

        vector<entry> getEntries() {
            return this->entries;
        }

        vector<rate> getPassPerInstructor() {
            vector<rate> res;
            
            double passRate = 0;

            for(auto i : this->instructors) {
                int pass = 0;
                int total = 0;
                rate rate;
                rate.id = i.id;

                for(auto j : this->entries) {
                    if(i.id == j.instructorid) {
                        total++;
                        if(!isFailed(j.grade)) {
                            pass++; 
                            rate.num = pass;
                            rate.den = total; 
                        }
                    } 
                    
                }
                
                passRate = ((double)rate.num / rate.den);
                rate.rate = passRate;
                res.push_back(rate);
            }

            return res;

        }      

        vector<rate> getPassPerCourse() {
            vector<rate> res;
            double passRate = 0;

            for(auto i : this->courses) {
                int pass = 0;
                int total = 0;
                rate rate;
                rate.id = to_string(i.courseno);

                for(auto j : this->entries) {
                    if(i.courseno == j.courseno) {
                        total++;
                        if(!isFailed(j.grade)) {
                            pass++; 
                            rate.num = pass;
                            rate.den = total; 
                        }
                    } 
                    
                }
                
                passRate = ((double)rate.num / rate.den);
                rate.rate = passRate;
                res.push_back(rate);
            }

            return res;

        }

        vector<rate> getWRatePerInstructor() {
            vector<rate> res;
            
            double passRate = 0;

            for(auto i : this->instructors) {
                int pass = 0;
                int total = 0;
                rate rate;
                rate.id = i.id;

                for(auto j : this->entries) {
                    if(i.id == j.instructorid) {
                        total++;
                        if(!isWithrW(j.grade)) {
                            pass++; 
                            rate.num = pass;
                            rate.den = total; 
                        }
                    } 
                    
                }
                
                passRate = ((double)rate.num / rate.den);
                rate.rate = passRate;
                res.push_back(rate);
            }

            return res;


        }

        vector<rate> getWRatePerCourse() {
            vector<rate> res;
            double passRate = 0;

            for(auto i : this->courses) {
                int pass = 0;
                int total = 0;
                rate rate;
                rate.id = to_string(i.courseno);

                for(auto j : this->entries) {
                    if(i.courseno == j.courseno) {
                        total++;
                        if(!isWithrW(j.grade)) {
                            pass++; 
                            rate.num = pass;
                            rate.den = total; 
                        }
                    } 
                }
                
                passRate = ((double)rate.num / rate.den);
                rate.rate = passRate;
                res.push_back(rate);
            }

            return res;

        }




        vector<rate> getPassRateFall() {
            vector<rate> res;

            for(auto i : this->courses) {
                rate rate;
                rate.id = to_string(i.courseno);
                double passRate = 0;
                int pass = 0;
                int total = 0;

                for(auto j : this->entries) {
                    if(i.courseno == j.courseno && isFall(j.termid)) {
                        total++;
                        if(j.grade != "F") {
                            pass++;  
                            rate.num = pass;
                            rate.den = total;
                        }
                    } 
                }

                passRate = ((double)rate.num / rate.den);
                rate.rate = passRate;
                res.push_back(rate);
                
            }

            return res;


            
        }
        vector<rate> getPassRateSpring() {
            vector<rate> res;

            for(auto i : this->courses) {
                rate rate;
                rate.id = to_string(i.courseno);
                double passRate = 0;
                int pass = 0;
                int total = 0;

                for(auto j : this->entries) {
                    if(i.courseno == j.courseno && !isFall(j.termid)) {
                        total++;
                        if(j.grade != "F") {
                            pass++;  
                            rate.num = pass;
                            rate.den = total;
                        }
                    } 
                }

                passRate = ((double)rate.num / rate.den);
                rate.rate = passRate;
                res.push_back(rate);
                
            }

            return res;


            
        }

        

        void addEntry(string emplid, int courseno, string instructorid, string termid, string sectionid, string grade) {
            entry newEntry;
            newEntry.emplid = emplid;
            newEntry.courseno = courseno;
            newEntry.instructorid = instructorid;
            newEntry.termid = termid;
            newEntry.sectionid = sectionid;
            newEntry.grade = grade;

            for(int i = 0; i < this->entries.size(); i++) {
                if(this->entries[i].isEqual(newEntry)) {
                    this->entries[i] = newEntry;
                }
            }

            this->entries.push_back(newEntry);

            updateCSV(this->entries);

        }
 
        vector<student> getStudents() {
            return this->students;
        }

        vector<instructor> getInstructors() {
            return this->instructors;
        }


        vector<term> getTerms() {
            return this->terms;
        }

        vector<course> getCourses() {
            return this->courses;
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


};

#endif
