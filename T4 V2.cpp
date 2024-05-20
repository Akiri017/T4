#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int minReplacement(const std::string& str) {
    std::stack<char> stk;
    int replacements = 0;

    for (char c : str) {
        if (c == '{') {
            stk.push(c);
        }
        else if (c == '}' && !stk.empty() && stk.top() == '{') {
            stk.pop();
        }
        else {
            replacements++;
        }
    }

    replacements += stk.size();

    return replacements;
}

int main() {
    std::string braces, YesNo;

    bool repeat = true;

    while (repeat) {
        bool valid = false;

        while (!valid) {
            std::cout << "Enter a string of braces: ";
            std::getline(std::cin, braces);

            if (!braces.empty() && std::all_of(braces.begin(), braces.end(), [](char c) {
                return c == '{' || c == '}';
                })) {
                valid = true;

            }
            else {
                std::cout << "Input is invalid. Please enter only '{' or '}'." << std::endl;
                system("PAUSE");
                system("CLS");
            }
        }

        int replacements = minReplacement(braces);
        std::cout << "Minimum number of replacements required: " << replacements << std::endl;
        valid = false;

        do {
            std::cout << "\nTry again? [Y/N] ";
            std::getline(std::cin, YesNo);

            if (YesNo.size() == 1 && (YesNo[0] == 'Y' || YesNo[0] == 'y' || YesNo[0] == 'N' || YesNo[0] == 'n')) {
                valid = true;
            }
            else {
                std::cout << "Input is invalid. Please enter only 'Y' or 'N'." << std::endl;
            }
        } while (valid == false);

        if (YesNo[0] == 'N' || YesNo[0] == 'n') {
            repeat = false;
        }
        else {
            system("PAUSE");
            system("CLS");
        }
    }

    return 0;
}


