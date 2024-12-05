#include <iostream>
#include <limits> // Required for numeric_limits
using namespace std;

void displayMenu() {
    cout << "Welcome to the Multi-Operand Calculator!" << endl;
    cout << "Select an operation to perform:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    int operation;
    double result, num;

    cout << "Enter the first number: ";
    cin >> result;

    while (true) {
        displayMenu();

        // Input operation with validation
        cout << "Enter the number corresponding to the operation (1-5): ";
        cin >> operation;

        if (cin.fail()) {
            // Clear the error flag and ignore invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid option (1-5)." << endl;
            continue;
        }

        if (operation == 5) {
            cout << "Exiting the calculator. Final result: " << result << endl;
            break;
        }

        if (operation < 1 || operation > 5) {
            cout << "Invalid choice. Please select a valid operation." << endl;
            continue;
        }

        cout << "Enter the next number: ";
        cin >> num;

        switch (operation) {
            case 1:
                result += num;
                cout << "Current result: " << result << endl;
                break;
            case 2:
                result -= num;
                cout << "Current result: " << result << endl;
                break;
            case 3:
                result *= num;
                cout << "Current result: " << result << endl;
                break;
            case 4:
                if (num == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    result /= num;
                    cout << "Current result: " << result << endl;
                }
                break;
        }
    }

    return 0;
}
