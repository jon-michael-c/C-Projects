#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

#include "structs.h"
#include "csvIO.cpp"

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
                        if(j.grade != "W") {
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
                        if(j.grade != "W") {
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

            
            return res;
        }

        vector<rate> getPassRateSpring() {
            vector<rate> res;
            
            return res;
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
        





        


};
