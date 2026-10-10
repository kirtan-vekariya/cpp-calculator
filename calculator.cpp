#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
const double EPSILON = 1e-9;

int factorial(int num1){
    int a = 1;
    for(int i = 2 ; i <= num1 ; i++)a*=i;
    return a;
}
void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            cout << (c == 0 ? "Infinite solutions.\n" : "No solution.\n");
        } else {
            cout << "Linear equation. Root: x = " << -c / b << "\n";
        }
        return;
    }

    double discriminant = (b*b) - (4*a*c);

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two distinct real roots:\n";
        cout << "x1 = " << root1 << "\n";
        cout << "x2 = " << root2 << "\n";
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "One real root: x = " << root << "\n";
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Complex roots:\n";
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i\n";
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i\n";
    }
}
void solveCubic(double a, double b, double c, double d) {
    if (a == 0) {
        cout << "This is actually a quadratic equation (a=0). Solving as quadratic...\n";
        solveQuadratic(b, c, d);
        return;
    }

    double B = b / a, C = c / a, D = d / a;
    
    double p = C - (B * B) / 3.0;
    double q = (2.0 * B * B * B) / 27.0 - (B * C) / 3.0 + D;
    double discriminant = (q * q) / 4.0 + (p * p * p) / 27.0;

    if (abs(discriminant) < EPSILON) {
        double u = cbrt(-q / 2.0);
        double root1 = 2.0 * u - B / 3.0;
        double root2 = -u - B / 3.0;
        
        cout << "All real roots (at least two are equal).\n";
        cout << "x1 = " << root1 << "\n";
        cout << "x2 = x3 = " << root2 << "\n";
    } 
    else if (discriminant > 0) {
        double u = cbrt(-q / 2.0 + sqrt(discriminant));
        double v = cbrt(-q / 2.0 - sqrt(discriminant));
        double root1 = u + v - B / 3.0;
        
        cout << "One real root and two complex conjugate roots.\n";
        cout << "Real root: x1 = " << root1 << "\n";
        
        double realPart = -(u + v) / 2.0 - B / 3.0;
        double imagPart = (sqrt(3.0) / 2.0) * (u - v);
        cout << "Complex root 1: x2 = " << realPart << " + " << imagPart << "i\n";
        cout << "Complex root 2: x3 = " << realPart << " - " << imagPart << "i\n";
    } 
    else { 
        double r = sqrt(-(p * p * p) / 27.0);
        double phi = acos(-q / (2.0 * r));
        double r_cbrt = 2.0 * sqrt(-p / 3.0);
        
        double root1 = r_cbrt * cos(phi / 3.0) - B / 3.0;
        double root2 = r_cbrt * cos((phi + 2.0 * PI) / 3.0) - B / 3.0;
        double root3 = r_cbrt * cos((phi + 4.0 * PI) / 3.0) - B / 3.0;
        
        cout << "Three distinct real roots.\n";
        cout << "x1 = " << root1 << "\n";
        cout << "x2 = " << root2 << "\n";
        cout << "x3 = " << root3 << "\n";
    }
}

int main() {
    char op;
    double num1, num2;
    char choice;

    cout << "=======================================\n";
    cout << "           C++ CLI Calculator          \n";
    cout << " Supported:   +, -, *, /, ^ (pow), % (mod)\n";
    cout << " Trig (Rads): s (sin), c (cos), t (tan)\n";
    cout << " Inv Trig:    S (asin), C (acos), T (atan)\n";
    cout << " trignimetric functions are calculated in radian\n";
    cout << " Logarithms:  l (log10), n (ln)\n";
    cout << "              z (log(num1) with base num2)\n";
    cout << " factorials:  f (n!)\n";
    cout << " solver:      2 (quadretic)(ax^2+bx+c)\n";
    cout << " solver:      3 (cubic)(ax^3+bx^2+cx+d)\n";
    cout << " permutation: a (n P r)\n";
    cout << " combinations:b (n C r)\n";
    cout << " Type 'q' or 'e' as the operator to exit\n";
    cout << "=======================================\n";

    while (true) {
        cout << "\nEnter first number (or 'a' for solvers): ";
        if (!(cin >> num1)) {
            cout << "Invalid input. Exiting program...\n";
            break;
        }

        cout << "Enter operator (+, -, *, /, ^, %, s, c, t, S, C, T, l, n, z, f, 2, 3, a, b or 'q' to quit): ";
        cin >> op;

        if (op == 'q' || op == 'Q' || op == 'e' || op == 'E') {
            cout << "Exit command received. Goodbye!\n";
            break;
        }

        bool isUnary = (op == 's' || op == 'c' || op == 't' || 
                        op == 'S' || op == 'C' || op == 'T' ||
                        op == 'l' || op == 'n' || op == 'f' );

        if (!isUnary) {
            cout << "Enter second number (or 'a' for solvers): ";
            if (!(cin >> num2)) {
                cout << "Invalid input. Exiting program...\n";
                break;
            }
        }

        switch (op) {
            case '+':
                cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
                break;
            case '-':
                cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
                break;
            case '*':
                cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
                } else {
                    cout << "Error: Division by zero is undefined.\n";
                }
                break;
            case '^':
                cout << "Result: " << num1 << " ^ " << num2 << " = " << pow(num1, num2) << "\n";
                break;
            case '%':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " % " << num2 << " = " << fmod(num1, num2) << "\n";
                } else {
                    cout << "Error: Modulo by zero is undefined.\n";
                }
                break;

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
                if (num1 >= -1 && num1 <= 1)
                    cout << "Result: asin(" << num1 << ") = " << asin(num1) << "\n";
                else
                    cout << "Error: Domain of arcsin is [-1, 1].\n";
                break;
            case 'C':
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

            case 'f':
                cout << "Result: factorial of (" << num1 << ") = " << factorial(num1) << "\n";
                break;

            case '2':
                double c_quad;
                cout << "enter cofficient c: ";
                if(!(cin >> c_quad)){
                    cout << "invalid input.\n";
                    break;
                }
                cout << "\nSolving Quadratic: " << num1 << "x^2 + " << num2 << "x + " << c_quad << " = 0\n";
                solveQuadratic(num1, num2, c_quad);
                break;

            case '3': {
                double c_cub, d_cub;
                cout << "Enter coefficient c: ";
                if (!(cin >> c_cub)) break;
                cout << "Enter coefficient d: ";
                if (!(cin >> d_cub)) break;
                
                cout << "\nSolving Cubic: " << num1 << "x^3 + " << num2 << "x^2 + " << c_cub << "x + " << d_cub << " = 0\n";
                solveCubic(num1, num2, c_cub, d_cub);
                break;
            }

            case 'a':
                cout <<  num1 << " P " << num2 << " is equal to : " << factorial(num1) / factorial(num1 - num2) << "\n";
                break;
            case 'b':
                cout <<  num1 << " C " << num2 << " yis equal to : " << factorial(num1) / (factorial(num2) * factorial(num1 - num2)) << "\n";
                break;

            default:
                cout << "Error: '" << op << "' is not a recognized operator.\n";
                break;
        }

        cout << "\nPerform another calculation? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N' || choice == 'q' || choice == 'Q') {
            cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}