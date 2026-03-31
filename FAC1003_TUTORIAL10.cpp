#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

void pauseBeforeMenu() {
    cout << "\n[Press ENTER to return to the main menu...]";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
}

void calculateKineticEnergy(double m, double v) {
    double ke = 0.5 * m * pow(v, 2);
    cout << "The kinetic energy is " << ke << " Joules.\n";
}

void handleQ1() {
    cout << "\n--- Question 1: Kinetic Energy ---\n";
    double mass, velocity;
    cout << "Enter mass (kg): ";
    cin >> mass;
    cout << "Enter velocity (m/s): ";
    cin >> velocity;
    calculateKineticEnergy(mass, velocity);
}

double factorial(int n) {
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double sumOfSeries(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i) / i;
    }
    return sum;
}

void handleQ2() {
    cout << "\n--- Question 2: Sum of Series ---\n";
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The sum of the series is: " << sumOfSeries(n) << "\n";
}

void printKinematicsTable() {
    cout << "\n--- Question 3: Particle Motion ---\n";
    cout << left << setw(10) << "Time (s)" 
         << setw(15) << "Position (m)" 
         << setw(15) << "Velocity (m/s)" 
         << "Acceleration (m/s^2)\n";
    cout << "----------------------------------------------------------\n";
    
    for (double t = 0; t <= 1.5; t += 0.1) {
        double position = 3 * pow(t, 2) + 8 * t - 2 * pow(t, 2.5);
        double velocity = 6 * t + 8 - 5 * pow(t, 1.5);
        double acceleration = 6 - 7.5 * pow(t, 0.5);
        
        cout << fixed << setprecision(3) << left 
             << setw(10) << t 
             << setw(15) << position 
             << setw(15) << velocity 
             << acceleration << "\n";
    }
}

double calcAverage(double x1, double x2, double x3, double x4) {
    return (x1 + x2 + x3 + x4) / 4.0;
}

double calcStdDev(double x1, double x2, double x3, double x4, double mean) {
    double sumOfSquares = pow(x1 - mean, 2) + pow(x2 - mean, 2) + 
                          pow(x3 - mean, 2) + pow(x4 - mean, 2);
    return sqrt(sumOfSquares / 3.0); 
}

void handleQ4() {
    cout << "\n--- Question 4: Mean & Std Dev ---\n";
    char choice;
    
    while (true) {
        cout << "\nPress Y to enter the program or press any button to exit back to main menu: ";
        cin >> choice;
        
        if (choice != 'Y' && choice != 'y') {
            cout << "You wished to exit Q4. Thank you.\n";
            break; 
        }
        
        double num1, num2, num3, num4;
        cout << "Enter 4 numbers, I will give you the mean and standard deviation of the data.\n";
        cin >> num1 >> num2 >> num3 >> num4;
        
        double mean = calcAverage(num1, num2, num3, num4);
        double stdDev = calcStdDev(num1, num2, num3, num4, mean);
        
        cout << fixed << setprecision(2);
        cout << "The mean of " << num1 << ", " << num2 << ", " << num3 << ", and " << num4 << " is " << mean << "\n";
        cout << fixed << setprecision(6);
        cout << "The standard deviation of these numbers is " << stdDev << "\n";
    }
}

double calculateFuel(int distance) {
    return (6.8 / 102.0) * distance;
}

void printOutput(int distance, double fuel) {
    cout << left << setw(15) << distance << fixed << setprecision(2) << fuel << " Liters\n";
}

void handleQ5() {
    cout << "\n--- Question 5: Fuel Consumption ---\n";
    cout << left << setw(15) << "Distance (km)" << "Fuel Consumed\n";
    cout << "--------------------------------\n";
    
    for (int dist = 10; dist <= 150; dist += 10) {
        double fuel = calculateFuel(dist); 
        printOutput(dist, fuel);           
    }
}

double kiraPecutan(double t) {
    return 8 + 12 * t - 48 * pow(t, 2);
}

void paparJadual() {
    cout << "\n--- Question 6: Instantaneous Acceleration ---\n";
    cout << left << setw(15) << "Time (s)" << "Acceleration (m/s^2)\n";
    cout << "--------------------------------------\n";
    
    for (double t = 0; t <= 1.5; t += 0.1) {
        double acc = kiraPecutan(t);
        cout << fixed << setprecision(2) << left << setw(15) << t << acc << "\n";
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n========================================\n";
        cout << "       FAC1003 Tutorial 10 Menu         \n";
        cout << "========================================\n";
        cout << "1. Calculate Kinetic Energy\n";
        cout << "2. Sum of Factorial Series\n";
        cout << "3. Particle Motion Table\n";
        cout << "4. Mean and Standard Deviation\n";
        cout << "5. Fuel Consumption Table\n";
        cout << "6. Instantaneous Acceleration Table\n";
        cout << "0. Exit Program\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice (0-6): ";
        
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
                printKinematicsTable(); 
                pauseBeforeMenu(); 
                break;
            case 4: 
                handleQ4(); 
                pauseBeforeMenu(); 
                break;
            case 5: 
                handleQ5(); 
                pauseBeforeMenu(); 
                break;
            case 6: 
                paparJadual(); 
                pauseBeforeMenu(); 
                break;
            case 0: 
                cout << "\nExiting program. Goodbye!\n"; 
                break;
            default: 
                cout << "\nInvalid choice. Please enter a number between 0 and 6.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                pauseBeforeMenu();
        }
        
    } while (choice != 0); 
    
    return 0;
}