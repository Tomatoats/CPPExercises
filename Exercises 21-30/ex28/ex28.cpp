#include <iostream>

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


int main () {
    int toAdd = 0;
    //ask a number 5 times, add them up and you'll be okay
    for (int i = 0; i < 5; i++){
        toAdd += validateInt("Enter a number. ");
    }

    std::cout << "The total is " << toAdd << ".\n";
}
