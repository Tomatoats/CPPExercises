#include <iostream>
int validate(std::string question){
    std::string userInput;
    int input;

    bool flag = false;
    while (flag == false){
        std::cout << question;
        std::cin >> userInput;
        try {
            input = std::stoi(userInput);
            flag = true;
        }
        catch(const std::invalid_argument& e){
            std::cout << "Not a int!\n";
            //flag = false;
        }
        
    }
    return input;
    
}

int main () {
    // Make the strings for our input
    //std::string userPeople;
    //std::string userPizza;
    //std::string userSlices;

    //get the user input via cout / cins
    /*
    std::cout << "How many people? ";
    std::cin >> userPeople;
    std::cout << "How many pizzas do you have? ";
    std::cin >> userPizza;
    std::cout << "How many slices per pizza? ";
    std::cin >> userSlices;
    */
    //convert to int!
    int people = validate("How many people? ");
    int pizza = validate("How many pizzas do you have ? ");
    int slices = validate("How many slices per pizza? ");
}

