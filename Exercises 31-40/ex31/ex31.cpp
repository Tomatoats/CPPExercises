#include <iomanip> // for tabular filling
#include <cmath> // for rounding
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

int calculate(int restPulse, int age, float intensity){
    float pulses = (((220 - age) - restPulse) * (intensity)) + restPulse; 
    int roundPulse = std::round(pulses);
    return roundPulse;
}

int main () {
    int restPulse = validateInt("What is your resting heart rate? ");
    int age = validateInt("What is your age? ");

    int pulses[9];
    for (int i = 0; i < 9; i++){
        int intense = (i * 5 + 55);
        float intensity = static_cast <float>(  intense) / static_cast<float>(100);
        //std::cout << intensity << "and intense is" << intense << "\n";
        pulses[i] = calculate(restPulse,age,intensity);
    }

    //now to get this fucking right/


    std::cout <<"Intensity\t| Rate\t\n";
    std::cout << std::setfill('-') << std::setw(25) << "\n";
    for (int i = 0; i < 9; i++){
        std::cout << i*5 + 55 << "%\t\t| " << pulses[i] << " bpm\n";
    }
    return 0;

}
