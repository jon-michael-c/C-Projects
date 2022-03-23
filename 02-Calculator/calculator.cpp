#include <iostream>
#include <math.h>

using namespace std;


struct Calculator {
    enum Oper {
        Add=0, Sub, Mult, Div, Sqrt
    };
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
            case Sqrt:
                return pow(num1, 0.5);
        }

    }
};

int main() {
    
    string done = "Y";
    double num1=0, num2=0;
    int mode;   

    while(done == "Y" || done == "y") {
        cout << "Enter Operation" << endl;
        cout << "0 - ADD" << endl;
        cout << "1 - SUBTRACT" << endl;
        cout << "2 - MULTIPLY" << endl;
        cout << "3 - DIVIDE" << endl;
        cout << "4 - SQUARE ROOT" << endl;
        cin >> mode;


        cout << "Enter two numbers" << endl;
        cout << "Number 1: ";
        cin >> num1;
        if(mode != 4) {
            cout << "Number 2: ";
            cin >> num2;
        }
        
        Calculator calc(num1, num2);

        cout << "Result: " << calc.calculate(mode) << endl;

        cout << "Another Calculation? Y/N: ";
        cin >> done; 
    }    
    return 0;

}
