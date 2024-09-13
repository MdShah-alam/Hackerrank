#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string encryption(string s) {
    // Remove spaces from the string
    string cleanString = "";
    for (char c : s) {
        if (c != ' ') {
            cleanString += c;
        }
    }

    int length = cleanString.size();
    int rows = floor(sqrt(length));
    int cols = ceil(sqrt(length));

    // Adjust rows and cols if necessary to cover all characters
    if (rows * cols < length) {
        rows++;
    }

    // Create the encoded message
    string encoded = "";

    // Read column by column
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            int index = row * cols + col;
            if (index < length) {
                encoded += cleanString[index];
            }
        }
        // Add a space between words (but not after the last one)
        if (col < cols - 1) {
            encoded += " ";
        }
    }

    return encoded;
}

int main() {
    string input;
    getline(cin, input);

    string result = encryption(input);
    cout << result << endl;

    return 0;
}
