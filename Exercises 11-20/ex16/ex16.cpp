#include <iostream>

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

int main () {
    //grab age
    int age = validateInt("What is your age? ");
    //use a ternary operator
    std::string result = (age >= 16) ? " " : " not ";

    std::cout << "You are" << result << "legally allowed to drive.";

}