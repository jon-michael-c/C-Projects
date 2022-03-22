#include <iostream>
#include <math.h>

using namespace std;
enum Oper {
    Add=0, Sub, Mult, Div, Exp
};

struct Calculator {
    Oper op;
    double num1;
    double num2;

    Calculator(double num1, double num2) {
        this->num1 = num1;
        this->num2 = num2;
    }

    double calculate(int mode) {
        switch(mode) {
            case Add:
                return num1 + num2;
            case Sub:
                return num1 - num2; 
            case Mult:
                return num1 * num2;
            case Div:
                return num1 / num2;
            case Exp:
                return pow(num1, num2);
        }

    }
};

int main() {
    
    double num1, num2;
    int mode;   


    cout << "Enter two numbers" << endl;
    cout << "Number 1: " << endl;
    cin >> num1;
    cout << "Number 2: " << endl;
    cin >> num2;
    cout << "Enter Operation" << endl;
    cout << "0 - ADD" << endl;
    cout << "1 - SUBTRACT" << endl;
    cout << "2 - MULTIPLY" << endl;
    cout << "3 - DIVIDE" << endl;
    cout << "4 - EXPONENT" << endl;
    cin >> mode;

    Calculator calc(num1, num2);

    cout << calc.calculate(mode) << endl;

    



    return 0;

}
