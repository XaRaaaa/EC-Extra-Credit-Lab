#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
// Function to extract a numeric value from a string
double extractNumeric(const string& input) {
    // Initialize all flags to false
    bool hasDecimal = false;
    bool hasSign = false;
    bool hasDigits = false;
    // Initialize the starting index
    int start = 0;
    // Check if the input is empty or too long
    if (input.empty() || input.length() > 20) {
        return -999999.99;
    }
    // Check if the input has a sign
    if (input[0] == '+' || input[0] == '-') {
        hasSign = true;
        start = 1;
    }
    // Check if the input has a decimal point
    for (int i = start; i < input.length(); ++i) {
        if (isdigit(input[i])) {
            hasDigits = true;
        } else if (input[i] == '.') {
            // Check if the input has more than one decimal point
            if (hasDecimal) {
                return -999999.99;
            }
            hasDecimal = true;
        } else {
            return -999999.99;
        }
    }
    // Check if the input has digits
    if (!hasDigits) {
        return -999999.99;
    }
    // Convert the input to a double
    return stod(input);
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
