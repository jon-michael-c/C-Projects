#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regex>


#include "structs.h"
#include "csvIO.h"
#include "utilFuncs.h"

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
            vector<string> files = {"./03-Student-Grades/data/1115.csv", "./03-Student-Grades/data/3115.csv", "./03-Student-Grades/data/3130.csv"};

            this->entries = readEntries(files);
            this->students = readStudents(files);
            this->instructors = readInstructors(files);
            this->courses = readCourses(files);
        }

        vector<entry> getEntries() {
            return this->entries;
        }

        void printPassPerInstructor() {

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
                
                passRate = ((double)rate.num / rate.den) * 100;
                rate.rate = passRate;
                res.push_back(rate);
            }

            
            printRate("Pass Rate Per Instuctor","Instructor", res);


        }      

        void printPassPerCourse() {
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
                
                passRate = ((double)rate.num / rate.den) * 100;
                rate.rate = passRate;
                res.push_back(rate);
            }

            printRate("Pass Rate Per Course","Course", res);


        }

        void printWithRatePerInstructor() {
            vector<rate> res;
            
            double withRate = 0;

            for(auto i : this->instructors) {
                int with = 0;
                int total = 0;
                rate rate;
                rate.id = i.id;

                for(auto j : this->entries) {
                    if(i.id == j.instructorid) {
                        total++;
                        if(isWithrW(j.grade)) {
                            with++; 
                            rate.num = with;
                            rate.den = total; 
                        }
                    } 
                    
                }
                
                withRate = ((double)rate.num / rate.den) * 100;
                rate.rate = withRate;
                res.push_back(rate);
            }
            printRate("Withdraw Rate Per Instructor","Instructor", res);



        }

        void printWithRatePerCourse() {
            vector<rate> res;
            double withRate = 0;

            for(auto i : this->courses) {
                int with = 0;
                int total = 0;
                rate rate;
                rate.id = to_string(i.courseno);

                for(auto j : this->entries) {
                    if(i.courseno == j.courseno) {
                        total++;
                        if(isWithrW(j.grade)) {
                            with++; 
                            rate.num = with;
                            rate.den = total; 
                        }
                    } 
                }
                
                withRate = ((double)rate.num / rate.den) * 100;
                rate.rate = withRate;
                res.push_back(rate);
            }
            printRate("Withdraw Rate Per Course", "Course", res);


        }




        void printPassRateFall() {
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
                        if(!isFailed(j.grade)) {
                            pass++;  
                            rate.num = pass;
                            rate.den = total;
                        }
                    } 
                }

                passRate = ((double)rate.num / rate.den) * 100;
                rate.rate = passRate;
                res.push_back(rate);
                
            }

            printRate("Pass Rate In Fall","Course", res);


            
        }
        void printPassRateSpring() {
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
                        if(!isFailed(j.grade)) {
                            pass++;  
                            rate.num = pass;
                            rate.den = total;
                        }
                    } 
                }

                passRate = ((double)rate.num / rate.den) * 100;
                rate.rate = passRate;
                res.push_back(rate);
                
            }

            printRate("Pass Rate In Spring","Course", res);





            
        }

        

        

        void addEntry(entry newEntry) {
            
            for(int i = 0; i < this->entries.size(); i++) {
                if(this->entries[i].isEqual(newEntry)) {
                    this->entries[i] = newEntry;
                }
            }

            this->entries.push_back(newEntry);

            cout << "Updating Database...";
            updateCSV(this->entries);
            cout << "Done" << endl;

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

#endif
