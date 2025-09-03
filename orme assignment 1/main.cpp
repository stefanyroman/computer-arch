#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// ----------- Helper Functions ------------

// Convert binary string to decimal integer
int binToDec(string bin) {
    int dec = 0;
    int power = 0;
    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += pow(2, power);
        }
        power++;
    }
    return dec;
}

// Convert hexadecimal string to decimal integer
int hexToDec(string hex) {
    int dec = 0;
    int base = 1; // 16^0
    for (int i = hex.length() - 1; i >= 0; i--) {
        char c = hex[i];
        int val;
        if (c >= '0' && c <= '9') {
            val = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            val = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            val = c - 'a' + 10;
        } else {
            cout << "Invalid HEX character.\n";
            return -1;
        }
        dec += val * base;
        base *= 16;
    }
    return dec;
}

// Convert decimal integer to binary string
string decToBin(int dec) {
    string bin = "";
    if (dec == 0) return "0";
    while (dec > 0) {
        bin = char((dec % 2) + '0') + bin;
        dec /= 2;
    }
    return bin;
}

// Convert decimal integer to hexadecimal string
string decToHex(int dec) {
    string hex = "";
    char hexDigits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if (dec == 0) return "0";
    while (dec > 0) {
        hex = hexDigits[dec % 16] + hex;
        dec /= 16;
    }
    return hex;
}

// Convert float to binary (simple integer part only)
string floatToBin(float number) {
    int integerPart = int(number);
    return decToBin(integerPart);
}

// Convert input string to decimal based on input type
int toDecimal(string input, string inputType) {
    if (inputType == "DEC") {
        return atoi(input.c_str());
    } else if (inputType == "BIN") {
        return binToDec(input);
    } else if (inputType == "HEX") {
        return hexToDec(input);
    }
    return -1; // error
}

// ------------- Main Program -------------

int main() {
    string inputType, outputType;
    string input;

    cout << "Enter input type (DEC, BIN, HEX, FLOAT): ";
    cin >> inputType;

    cout << "Enter the number: ";
    cin >> input;

    cout << "Enter output type (DEC, BIN, HEX): ";
    cin >> outputType;

    int decimalValue;

    // Convert input to decimal first
    if (inputType == "FLOAT") {
        float floatVal = atof(input.c_str());
        if (outputType == "BIN") {
            cout << "Converted (float to BIN): " << floatToBin(floatVal) << endl;
        } else {
            cout << "Cannot convert FLOAT to " << outputType << endl;
        }
        decimalValue = int(floatVal);
    } else {
        decimalValue = toDecimal(input, inputType);

        // Convert from decimal to desired output
        if (outputType == "DEC") {
            cout << "Converted (to DEC): " << decimalValue << endl;
        } else if (outputType == "BIN") {
            cout << "Converted (to BIN): " << decToBin(decimalValue) << endl;
        } else if (outputType == "HEX") {
            cout << "Converted (to HEX): " << decToHex(decimalValue) << endl;
        } else {
            cout << "Invalid output type.\n";
        }
    }

    // ---------- BONUS: Arithmetic Operations ----------
    cout << "\nBONUS: Base Conversion and Arithmetic\n";

    string num1Base, num2Base, num1Str, num2Str;
    cout << "Enter base of first number (DEC, BIN, HEX): ";
    cin >> num1Base;
    cout << "Enter first number: ";
    cin >> num1Str;

    cout << "Enter base of second number (DEC, BIN, HEX): ";
    cin >> num2Base;
    cout << "Enter second number: ";
    cin >> num2Str;

    // Convert both numbers to decimal
    int num1 = toDecimal(num1Str, num1Base);
    int num2 = toDecimal(num2Str, num2Base);

    // Convert second number to first number's base
    string convertedSecond;
    if (num1Base == "DEC") {
        convertedSecond = to_string(num2);
    } else if (num1Base == "BIN") {
        convertedSecond = decToBin(num2);
    } else if (num1Base == "HEX") {
        convertedSecond = decToHex(num2);
    }

    cout << "Second number converted to first number's base (" << num1Base << "): " << convertedSecond << endl;

    // Ask for operation
    string op;
    cout << "Do you want to ADD or MULTIPLY the numbers? ";
    cin >> op;

    int result;
    if (op == "ADD") {
        result = num1 + num2;
    } else if (op == "MULTIPLY") {
        result = num1 * num2;
    } else {
        cout << "Invalid operation.\n";
        return 0;
    }

    cout << "Result in DEC: " << result << endl;
    if (num1Base == "BIN") {
        cout << "Result in BIN: " << decToBin(result) << endl;
    } else if (num1Base == "HEX") {
        cout << "Result in HEX: " << decToHex(result) << endl;
    }

    return 0;
}


