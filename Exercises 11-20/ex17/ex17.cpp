#include <iostream>
float validateFloat(std::string question){
    //set up the variables needed
    std::string userInput;
    float input;
    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << question;
        std::cin >> userInput;
        try {
            //try turning it into an int
            input = std::stof(userInput);
            flag = true;
            return input;
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not a float!\n";
            //flag = false;
        }    
    }
}
int validateInt(std::string question){
    //set up the variables needed
    std::string userInput;
    float input;
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

float calculateBAC(int sex, float alcoholinOunces, float weightinPounds, float hours){
    float ratio = (sex == 1) ? 0.73 : 0.66;
    float BAC = (alcoholinOunces * 5.14 / weightinPounds * ratio) - .015 * hours;
    return BAC;
}


int main () {
    // grab the neccesary amount of info needed from user
    int sex = validateInt("1 if male, 2 if female ");
    float alcoholinOunces = validateFloat(" How many ounces of alcohol did you have? ");
    float weightinPounds = validateFloat("What is your weight, in pounds? ");
    float hours = validateFloat(" How many hours has it been since your last drink? ");

    //calculate 
    float BAC = calculateBAC(sex,alcoholinOunces,weightinPounds,hours);

    //output
    std::string result = (BAC >= 0.08) ? "not legal" : "legal";
    std::cout << "Your BAC is " << BAC << "\n";
    std::cout << "It is " << result << " for you to drive.\n";
    return 0;
}