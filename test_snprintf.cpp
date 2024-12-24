#include <iostream>
#include <iomanip>
#include <string>

void printInput(const std::string& input) {
    // Using std::setw without checking input length
    std::cout << "Formatted Input: " << std::setw(10) << input << std::endl;
}

int main() {
    std::string userInput;
    std::cout << "Enter a word: ";
    std::cin >> userInput;
    // This could cause data truncation if input is longer than 10 characters
    printInput(userInput);
    return 0;
}
