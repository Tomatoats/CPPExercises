#include <iostream>
#include <iomanip>


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
            std::cout << input << "\n";
            return input;
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not a float!\n";
            //flag = false;
        }
        
    }
    
}
float calculate (float euros, float exchange){
    float amount = euros * exchange;
    return amount;
}

int main () {
    //grab euros, exchange
    float euros = validateFloat("How many Euros are you exchanging? ");
    float exchange = validateFloat("What is the Exchange rate? ");
    //calculate on its own function
    float amount = calculate(euros,exchange);
    //print out and used fixed / setprecision to make a set amount
    std::cout << euros << " euros at an exchange rate of " << exchange << " is \n"; 
    std::cout << std::fixed << std::setprecision(2) <<  amount << " U.S. dollars.\n";
    return 0;
}