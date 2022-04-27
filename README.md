# C-Projects
### Table of Contents 
1.  [Reading/Writing in C](#example)
2.  [Calculator Using Enums](#calculator-using-enums)
3.  [Student Grade Records Utility](#student-grade-records-utility)

## Calculator Using Enums
Run using ```make lab2``` 

Source file can be found [here](https://github.com/jon-michael-c/C-Projects/blob/lab2/02-Calculator/calculator.cpp) 

**Objective:** Create a calculator program using struct and enums in C++.

First we must create a calculator struct that takes two numbers, along with the constructor.


```c++
struct Calculator {
    double num1;
    double num2;

    Calculator(double num1, double num2) {
        this->num1 = num1;
        this->num2 = num2;
    }

}
```

Next, we can use enums, along with switch statements, to help with the operation mode.

```c++
//Inside Calculator Struct
enum Oper {
    Add=0, Sub, Mult, Div, Sqrt
};

double calculate(int mode) {
    switch(mode) {
        case Add:
            return num1 + num2;
        case Sub:
            return num1 - num2;
        case Mult
            return num1 * num2;
        case Div:
            return num1 / num2;
        case Sqrt:
            return pow(num1, 0.5);
    }
}

```

Example Case:

```
Operation
0 - ADD
1 - SUBTRACT
2 - MULTIPLY
3 - DIVIDE
4 - SQUARE ROOT
2
Enter two numbers
Number 1: 5
Number 2: 4
Result: 20
Another Calculation? Y/N: 
```

## Student Grade Records Utility
Run using ```make lab3```

Source files can be found [here](https://github.com/jon-michael-c/C-Projects/tree/main/03-Student-Grades/src)

**Objective:** Create a record keeping utility functions for students and instructors in C++. The program is designed to take an input of data via csv files, add or update entries, and analyze data.

**Sample CSV File**

```
emplid,courseno,instructorid,termid,sectionid,grade
E0003,1115,I12,T04,S10,A+
E0118,1115,I12,T04,S10,B
E0174,1115,I12,T04,S10,W
...
```

**Analytical Functions**

| Function         | Description | 
|--------------|:-----:|
| printPassPerInstructor() |  Shows the pass rate per instructor, where grade is not 'F*' | 
| printPassPerCourse() |  Shows the pass rate per course |  
| printWithRatePerInstructor() |  Shows the withdraw rate per instructor, where grade is 'W*' |  
| printWithRatePerCourse() |  Shows the withdraw rate per course |  
| printPassRateFall() |  Shows pass rate in the fall semesters |  
| printPassRateSpring() | Shows pass rate in the spring semesters |  

### Necessary Structs
```c++

struct entry {
    string emplid;
    int courseno;
    string instructorid;
    string termid;
    string sectionid;
    string grade;

    bool isEqual(entry i) {
        //See structs.h
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
        //See structs.h
    };
};

struct term {
    string id;
    string name;

    bool isEqual(term i) {
        //See structs.h
    };
};

struct course {
    string id;
    string instructor;
    int courseno;
    string sectionid;
    string termid;

    bool isEqual(course i) {
        //See structs.h
    }
};

struct rate {
    string id;
    int num;
    int den;
    double rate;
};

```

#### recordUtil class
```c++ 

class recordUtil {

	private:
		vector<entry> entries;
		vector<student> students;
		vector<instructor> instructors;
		vector<course> courses;
		vector<term> terms;

	public:

		recordUtil() {
			vector<string> files = {"./03-Student-Grades/src/data/1115.csv", 
								"./03-Student-Grades/src/data/3115.csv", 
								"./03-Student-Grades/src/data/3130.csv"};

			this->entries = readEntries(files);
			this->students = readStudents(files);
			this->instructors = readInstructors(files);
			this->courses = readCourses(files);

		}

	//Read,Get,etc functions
	//Rest in recordUtil.h
}
```


### Example Use
```
Add/Update Entry? Y/NY
EMPLID: E0232
COURSENO: 1115
INSTRUCTORID: I27
TERMID: T05
SECTIONID: S12
GRADE: A++
Updating Database...Done
Add/Update Another Entry? Y/N
N
Printed Results At 03-Student-Grades/output/Pass Rate Per Instuctor 2022-04-24 21:20:18.txt
Processing Data...Done
Printed Results At 03-Student-Grades/output/Pass Rate Per Course 2022-04-24 21:20:19.txt
Processing Data...Done
Printed Results At 03-Student-Grades/output/Withdraw Rate Per Instructor 2022-04-24 21:20:19.txt
Processing Data...Done
Printed Results At 03-Student-Grades/output/Withdraw Rate Per Course 2022-04-24 21:20:19.txt
Processing Data...Done
Printed Results At 03-Student-Grades/output/Pass Rate In Fall 2022-04-24 21:20:19.txt
Done
Printed Results At 03-Student-Grades/output/Pass Rate In Spring 2022-04-24 21:20:19.txt
```

**Example Output**
```
-------------------------------------
| Course |    Ratio    | Percentage |
-------------------------------------
| 1115   | 2423 / 2920 | 82.979452% |
| 3115   | 3563 / 3839 | 92.810628% |
| 3130   | 2768 / 2990 | 92.575251% |
-------------------------------------
```

**CSV File Result**
```
emplid,courseno,instructorid,termid,sectionid,grade
...
...
...
E0232,1115,I27,T05,S12,A++

```

**Credit to [friedmud](https://github.com/friedmud)for his [variadic table](https://github.com/jon-michael-c/C-Projects/blob/main/03-Student-Grades/src/VariadicTable.h) for formatting**.
