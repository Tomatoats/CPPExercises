#include <iostream>
int validate(std::string question){
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
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not a int!\n";
            //flag = false;
        }
        
    }
    return input;
    
}

int main () {
  
    //convert to int!
    int people = validate("How many people? ");
    int pizza = validate("How many pizzas do you have ? ");
    int slices = validate("How many slices per pizza? ");

    //set up math!
    int totalSlice = pizza * slices;
    int slicePerPerson = totalSlice / people;
    int remaindingSlices = totalSlice % people;

    std::cout << people << " people with " << pizza << " pizzas ("<<totalSlice<< " slices)\n"
     << "Each person gets " << slicePerPerson << " pieces of pizza.\n" 
     << "There are " << remaindingSlices << " leftover pieces.";

}

