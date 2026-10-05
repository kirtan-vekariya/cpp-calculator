#include<iostream>
using namespace std;
int main(){

    char op;
    double num1,num2;
    cout << "Enter a math problem (e.g., 5 + 3): ";
    cin >> num1 >> op >> num2;
    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            // Prevent division by zero
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed.";
            }
            break;
        default:
            // Catch invalid operators
            cout << "Error: Invalid operator.";
            break;
    }

    return 0;
}