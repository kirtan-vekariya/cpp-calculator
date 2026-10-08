#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char op;
    double num1, num2;
    char choice;

    cout << "=======================================\n";
    cout << "           C++ CLI Calculator          \n";
    cout << " Supported: +, -, *, /, ^ (pow), % (mod)\n";
    cout << " Trig (Rads): s (sin), c (cos), t (tan)\n";
    cout << " Inv Trig:    S (asin/), C (acos), T (atan)\n";
    cout << " trignimetric functions are calculated in radian\n";
    cout << " Logarithms:  l (log10), n (ln)\n";
    cout << "              z (log(num1) with base num2)\n";
    cout << " Type 'q' or 'e' as the operator to exit\n";
    cout << "=======================================\n";

    // Feature 1: Continuous execution loop
    while (true) {
        cout << "\nEnter first number (or angle in radians): ";
        if (!(cin >> num1)) {
            // Feature 4: Input validation (handles non-numeric inputs)
            cout << "Invalid input. Exiting program...\n";
            break;
        }

        cout << "Enter operator (+, -, *, /, ^, %, s, c, t, S, C, T, l, n, z or 'q' to quit): ";
        cin >> op;

        // Feature 5: Immediate exit check via operator input
        if (op == 'q' || op == 'Q' || op == 'e' || op == 'E') {
            cout << "Exit command received. Goodbye!\n";
            break;
        }

        // Check if the operation only requires one number
        bool isUnary = (op == 's' || op == 'c' || op == 't' || 
                        op == 'S' || op == 'C' || op == 'T' ||
                        op == 'l' || op == 'n');

        // Only prompt for num2 if it's NOT a unary (trig) function
        if (!isUnary) {
            cout << "Enter second number: ";
            if (!(cin >> num2)) {
                cout << "Invalid input. Exiting program...\n";
                break;
            }
        }

        switch (op) {
            // Standard basic operations
            case '+':
                cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
                break;
            case '-':
                cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
                break;
            case '*':
                cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
                break;
            // Existing division with zero-division safeguard
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
                } else {
                    cout << "Error: Division by zero is undefined.\n";
                }
                break;
            // Feature 2: Exponentiation using pow() from <cmath>
            case '^':
                cout << "Result: " << num1 << " ^ " << num2 << " = " << pow(num1, num2) << "\n";
                break;
            // Feature 3: Modulo for floating-point values using fmod()
            case '%':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " % " << num2 << " = " << fmod(num1, num2) << "\n";
                } else {
                    cout << "Error: Modulo by zero is undefined.\n";
                }
                break;

            // --- TRIGONOMETRIC FUNCTIONS ---
            case 's':
                cout << "Result: sin(" << num1 << ") = " << sin(num1) << "\n";
                break;
            case 'c':
                cout << "Result: cos(" << num1 << ") = " << cos(num1) << "\n";
                break;
            case 't':
                cout << "Result: tan(" << num1 << ") = " << tan(num1) << "\n";
                break;
            case 'S':
                // arcsin is only valid for domain [-1, 1]
                if (num1 >= -1 && num1 <= 1)
                    cout << "Result: asin(" << num1 << ") = " << asin(num1) << "\n";
                else
                    cout << "Error: Domain of arcsin is [-1, 1].\n";
                break;
            case 'C':
                // arccos is only valid for domain [-1, 1]
                if (num1 >= -1 && num1 <= 1)
                    cout << "Result: acos(" << num1 << ") = " << acos(num1) << "\n";
                else
                    cout << "Error: Domain of arccos is [-1, 1].\n";
                break;
            case 'T':
                cout << "Result: atan(" << num1 << ") = " << atan(num1) << "\n";
                break;
            case 'l':
                if (num1 > 0) {
                    cout << "Result: log10(" << num1 << ") = " << log10(num1) << "\n";
                } else {
                    cout << "Error: Logarithm is undefined for zero or negative numbers.\n";
                }
                break;

            case 'n':
                if (num1 > 0) {
                    cout << "Result: ln(" << num1 << ") = " << log(num1) << "\n"; // Note: log() in C++ computes the natural logarithm (ln)
                } else {
                    cout << "Error: Natural logarithm is undefined for zero or negative numbers.\n";
                }
                break;
            
            case 'z':
                cout << "Result: " << "log(" << num1  << ")(" << num2 << ")" << " = " << log(num1) / log(num2) << "\n";
                break;

            default:
                cout << "Error: '" << op << "' is not a recognized operator.\n";
                break;
        }

        // Feature 6: End-of-cycle exit prompt
        cout << "\nPerform another calculation? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N' || choice == 'q' || choice == 'Q') {
            cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}