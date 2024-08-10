#include <iostream>
#include <cmath>  // to round
#include <cctype> // to lower a char


int validateInt(std::string question){
    //set up the variables needed
    std::string userInput;
    int input;
    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << question;
        std::cin >> userInput;
        try {
            //try turning it into an int
            input = std::stoi(userInput);
            flag = true;
            return input;
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not an int!\n";
            //flag = false;
        }    
    }
}
char validateChar(std::string question){
   //set up the variables needed
    char userInput;
    int input;
    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << question;
        std::cin >> userInput;
        //lower it down so that either works
        userInput = std::tolower(userInput);
        //if its c or f we're good, else  keep on.
        if (userInput == 'c' || userInput == 'f'){
            flag = true;
        }
        else{
            std::cout << "Try again, only use c or f.\n";
        }
    }
    return userInput;
}

int calculate(char tempMeasure, int temp){
    int actualTemp;
    //if it's celsius, do celsius convert, otherwise fehrenheit
    if (tempMeasure == 'c'){
        actualTemp = std::round((temp - 32) * 5 / 9);
    }
    else{
        actualTemp = std::round((temp * 9 / 5) + 32);
    }
    return actualTemp;
}

int main () {
    //grab char
    char tempMeasure = validateChar("Press C to convert from Fahrenheit to Celsius.\nPress F to convert from Celsius to Fahrenheit.\nYour choice: ");
    std::string whichMeasure = (tempMeasure == 'c') ? "Please enter the temperature in fahrenheit: " : "Please enter the temperature in Celsius: ";
    //grab our ints needed
    int temp = validateInt(whichMeasure);
    int convertedTemp = calculate(tempMeasure,temp);
    //set up the results and output
    std::string result = (tempMeasure == 'c') ? "The temperature in Celsius is " : "The temperature in Fehrenheit is ";
    std::cout << result << convertedTemp << ".\n";

    return 0;
}