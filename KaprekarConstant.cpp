#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(const string& number) {
    int count[10] = {0};
    for (char digit : number) {
        if (isdigit(digit)) {
            int digitValue = digit - '0';
            count[digitValue]++;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (count[i] == number.length() && count[i] > 1) {
            return true;
        }
    }
    return false;
}

void swapChars(char &firstDigit, char &secondDigit) {
    char temp = firstDigit;
    firstDigit = secondDigit;
    secondDigit = temp;
}

void descendingOrderSort(string &numbers) {
    int number = numbers.size();
    for (int i = 0; i < number - 1; ++i) {
        for (int j = i + 1; j < number; ++j) {
            if (numbers[i] < numbers[j]) {
                swapChars(numbers[i], numbers[j]);
            }
        }
    }
}

void ascendingOrderSort(string &numbers) {
    int number = numbers.size();
    for (int i = 0; i < number - 1; ++i) {
        for (int j = i + 1; j < number; ++j) {
            if (numbers[i] > numbers[j]) {
                swapChars(numbers[i], numbers[j]);
            }
        }
    }
}

int stringToInteger(string &numberString) {
    int result = 0;

    for (int i = 0; i < numberString.length(); ++i) {
        result = result * 10 + (numberString[i] - '0');
    }

    return result;
}

int performKaprekarRoutine(int number) {
    string numberString = to_string(number);
    while (numberString.size() < 4) {
        numberString = "0" + numberString;
    }

    descendingOrderSort(numberString);
    int descendingOrder = stringToInteger(numberString);

    ascendingOrderSort(numberString);
    int ascendingOrder = stringToInteger(numberString);
    cout<<descendingOrder<<" - "<<ascendingOrder<<" = "<<(descendingOrder - ascendingOrder)<<endl;
    return descendingOrder - ascendingOrder;
}

int iterations(int number) {
    int move = 0;
    while (number != 6174 && move < 8) {
        number = performKaprekarRoutine(number);
        move++;
        if(move>7)
            return -1;
    }
    return move;
}

int main() {
    string number;
    cout << "Enter a Four-Digit number: ";
    cin >> number;

    string temp = number;

    if (number.size() != 4) {
        cout << "Please enter a valid four-digit number." << endl;
        return -1;
    }
    
    
    if (hasSameDigits(number)) {
        cout << "Please enter a valid number with at least 2 different digits." << endl;
        return -1;
    }
    
    int num = stringToInteger(number);
    int steps = iterations(num);
    
    if (steps == -1) {
        cout << "Number of iterations to reach Kaprekar's Constant (6174) is more than : 7"  << endl;
    } else {
        cout << "Number of iterations to reach Kaprekar's Constant (6174): " << steps << endl;
    }

    return 0;
}