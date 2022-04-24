# C-Projects
### Table of Contents 
1.  [Reading/Writing in C](#example)
2.  [Calculator Using Enums](#calculator-using-enums)
3.  [Student Grade Records Utility](#student-grade-records-utility)

## Calculator Using Enums
Run using ```make lab2``` <br/>
Source file can be found [here](https://github.com/jon-michael-c/C-Projects/blob/lab2/02-Calculator/calculator.cpp) <br/>
Objective: Create a calculator program using struct and enums in C++.<br/>
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

