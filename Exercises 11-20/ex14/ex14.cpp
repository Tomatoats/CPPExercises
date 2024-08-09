#include <iostream>
#include <cmath> //to round

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

float calculate(float amount, std::string state){
    float fakeTax, total,tax = 0;
    if (state == "WI"){
        fakeTax = amount * 0.055;
        tax = std::round(100 * fakeTax) / 100.0;
        //std::cout  << "hey this is tax" << tax << "\n"; 
    }

    total = amount + tax;
    tax = std::round(100 * tax) / 100.0;
    //std::cout << "tax out here is" << tax << "\n";
    return tax, total;
}


int output(float amount, float tax, float total, std::string state){
    //std::cout << "tax in output: " << tax << "\n";

    if (state != "WI"){
        std::cout << "The total is: $" << total;
        return 0;
    }
    tax = std::round(100 * tax) / 100.0;
    std::cout << "The subtotal is: $" << amount 
    << "\nThe Tax is: $" << (total - amount) << "\nThe total is: $" 
    << total;
    return 0;





}
int main () {
    float amount = validateFloat("What is the order amount? ");
    //grab the state
    std::cout << "What state do you live in? ";
    std::string state;
    std::cin >> state;
    //calculate it all
    float tax, total =  calculate(amount, state);
    //output to console
    //std::cout << "tax out here is " << tax << "\n";
    output(amount,tax, total, state);
    return 0;
}
