#include <iostream>

int main () {
    // start up the strings
    std::string noun;
    std::string verb;
    std::string adjective;
    std::string adverb;

    //get user input
    std::cout << "Enter a noun: ";
    std::cin >> noun;
    std::cout << "Enter a verb: ";
    std::cin >> verb;
    std::cout << "Enter a adjective: ";
    std::cin >> adjective;
    std::cout << "Enter a adverb: ";
    std::cin >> adverb;

    // concat to a final input
    std::cout << "Do you " << verb << " your " << adjective << " " << noun << " " << adverb << "? That's hilarious!"; 

    //don't forget a return!
    return 0;


}