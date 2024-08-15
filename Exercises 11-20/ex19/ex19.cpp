#include <iostream>
#include <cmath> //for rounding

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

float calculate (int weightPounds, int heightInches){
    // do the formula for bmi
    //because we're using ints we need to cast to float for a sec for this diviision
    float bmi = std::round( static_cast< float> (weightPounds) / static_cast<float> ( (heightInches * heightInches)) * 703 * 100) / 100;
    
    return bmi;
}

int main () {
    //grab user's weight and height
    int weightPounds = validateInt("What's your weight (in pounds)? ");
    int heightInches = validateInt("What's your height (in inches)? ");
    //calculate
    float bmi = calculate(weightPounds,heightInches);


    // figure out which result to print out.
    std::string result;
    if (bmi < 18.5){
        result = "You are underweight. You should see a doctor.";
    }
    else if (bmi > 25){
        result = "You are overweight. You should see a doctor.";
    }
    else {
        result = "You are within the ideal weight range.";
    }
    //print!
    std::cout << "Your BMI is " << bmi << ".\n" << result;
    return 0;
}