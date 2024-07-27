#include <iostream>

int main() {
    std::string userString;
    std::cout << "Give me a string and I'll count the characters!\n";
    getline(std::cin, userString); // So We're using proper names for things now
    //use get line OR ELSE it won't read past the first space
    std::cout << userString << " Has " << userString.length() << " characters.";

    return 0;
}
