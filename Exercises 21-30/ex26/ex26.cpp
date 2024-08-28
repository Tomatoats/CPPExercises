#include <iostream>
#include <cmath> // to raise by pow

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



class PaymentCalculator{
    public:
    int balance;
    float APR;
    int monthlyPayment;

    int calculateMonthsUntilPaidOff() {
        float top = 1;
        float bot = 30;// idk why but just doing -1/30 gives 0
        float partOne = -(top/bot);
        float partTwo = std::log(1+(balance/monthlyPayment) * (1-pow((1+(APR/36500)),30)));
        float partThree = std::log(1+(APR/36500));
        return std::ceil(partOne * partTwo / partThree);
    }
};

int main(){
    PaymentCalculator thisPayment;

    thisPayment.balance = validateInt("What is your balance? ");
    thisPayment.APR = validateFloat("What is the APR on the card (as a percent)? ");
    thisPayment.monthlyPayment = validateInt("What is the monthly payment you can make? ");

    std::cout << "It will take you " << thisPayment.calculateMonthsUntilPaidOff() << " months to pay off the credit card.";

    return 0;
}   