// Hacktoberfest 2025 Contribution
// Description: C++ program to check whether a number is an Armstrong Number using OOP

#include <iostream>
#include <cmath> // for pow()

using namespace std;

// Class to represent an Armstrong number checker
class ArmstrongNumber {
private:
    int number; // user input number

    // Helper function to count number of digits
    int countDigits(int n) {
        int count = 0;
        while (n != 0) {
            n /= 10;
            count++;
        }
        return count;
    }

public:
    // Constructor to initialize number
    ArmstrongNumber(int num) {
        number = num;
    }

    // Function to check if the number is an Armstrong number
    bool isArmstrong() {
        int n = number;
        int digits = countDigits(n);
        int sum = 0;

        while (n != 0) {
            int digit = n % 10;
            sum += pow(digit, digits);
            n /= 10;
        }

        return sum == number;
    }

    // Function to display the result
    void displayResult() {
        if (isArmstrong())
            cout << number << " is an Armstrong Number." << endl;
        else
            cout << number << " is NOT an Armstrong Number." << endl;
    }
};

// Main function
int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    ArmstrongNumber check(num);
    check.displayResult();

    return 0;
}
