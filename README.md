# C-Projects
## Calculator Using Enums
Run using ```make lab2```
Source file can be found [here](https://github.com/jon-michael-c/C-Projects/blob/lab2/02-Calculator/calculator.cpp)
Objective: Create a calculator program using struct and enums in C++.
First creating the calculator struct
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
`` 
