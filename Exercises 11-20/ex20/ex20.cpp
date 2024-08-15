#include <iostream> 
#include <cmath> // for round
#include <algorithm> // for find

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

std::string getUserInput(std::string question){
    //grab user's input
    std::string input;
    std::cout << question;
    std::cin >> input;
    //getline(std::cin,input);
    return input;
}

std::string getUserInputBig(std::string question){
    //grab user's input
    std::string input;
    std::cout << question;
    //std::cin >> input;
    getline(std::cin,input);
    return input;
}


float figureOut(float amount, std::string state, std::string county){
    float tax,total= 0;
    std::string allowedState[8] =
    {"Wisconsin", "wisconsin", "WI","wi", "illinois","Illinois","IL","il"};
    std::string allowedCounty[5] = 
    {"Eau", "eau", "Dunn", "dunn"};
    bool wisconsin,illinois,eau,dunn = false;
    eau = false;
    dunn = false;
    illinois = false;
    wisconsin = false;
    //find if state has wisconsin or illinois
    
    for (int i = 0; i < sizeof(allowedState) / sizeof(std::string);i++){
        if (state == allowedState[i] && i < 4){
            wisconsin = true;
        }
        else if (state == allowedState[i] && i > 3){
            illinois = true;
        }
        else {
        }
    }
     // find if county has eau or dunn
    for (int i = 0; i < sizeof(allowedCounty) / sizeof(std::string);i++){
        if (county == allowedCounty[i] && i <= 1){
            eau = true;
        }
        else if (county == allowedCounty[i] && i >= 2){
            dunn = true;
        }
        else {
        }

    }
    if (wisconsin == true){
        if (eau == true){
            tax = amount * 0.055;
             total = tax + amount;
        }
        else if (dunn == true){
            tax = 0.054 * amount;
             total = tax + amount;
        }
        else {
            tax = amount * 0.05;
             total = tax + amount;
        }
    }

    else if (illinois == true) {
        tax = amount * 0.08;
        total = tax + amount;
    }

    else {
        tax = 0;
        total = amount;
    }


    return tax, total;
}


int main () {
    //grab user input for order amount, state and county
    float amount = validateFloat("What is the order amount? ");
    std::string state = getUserInput ("What state do you live in? ");
    std::string county = getUserInput("What county do you live in? ");

    //calculate tax and total
    float tax, total = figureOut(amount, state, county);
    tax = std::round(tax * 100)/100;
    //total = std::round(total * 100.0)/100.0;
    //print out
    std::cout << "The tax is $" << (total - amount) << ".\nThe Total is $" << total << ".\n";


    return 0;
}