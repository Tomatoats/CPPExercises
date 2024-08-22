#include <iostream>
#include <algorithm> // for sorting


std::string grabString(std::string question){
    std::string input = "";
    std::cout << question;
    std::cin >> input;
    return input;
}

bool calculate (std::string stringOne, std::string stringTwo){
    // so we're gonna use sort to get these words sorted
    std::sort(stringOne.begin(),stringOne.end());
    std::sort(stringTwo.begin(), stringTwo.end());
    // we use begin and end as pointers that show the beginning and end of the string to iterate upon

    if (stringOne == stringTwo){
        return true;
    }
    else {
        return false;
    }
}



int main () {
    std::cout << "Enter two strings and I'll tell you if they are anagrams.\n";
    std::string stringOne = grabString("Enter the first string: ");
    std::string stringTwo = grabString("Enter the second string: ");

    std::string result = (calculate(stringOne,stringTwo) == true) ?  "are anagrams." : "are not anagrams.";

    std::cout << "\"" << stringOne << "\" and \"" << stringTwo << "\" " << result;
}