#include <iostream>
#include <string>
#include <cmath>

int binToDec(std::string bin) {
    int dec = 0;
    int power = 0;
    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += std::pow(2, power);
        }
        power++;
    }
    return dec;
}

int hexToDec(std::string hex) {
    int dec = 0;
    int base = 1;
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
            std::cout << "Pick a HEX, A-F".\n";
            return -1;
        }
        dec += val * base;
        base *= 16;
    }
    return dec;
}

std::string decToBin(int dec) {
    std::string bin = "";
    if (dec == 0) return "0";
    while (dec > 0) {
        bin = char((dec % 2) + '0') + bin;
        dec /= 2;
    }
    return bin;
}

std::string decToHex(int dec) {
    std::string hex = "";
    char hexDigits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if (dec == 0) return "0";
    while (dec > 0) {
        hex = hexDigits[dec % 16] + hex;
        dec /= 16;
    }
    return hex;
}

std::string floatToBin(float number) {
    int integerPart = int(number);
    return decToBin(integerPart);
}

int toDecimal(std::string input, std::string inputType) {
    if (inputType == "DEC") {
        return std::atoi(input.c_str());
    } else if (inputType == "BIN") {
        return binToDec(input);
    } else if (inputType == "HEX") {
        return hexToDec(input);
    }
    return -1;
}

int main() {
    std::string inputType, outputType;
    std::string input;

    std::cout << "Enter your input (DEC, BIN, HEX, FLOAT): ";
    std::cin >> inputType;

    std::cout << "Enter the number: ";
    std::cin >> input;

    std::cout << "Enter output type (DEC, BIN, HEX): ";
    std::cin >> outputType;

    int decimalValue;

    if (inputType == "FLOAT") {
        float floatVal = std::atof(input.c_str());
        if (outputType == "BIN") {
            std::cout << "Changed (float to BIN): " << floatToBin(floatVal) << std::endl;
        } else {
            std::cout << "Cannot change FLOAT to " << outputType << std::endl;
        }
        decimalValue = int(floatVal);
    } else {
        decimalValue = toDecimal(input, inputType);

        if (outputType == "DEC") {
            std::cout << "Changed to DEC: " << decimalValue << std::endl;
        } else if (outputType == "BIN") {
            std::cout << "Changed to BIN: " << decToBin(decimalValue) << std::endl;
        } else if (outputType == "HEX") {
            std::cout << "Changed to HEX: " << decToHex(decimalValue) << std::endl;
        } else {
            std::cout << "Invalid output type.\n";
        }
    }

    std::cout << "\nBONUS: Base Conversion and Arithmetic\n";

    std::string num1Base, num2Base, num1Str, num2Str;
    std::cout << "Enter base of first number (DEC, BIN, HEX): ";
    std::cin >> num1Base;
    std::cout << "Enter first number: ";
    std::cin >> num1Str;

    std::cout << "Enter base of second number (DEC, BIN, HEX): ";
    std::cin >> num2Base;
    std::cout << "Enter second number: ";
    std::cin >> num2Str;

    int num1 = toDecimal(num1Str, num1Base);
    int num2 = toDecimal(num2Str, num2Base);

    std::string convertedSecond;
    if (num1Base == "DEC") {
        convertedSecond = std::to_string(num2);
    } else if (num1Base == "BIN") {
        convertedSecond = decToBin(num2);
    } else if (num1Base == "HEX") {
        convertedSecond = decToHex(num2);
    }

    std::cout << "Second number converted to first number's base (" << num1Base << "): " << convertedSecond << std::endl;

    std::string op;
    std::cout << "Do you want to add or multiply the numbers? ";
    std::cin >> op;

    int result;
    if (op == "add") {
        result = num1 + num2;
    } else if (op == "multiply") {
        result = num1 * num2;
    } else {
        std::cout << "Invalid answer.\n";
        return 0;
    }

    std::cout << "DEC form: " << result << std::endl;
    if (num1Base == "BIN") {
        std::cout << "BIN form: " << decToBin(result) << std::endl;
    } else if (num1Base == "HEX") {
        std::cout << "HEX form: " << decToHex(result) << std::endl;
    }

    return 0;
}
