#include <iostream>
#include <cmath> // for ceiling

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
            //flag = true;
            //return input;
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            //std::cout << "Not a float!\n";
            //flag = false;
        }
        if (input != 0){
            flag = true;
            return input;
        }
        else {
            std::cout << "Sorry. That's not a valid input.\n";
        }
    }
}

int main() {
    float rate = validateFloat("What is the rate of the return? ");

    int years = std::ceil(72 / rate);

    std::cout << "It will take " << years << " years to double your initial investment.\n";
    return 0;
}
    