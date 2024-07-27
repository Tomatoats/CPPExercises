#include <iostream>
#include <time.h>

int main() {
    //set up age
    std::string age;
    std::string ageRetire;
    //ask for age and retirement age
    std::cout << "What is your current age? ";
    std::cin >> age;
    std::cout << "At what age would you like to retire? ";
    std::cin >> ageRetire;

    //convert to int
    int userAge = std::stoi(age);
    int userRetirement = std::stoi(ageRetire);

    //grab current year
    //const auto now = std::chrono::system_clock::now();
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int year = aTime->tm_year + 1900;
    //stack overflow my beloved.

    //now we get what year the can retire
    int workingYears = userRetirement - userAge;
    int retirementYear = year + workingYears;

    // print!
    std::cout << "You have " << workingYears << " years left until you retire. \n";
    std::cout << "It's " << year << ", so you can retire in " << retirementYear << ".";
    return 0;

}