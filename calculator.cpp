#include <iostream>
#include <cmath> // Feature 2 & 3: Needed for pow() and fmod()

using namespace std;

int main() {
    char op;
    double num1, num2;
    char choice;

    cout << "=======================================\n";
    cout << "           C++ CLI Calculator          \n";
    cout << " Supported: +, -, *, /, ^ (pow), % (mod)\n";
    cout << " Type 'q' or 'e' as the operator to exit\n";
    cout << "=======================================\n";

    // Feature 1: Continuous execution loop
    while (true) {
        cout << "\nEnter first number: ";
        if (!(cin >> num1)) {
            // Feature 4: Input validation (handles non-numeric inputs)
            cout << "Invalid input. Exiting program...\n";
            break;
        }

        cout << "Enter operator (+, -, *, /, ^, %, or 'q' to quit): ";
        cin >> op;

        // Feature 5: Immediate exit check via operator input
        if (op == 'q' || op == 'Q' || op == 'e' || op == 'E') {
            cout << "Exit command received. Goodbye!\n";
            break;
        }

        cout << "Enter second number: ";
        if (!(cin >> num2)) {
            cout << "Invalid input. Exiting program...\n";
            break;
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