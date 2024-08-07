#include <iostream>
#include <cmath> // for rounding


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


float calculate(float principal, float rate, int years, int timesCompunded){
    //get the rate back as a modifier
    float realRate = rate / 100;
    float base = (1+ (realRate/timesCompunded));
    //now to get the base and exponent by the compound)
    float besidesPrincipal = pow(base, (timesCompunded*years));
    float total = principal *besidesPrincipal; 
    //round it to nearest hundreth and return
    return  std::round(100 * total) / 100.0;

}


int main (){
 //grab the principal, rate, years, and times compounded
    float principal = validateFloat("Enter the principal: ");
    float rate = validateFloat("Enter the rate of interest: ");
    int years = validateInt("Enter the number of years: ");
    int timesCompoundedPerYear = validateInt("Enter the numbr of times the interest is compounded per year: ");
    //now to calculate and output
    std::cout << "$" << principal << " invested at " << rate <<"% for " << years <<
    " years compounded " << timesCompoundedPerYear << " times per year is $" << calculate(principal,rate,years,timesCompoundedPerYear) << ".\n";


}