#include <iostream>
#include <cmath> // for round
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

float calculate(float principal, float rate, float years){
    //get the rate back as a modifier
    float realRate = rate / 100;
    float total = principal * (1+ (realRate*years));
    //round it to nearest hundreth and return
    return  std::round(100 * total) / 100.0;

}

int main () {
    //grab the principal, rate, and years
    float principal = validateFloat("Enter the principal: ");
    float rate = validateFloat("Enter the rate of interest: ");
    float years = validateFloat("Enter the number of years: ");
    //output it out to user
    //round it to two for the answer

    std::cout << "After " << years << " years at " << rate << "%, the investment will be worth $"
     << calculate(principal, rate, years) << ".\n";     
    return 0;
}