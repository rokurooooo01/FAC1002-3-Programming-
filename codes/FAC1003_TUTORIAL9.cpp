#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

const double PI = 3.14159;

void pauseBeforeMenu() {
    cout << "\n[Press ENTER to return to the main menu...]";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
}

void handleQ1() {
    cout << "\n--- Question 1: Find Absolute Value ---\n";
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The absolute value is: " << abs(num) << "\n";
}

double divideNumbers(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero. ";
        return 0;
    }
    return static_cast<double>(a) / b; 
}

void handleQ2() {
    cout << "\n--- Question 2: Divide Two Integers ---\n";
    int num1, num2;
    cout << "Enter two integers (e.g., 10 3): ";
    cin >> num1 >> num2;
    cout << "The division result is: " << divideNumbers(num1, num2) << "\n";
}

double calculateArea(double radius) {
    return PI * pow(radius, 2);
}

void handleQ4() {
    cout << "\n--- Question 4: Area of Circle ---\n";
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "The area of the circle is: " << calculateArea(radius) << "\n";
}

float calculateAverage(float num1, float num2) {
    return (num1 + num2) / 2.0f;
}

void handleQ6() {
    cout << "\n--- Question 6: Average of Two Numbers ---\n";
    float val1, val2;
    cout << "Enter two floating-point numbers: ";
    cin >> val1 >> val2;
    cout << "The average is: " << calculateAverage(val1, val2) << "\n";
}

double multiplyQ8(double a, double b) {
    return a * b;
}

double divideQ8(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero! ";
        return 0;
    }
    return a / b;
}

void handleQ8() {
    cout << "\n--- Question 8: Conditional Multiply/Divide ---\n";
    double n1, n2;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;
    
    if (n1 > n2) {
        cout << "First is greater. Multiplication result: " << multiplyQ8(n1, n2) << "\n";
    } else {
        cout << "First is not greater. Division result: " << divideQ8(n1, n2) << "\n";
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n========================================\n";
        cout << "        FAC1003 Tutorial 9 Menu         \n";
        cout << "========================================\n";
        cout << "1. Q1: Find Absolute Value\n";
        cout << "2. Q2: Divide Two Integers\n";
        cout << "3. Q4: Calculate Area of Circle\n";
        cout << "4. Q6: Average of Two Numbers\n";
        cout << "5. Q8: Conditional Multiply/Divide\n";
        cout << "0. Exit Program\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice (0-5): ";
        
        cin >> choice;
        
        switch (choice) {
            case 1: 
                handleQ1(); 
                pauseBeforeMenu(); 
                break;
            case 2: 
                handleQ2(); 
                pauseBeforeMenu(); 
                break;
            case 3: 
                handleQ4(); 
                pauseBeforeMenu(); 
                break;
            case 4: 
                handleQ6(); 
                pauseBeforeMenu(); 
                break;
            case 5: 
                handleQ8(); 
                pauseBeforeMenu(); 
                break;
            case 0: 
                cout << "\nExiting program. Goodbye!\n"; 
                break;
            default: 
                cout << "\nInvalid choice. Please enter a number between 0 and 5.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                pauseBeforeMenu();
        }
        
    } while (choice != 0); 
    
    return 0;
}
